#ifndef STACK_H
#define STACK_H

#include<bits/stdc++.h>
namespace stack
{
template <typename T>
class Stack {
private:
    T* data;       // 指向栈中元素的指针
    int head ;       // 栈顶指针
    int n ;  // 栈的容量

    // 动态扩容
    void expand();

public:
    // 构造函数
    Stack(int num= 10);

    // 析构函数
    ~Stack();

    // 入栈
    void push( T value);

    // 出栈
    void pop();

    // 获取栈顶元素
    T top() ;

    // 判断栈是否为空
    bool empty() ;

    // 获取栈的大小
    int size();

    // 获取栈的容量
    int getCapacity() ;
};
}

// 实现部分

#endif // STACK_H