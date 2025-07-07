#include <iostream>
#include <iomanip>
#include <sstream>
#include "Student.h"
#include "SortAlgorithms.h"
#include <windows.h>

using namespace std;

const int MAX_STUDENTS = 10000;  // 增加到5000个学生

// 将数字转换为字符串的辅助函数
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// 生成指定长度的数字字符串，不足前面补0
string formatNumber(int num, int width) {
    stringstream ss;
    ss << setw(width) << setfill('0') << num;
    return ss.str();
}

// 打印学生信息
void printStudents(const Student arr[], int n) {
    cout << setw(15) << "姓名" 
         << setw(15) << "学号" 
         << setw(10) << "成绩" << endl;
    cout << string(40, '-') << endl;
    
    // 如果数据量太大，只显示前10个和后10个
    if (n > 20) {
        // 显示前10个
        for (int i = 0; i < 10; i++) {
            cout << setw(15) << arr[i].getName()
                 << setw(15) << arr[i].getId()
                 << setw(10) << fixed << setprecision(1) 
                 << arr[i].getScore() << endl;
        }
        cout << string(40, '.') << " 省略" << n - 20 << "条记录 " << string(40, '.') << endl;
        // 显示后10个
        for (int i = n - 10; i < n; i++) {
            cout << setw(15) << arr[i].getName()
                 << setw(15) << arr[i].getId()
                 << setw(10) << fixed << setprecision(1) 
                 << arr[i].getScore() << endl;
        }
    } else {
        // 数据量小时全部显示
        for (int i = 0; i < n; i++) {
            cout << setw(15) << arr[i].getName()
                 << setw(15) << arr[i].getId()
                 << setw(10) << fixed << setprecision(1) 
                 << arr[i].getScore() << endl;
        }
    }
    cout << endl;
}

// 复制数组
void copyArray(Student dest[], const Student src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// 测试排序算法并计时
void testSortingAlgorithm(const Student students[], int n,
                         const string& algorithmName,
                         void (*sortFunc)(Student[], int, bool),
                         bool ascending) {
    Student testData[MAX_STUDENTS];
    copyArray(testData, students, n);
    
    cout << "\n测试 " << algorithmName << (ascending ? " (升序)" : " (降序)") << ":\n";
    cout << "排序前:\n";
    printStudents(testData, n);
    
    LARGE_INTEGER frequency;        // 计时器频率
    LARGE_INTEGER start;           // 开始时间
    LARGE_INTEGER end;             // 结束时间
    double elapsed;                // 耗时（毫秒）
    
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    
    sortFunc(testData, n, ascending);
    
    QueryPerformanceCounter(&end);
    elapsed = (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
    
    cout << "排序后:\n";
    printStudents(testData, n);
    
    cout << "排序用时: " << fixed << setprecision(3) << elapsed << " 毫秒\n";
}

int main() {
    SetConsoleOutputCP(65001);
    // 创建测试数据
    Student students[MAX_STUDENTS];
    const int studentCount = 8000;  // 使用8000个学生
    
    // 生成测试数据：一些有规律的数据和一些随机数据的混合
    for (int i = 0; i < studentCount; i++) {
        string name = "学生";
        name += intToString(i + 1);
        string id = "2023" + formatNumber(i + 1, 4);  // 生成类似2023001的学号
        
        // 生成成绩：混合一些特殊情况和随机情况
        float score;
      
            // 中间80%的学生随机成绩
            score =(float)(rand() % 101);  // 0-100之间的随机分数
        
        
        students[i] = Student(name, id, score);
    }

    cout << "原始学生数据:\n";
    printStudents(students, studentCount);

    // 测试三种排序算法（升序和降序）
    testSortingAlgorithm(students, studentCount, "折半插入排序", SortAlgorithms::binaryInsertionSort, true);
    testSortingAlgorithm(students, studentCount, "折半插入排序", SortAlgorithms::binaryInsertionSort, false);
    
    testSortingAlgorithm(students, studentCount, "快速排序", SortAlgorithms::quickSort, true);
    testSortingAlgorithm(students, studentCount, "快速排序", SortAlgorithms::quickSort, false);
    
    testSortingAlgorithm(students, studentCount, "简单选择排序", SortAlgorithms::selectionSort, true);
    testSortingAlgorithm(students, studentCount, "简单选择排序", SortAlgorithms::selectionSort, false);

    cout << "\n按任意键继续...";
    system("pause");
    return 0;
} 
