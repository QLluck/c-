#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;    // 学生姓名
    string id;      // 学号
    float score;    // 数据结构课程成绩

public:
    // 构造函数
    Student() : score(0.0f) {}
    Student(const string& n, const string& i, float s)
        : name(n), id(i), score(s) {}

    // 获取和设置成员变量的方法
    void setName(const string& n) { name = n; }
    void setId(const string& i) { id = i; }
    void setScore(float s) { score = s; }

    string getName() const { return name; }
    string getId() const { return id; }
    float getScore() const { return score; }
};

#endif // STUDENT_H 