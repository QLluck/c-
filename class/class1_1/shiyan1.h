#ifndef LIST_LINK_H
#define LIST_LINK_H
#include<bits/stdc++.h>

using namespace std ;
typedef struct Node
{
    int xi ;
    int zhi ;
    struct Node*next;
}Node,*ListNode;
typedef struct LinkList
{
       Node *head ;
      

}*List;
List ListAdd(List l1,List l2);
void ListInit(List l, int arr[][2]=NULL, int len=0);
void deleteList(List l);
void inputArray(int arr[][2],int n);
void PrintList(List l);


#endif //LIST_LINK_H
