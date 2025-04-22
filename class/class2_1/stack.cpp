#include"stack.h"
template <typename T>
stack::Stack<T>::Stack(int num) : head(-1), n(num) 
{
    data = (T*)malloc(n * sizeof(T));
    
}

template <typename T>
stack::Stack<T>::~Stack()
 {
    free(data);
}

template <typename T>
void stack::Stack<T>::push(T value) 
{
    if (head >= n - 1) 
    {
        expand();
    }
    data[++head] = value;
}

template <typename T>
void stack::Stack<T>::pop() 
{
    if (empty())
     {
        std::cout << "栈为空" << std::endl;
        return ;
    }
    head--;
}

template <typename T>
T stack::Stack<T>::top()  
{
    if (empty()) 
    {
        std::cout<< "栈为空" << std::endl;
        return 0 ;
    }
    return data[head];
}

template <typename T>
bool stack::Stack<T>::empty() 
 {
    return head == -1;
}

template <typename T>
int stack::Stack<T>::size()  
{
    return head + 1;
}

template <typename T>
int stack::Stack<T>::getCapacity() 
{
    return n;
}
template <typename T>
void stack::Stack<T>::expand()
{
    n *= 2;
    T* newData = (T*)realloc(data, n * sizeof(T));
    if (!newData) {
        std::cout << "内存分配失败！" << std::endl;
       return;
    }
    data = newData;
} 
template class stack:: Stack<int>;
template class stack:: Stack<double>;
template class stack::Stack<char>;
