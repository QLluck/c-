#include "graph.h"
int me[MAX_SIZE + 1] = {0};//为了深度优先搜索而定义的记忆表
int me2[MAX_SIZE+1]={0};//记录点是否遍历过
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
//使用深度优先搜索
void dfs(int x,int index,GP* g,int sum)
{    if(index>=g->num)
     {
          for (int i = 1; i <= g->num-1;i++)
               printf("%d ", me[i]);
          printf("%d", x);
          printf(" lenth :%d", sum);
          printf("\n");
          return;
     }
     
     me[index] = x;
     me2[x] = 1;
     for (LN* p =g->h[x]->head  ; p !=NULL ;p=p->next)
     {
          if(me2[p->data])
               continue;
         // std::cout << p->data << '\n';
          dfs(p->data, index + 1,g,sum + p->w);
     }
     me[index] = 0;
     me2[x] = 0;
}
GP* prim(int s,GP*g)
{
     GP *g2 = new GP;
     g2->head = 1;
     g2->num = g->num;
     for (int i = 1; i <= g->num; i++)
          init_v(i, g2);
     //选择num-1个点加入点集合
     me[s] = 1;//初始点为s
     
     for (int i = 1; i <= g->num-1;i++)
          {    //遍历图g 选一个最短的点
               int mi = inf;
               int u = 0;
               int v = 0;
               for (int j = 1; j <= g->num;j++)
               {
                     if(me[j])
                     {
                          for (LN *p = g->h[j]->head->next; p != NULL;p=p->next)
                          {   if(me[p->data])
                                    continue;
                              if (p->w <mi)
                              {
                                   mi = p->w;
                                   v = p->data;
                                   u = j;
                              }
                          }
                     }
               }
               //选完之后，加入点集
               me[v] = 1;
               add_e(u, v, mi, g2);
               printf("%d %d %d\n", u, v, mi);
          }
          for (int i = 1; i <= g2->num;i++)
               me[i] = 0;
          return g2;
}
