#include<stdio.h>
#include<stdlib.h>
//双链表

typedef struct DNode
{
     int date ;
     struct DNode * prior,*next ;
}DNode ,* DLinkList ;
bool InitDLinkList(DLinkList&L)
{
     L=(DNode*)malloc(sizeof(DNode)) ;
     if(L==NULL) return false ;
     L->next =NULL ;
     L->prior=NULL ;
     return true ;
}
//在 p节点的后面插入s 节点
bool InsertNextDNode(DNode*p, DNode*s )
{
      if(p==NULL||s==NULL)return false ;
     s->next = p ->next ;
     if(p->next!=NULL) p->next ->prior = s ;
     p ->next = s ;
     s->prior = p ;
     return true ;
      
}
//删除p节点的后继节点 
bool DelteNextDNode(DNode*p)
{
     if(p==NULL) return false ;
     DNode * q = p->next ;
     if(q==NULL) return false ;
     p->next = q->next ;
     if(q->next!=NULL) q->next ->prior = p ;
      free(q) ;
      return true ;


}
int main()
{
  DLinkList L ;
  InitDLinkList(L) ;
}