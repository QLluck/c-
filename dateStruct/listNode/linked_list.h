#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义链表结构
typedef struct LinkedList {
    Node* head;
} LinkedList;

// 创建链表
LinkedList* create_linked_list();

// 销毁链表并释放内存
void destroy_linked_list(LinkedList* list);

// 在链表头部插入元素
void insert_at_head(LinkedList* list, int value);

// 在链表尾部插入元素
void insert_at_tail(LinkedList* list, int value);

// 在指定位置插入元素
void insert_at_position(LinkedList* list, int value, int position);

// 删除指定位置的元素
void delete_at_position(LinkedList* list, int position);

// 查找元素，返回其位置（从0开始计数），若不存在返回-1
int find_element(LinkedList* list, int value);

// 获取指定位置的元素值
int get_element_at_position(LinkedList* list, int position);

// 打印链表
void print_linked_list(LinkedList* list);

#endif // LINKED_LIST_H