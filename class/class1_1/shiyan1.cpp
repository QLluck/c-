#include "shiyan1.h"
using namespace std;

List ListAdd(List l1, List l2)
{
    ListNode p1 = l1->head->next;
    ListNode p2 = l2->head->next;
    List l3 = new LinkList;
    ListNode head = new Node;
   
    head->next = NULL;
    l3->head = head;
    while(p1!=NULL&&p2!=NULL)
    {
        ListNode p = new Node ;
        if(p1->zhi==p2->zhi)
        {
            p->xi = p1->xi+p2->xi;
            p->zhi =p1->zhi;
            //添加链表
            head->next=p;
            head=p;
            head->next=NULL;
            p1=p1->next;
            p2=p2->next;

        }
        else if(p1->zhi>p2->zhi)
        {
             p->xi =p1->xi ;
             p->zhi =p1->zhi;
             head->next=p;
             head=p;
             head->next=NULL;
             p1=p1->next;

        }
        else if(p1->zhi<p2->zhi)
        {
            p->xi =p2->xi ;
            p->zhi =p2->zhi;
            head->next=p;
            head=p;
            head->next=NULL;
            p2=p2->next;
        }
        
         
    }


   
    while( p1!=NULL)     //当两个多项式长度不一样时
    {
      ListNode p = new Node ;
      p->xi = p1->xi;
      p->zhi =p1->zhi;
      head->next=p;
      head=p;
      head->next=NULL;
      p1=p1->next;  // 修正：应该是p1前进，而不是p2
  
    }
      while( p2!=NULL)     
    {
      ListNode p = new Node ;
      p->xi = p2->xi;
      p->zhi =p2->zhi;
      head->next=p;
      head=p;
      head->next=NULL;
      p2=p2->next;
  
    }
  
    

    
    
    return l3;
}

void PrintList(List l)
{
    ListNode p = l->head->next;
    while(p != NULL)
    {
        if(p->next == NULL)
        {
            printf("%dx^%d", p->xi, p->zhi);
            break;
        }
        printf("%dx^%d+", p->xi, p->zhi);
        p = p->next;
    }
    printf("\n");
}

void ListInit(List l, int arr[][2], int len)
{   
    ListNode head = new Node;
    head->next = NULL;
    l->head = head;
    
    if(arr==NULL or len==0) return;
    
    for(int i = 1; i <= len; i++)
    {
        ListNode p = new Node;
        p->xi = arr[i][0];
        p->zhi = arr[i][1];
        head->next = p;
        head = p;
        head->next = NULL;
    }
}

void deleteList(List l)
{
    ListNode p = l->head->next;
    ListNode head = l->head;
    
    while(head != NULL)
    {
        delete head;
        head = p;
        if(p != NULL)
            p = p->next;
    }
    delete l ;
}
bool cmp(int a,int b)
{
     return a>b;
}
void inputArray(int arr[][2], int n)
{
    srand(time(0));
    int xi[1000];
    int zhi[1000];
    
    for(int i = 1; i <= n; i++)
    {
        xi[i] = rand() % 100 + 1;
        zhi[i] = rand() % 100 + 1;
    }
    
    sort(zhi + 1, zhi + n + 1,cmp);
    sort(xi + 1, xi + n + 1,cmp);
    
    for(int i = 1; i <= n; i++)
    {
        arr[i][0] = xi[i];
        arr[i][1] = zhi[i];
    }
}
