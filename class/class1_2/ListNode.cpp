#include "ListNode.h"
using namespace std ;
void listInit(List l,char arr[][MAX_NAME],int len)//初始化
{   srand(time(0));
     ListNode head = new Node ;
     head->next = NULL;
     l->head =head;
     l->tail= head;
     if(arr==NULL)return;
     int mp[MAX_NAME_LENTH];
     memset(mp,0,sizeof(mp));
     for(int i=1 ;i<=len;i++)
     {
         ListNode p= new Node;
         for(int i=0 ;i<MAX_ID ;i++)
         {
             p->id[i]=(char)(rand()%10 +'0') ; //转成ascll码;

         }
         p->id[MAX_ID]='\0';//结尾零
         
        
        int num = rand()%MAX_NAME_LENTH;
         while(mp[num])
           {   num = rand()%MAX_NAME_LENTH ;
           }
           mp[num]=1;
           strcpy(p->name,arr[num]);
           listAdd(l,p);
     }
     


}
void listDelete(List l)//链表的销毁
{
     ListNode p = l->head->next;
     ListNode head=l->head;
     while(head!=NULL)
     {
         delete head;
         head=p;
         if(p!=NULL)p=p->next;
     }
     delete l;


}
ListNode listFindId(List l ,char id[] )//链表的id查找,反回前一个节点
{
    ListNode p = l->head;
     while(p->next!=NULL&&strcmp(p->next->id,id)) p=p->next;
         return p;

}
ListNode listFindName(List l ,char name[] )//链表的name查找,返回回一个节点
{
    ListNode p = l->head;
     while(p->next!=NULL&&strcmp(p->next->name,name)) p=p->next;
         return p ;

}
void listDeleteNode(List l,ListNode p1)//删除p1->next;
{     
      ListNode p2=  p1->next;
      p1->next=p2->next;
      delete p2;
}
void listAdd(List l, ListNode p1, ListNode p2)//把p1插入到p2后 
{  if(p2==NULL)p2=l->tail;
     p1->next=p2->next;
     p2->next=p1;
}
void listPrint(List l)
{
     ListNode p = l->head->next;
     while(p!=NULL)
       { printf("%s %s\n",p->id,p->name);
         p=p->next;
       }

}
void listNodePrint(ListNode p)
{
     printf("%s %s\n",p->id,p->name);
}