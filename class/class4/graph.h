#ifndef GRAPH
#include<bits/stdc++.h>
#define MAX_SIZE 100
const int inf = 1e9+7;
typedef struct ListNode
{
    int data;//点
    int w;//两点间距离
    ListNode*next;
}LN;
typedef struct list
{  
   
    LN*head;
    LN*tail;
}L;

typedef struct Graph
{
    L* h[MAX_SIZE];
    int head;
}GP;




#endif //GRAPH