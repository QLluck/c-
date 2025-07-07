#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  // 添加Windows API支持
#include "phonebook.h"

// 测试数据
const char* test_names[] = {
    "Zhang San", "Li Si", "Wang Wu", "Zhao Liu", "Sun Qi", 
    "Zhou Ba", "Wu Jiu", "Zheng Shi", "Chen Yi", "Yang Er",
    "Xu San", "Feng Si", "Hu Wu", "Pan Liu", "He Qi",
    "Guo Ba", "Luo Jiu", "Tang Shi", "Bai Yi", "Shi Er",
    "Deng San", "Xiao Si", "Cao Wu", "Wei Liu", "Yuan Qi",
    "Dong Ba", "Fu Jiu", "Mao Shi", "Lu Yi", "Long Er"
};

const char* test_ids[] = {
    "2023001", "2023002", "2023003", "2023004", "2023005",
    "2023006", "2023007", "2023008", "2023009", "2023010",
    "2023011", "2023012", "2023013", "2023014", "2023015",
    "2023016", "2023017", "2023018", "2023019", "2023020",
    "2023021", "2023022", "2023023", "2023024", "2023025",
    "2023026", "2023027", "2023028", "2023029", "2023030"
};

const char* test_phones[] = {
    "13800000001", "13800000002", "13800000003", "13800000004", "13800000005",
    "13800000006", "13800000007", "13800000008", "13800000009", "13800000010",
    "13800000011", "13800000012", "13800000013", "13800000014", "13800000015",
    "13800000016", "13800000017", "13800000018", "13800000019", "13800000020",
    "13800000021", "13800000022", "13800000023", "13800000024", "13800000025",
    "13800000026", "13800000027", "13800000028", "13800000029", "13800000030"
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseAndClear() {
    printf("\nPress Enter to continue...");
    clearInputBuffer();
    clearScreen();
}

int main() {
    // 设置控制台代码页为UTF-8
    SetConsoleOutputCP(65001);
    
    // 创建哈希表
    HashTable* phonebook = createHashTable(TABLE_SIZE);
    if (!phonebook) {
        printf("创建通讯录失败！\n");
        return 1;
    }

    // 插入测试数据
    printf("正在初始化通讯录...\n");
    for (int i = 0; i < 30; i++) {
        if (!insert(phonebook, test_names[i], test_ids[i], test_phones[i])) {
            printf("插入数据失败：%s\n", test_names[i]);
        }
    }
    printf("初始化完成！\n\n");
    pauseAndClear();

    int choice;
    char name[MAX_NAME];
    char id[MAX_ID];
    char phone[MAX_PHONE];

    while (1) {
        printf("\n通讯录管理系统\n");
        printf("1. 显示所有联系人\n");
        printf("2. 查找联系人\n");
        printf("3. 添加联系人\n");
        printf("4. 计算平均查找长度\n");
        printf("5. 退出\n");
        printf("请选择操作 (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("输入无效，请重试\n");
            clearInputBuffer();
            pauseAndClear();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                clearScreen();
                displayTable(phonebook);
                pauseAndClear();
                break;

            case 2: {
                clearScreen();
                printf("请输入要查找的姓名: ");
                if (fgets(name, MAX_NAME, stdin)) {
                    name[strcspn(name, "\n")] = 0;  // 删除换行符
                    int comparisons = 0;
                    Student* found = search(phonebook, name, &comparisons);
                    
                    if (found) {
                        printf("\n找到联系人：\n");
                        printf("姓名: %s\n", found->name);
                        printf("学号: %s\n", found->id);
                        printf("电话: %s\n", found->phone);
                        printf("查找比较次数: %d\n", comparisons);
                    } else {
                        printf("未找到联系人：%s\n", name);
                    }
                }
                pauseAndClear();
                break;
            }

            case 3:
                clearScreen();
                printf("请输入姓名: ");
                if (fgets(name, MAX_NAME, stdin)) {
                    name[strcspn(name, "\n")] = 0;
                    
                    printf("请输入学号: ");
                    if (fgets(id, MAX_ID, stdin)) {
                        id[strcspn(id, "\n")] = 0;
                        
                        printf("请输入电话: ");
                        if (fgets(phone, MAX_PHONE, stdin)) {
                            phone[strcspn(phone, "\n")] = 0;
                            
                            if (insert(phonebook, name, id, phone)) {
                                printf("添加成功！\n");
                            } else {
                                printf("添加失败，通讯录可能已满！\n");
                            }
                        }
                    }
                }
                pauseAndClear();
                break;

            case 4: {
                clearScreen();
                float avg = calculateAverageSearchLength(phonebook);
                printf("平均查找长度: %.2f\n", avg);
                pauseAndClear();
                break;
            }

            case 5:
                clearScreen();
                printf("感谢使用！再见！\n");
                destroyHashTable(phonebook);
                return 0;

            default:
                printf("无效的选择，请重试\n");
                pauseAndClear();
        }
    }

    return 0;
} 