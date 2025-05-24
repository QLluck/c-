#include "graph.h"

void init_v(int v,GP* G)
{
    L*temp =new L ;
   LN* head=new LN;
    head->next=NULL;
    temp->head=head;
    temp->tail=head;
    head->data=v;
    G->h[v]=temp;
}
void insert(L*l,int v,int w)
{
     LN*temp = new LN;
     temp->next=NULL;
     temp->data=v;
     temp->w=w;
     l->tail ->next =temp;
     l->tail = temp;

}
void add_e(int u,int v,int w,GP*G)//添加u到v 权值为w
{
     insert(G->h[u],v,w);

}



