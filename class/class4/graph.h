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
    L* h[MAX_SIZE+1];
    int head;
    int num;
}GP;
void init_v(int v, GP *G);
void insert(L *l, int v, int w);
void add_e(int u, int v, int w, GP *G);
void dfs(int x, int index, GP *g,int sum);
GP *prim(int s, GP *g);
#endif //GRAPH