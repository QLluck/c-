#ifndef LIST_NODE
#define LIST_NODE
#define MAX_ID 20
#define MAX_NAME 50
#define MAX_NAME_LENTH 11
#include<bits/stdc++.h>
typedef struct Node
{
    char id[MAX_ID+1];
    char name[MAX_NAME];
    struct Node * next ;
}Node,*ListNode;
typedef struct LinkList
{
    ListNode head;
    ListNode tail;
}*List;
void listAdd(List l, ListNode p1, ListNode p2= NULL);//尾插入把p1插入到p2后 
void listPrint(List l);
void listNodePrint(ListNode p);
void listDeleteNode(List l,ListNode p1);//删除p2 p1为p2的前驱 p1默认为head
ListNode listFindName(List l ,char name[] );//链表的name查找,返回回一个节点
ListNode listFindId(List l ,char id[] );//链表的id查找,反回前一个节点
void listDelete(List l);//链表的销毁
void listInit(List l,char arr[][MAX_NAME],int len);//初始化


#endif //LIST_NODE