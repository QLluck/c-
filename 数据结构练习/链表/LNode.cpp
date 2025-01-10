#include<stdio.h>
#include<stdlib.h>
typedef struct LNode 
{
     int date;
    struct LNode * next ;
     
}LNode , *LinkList;
//初始化
bool InitList(LinkList &L)
{  
     L=NULL ;
     return true ;
     //有头单链表
     L=(LNode *) malloc(sizeof(LNode)) ;
}
bool Empty(LinkList L)
{
     //不带头单链表
     if(L==NULL) return true ;
     else return false ;
     //不带头单链表判断
    return (L==NULL) ;
    //带头单链表
    if(L->next == NULL) return true ;
    else return false ;
}
//插入
bool ListInsert(LinkList L , int i ,int e )
{
      if(i<1) return false ;
      int j = 0 ;
      LNode * p ;
      p = L ;
      while(p!=NULL&&j<i-1)
      {
        p = p->next ;
        j++ ;
      }
    //   if(p==NULL) return false ;
    //   LNode*s = (LNode*)malloc(sizeof(LNode)) ;
    //   s->date =e ;
    //   s->next  = p ->next ;
    //   p->next = s ;
    //   return true ;
    return InsertNextNode(p,e) ;
}
bool InsertNextNode(LNode*p,int e)
{
       if(p==NULL)return false ;
       
     LNode * s =(LNode*)malloc(sizeof(LNode)) ;
     if(s==NULL) return false ;
     s->next = p ->next ;
     s->date = e ;
     p->next = s ;
}
bool InsertPriorNode(LNode *p,int e)
{//偷天换日  
    if(p=NULL)return false ;
    LNode * s = (LNode*)malloc(sizeof(LNode)) ;
    if(s==NULL) return true ;
    s->next = p->next ;
    s->date = p->date ;
    p->next = s ;
   p->date = e ;
   return true ;
}
//指定节点删除
bool DeleteNode(LNode *p )
{//偷天换日
      if(p==NULL) return false ;
      LNode  *q = p->next ;//有Bug 当p->next =NULL  只能从头开始找
      p ->date = q->date ;
      p->next = q->next ;
      free(q) ;
      return ;

}
int main()
{
 LinkList L ;
 InitList(L) ;

}