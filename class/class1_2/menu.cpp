#include "menu.h"
#include "ListNode.h"
using namespace std; 

void menuPrint(List l)
{  printf("欢迎使用图书管理系统\n");
   ListNode p = NULL;
   while(1)
   { char c[10000];
     printf("0退出菜单\n");
     printf("1书籍展示\n");
     printf("2书籍查询\n");
     printf("3书籍删除\n");
     printf("4添加书籍\n");
     cin>>c;
     if(strcmp(c,"0")==0)
     { printf("欢迎您的再次使用\n");
      return ;
     }
     else if(strcmp(c,"1")==0)
     {
       listPrint(l);
     }
     else if(strcmp(c,"2")==0)
     {
        p =bookFind(l);
       if(p->next!=NULL) listNodePrint(p->next);
     }
     else if(strcmp(c,"3")==0)
     {
      bookDelete( l);
     }
     else if(strcmp(c,"4")==0)
     {
      bookAdd(l );
     }
     else 
     {
       printf("无效输入\n");
       
     }





     
   }

}
ListNode bookFind(List l)
{   char c[100] ;
    ListNode p =NULL;
     printf("1 id查询\n");
     printf("2 名字查询\n");
     cin>>c;
     if(strcmp(c,"1")==0)
     {  char id[MAX_NAME];
         printf("请输入id");
         cin>>id;
          p= listFindId(l,id);
         if(p->next)
           {  printf("查询成功\n");
           // listNodePrint(p->next);
          
           }
         else printf("未找到该id\n");
         return p ;
     }
     else if(strcmp(c,"2")==0)
     {  char name[MAX_NAME];
         printf("请输入name");
         cin>>name;
         p = listFindName(l,name);
         if(p->next)
           {  printf("查询成功\n");
           //listNodePrint(p->next);
           }
         else printf("未找到该name\n");
         return p ;

     }
     else 
     {
         printf("无效输入\n");
         return NULL ; 
     }
     return p ;
     

}
void bookDelete(List l)
{
     ListNode p = bookFind(l);
     if(p->next==NULL) 
      {     printf("删除失败\n"); //失败
        return;
      }
   listDeleteNode(l,p);
   printf("删除成功\n");
   return;
}
void bookAdd(List l )
{ char id[MAX_NAME];
  char name[MAX_NAME];
  ListNode p ;
    printf("请输入id\n");
    cin>>id; 
   p= listFindId(l,id);
    if(p->next)
    {
       printf("存在重复id\n");
       printf("该书为\n");
       listNodePrint(p->next);
       printf("添加失败\n");
       return;
   
    }

    printf("请输入书名\n");
    cin>>name;
   
  
    p=listFindName(l,name);
    if(p->next)
    {
      printf("存在重复name\n");
      printf("该书为\n");
      listNodePrint(p->next);
      printf("添加失败\n");
      return;
     

    }
    p = new Node;
    strcpy(p->id,id);
    strcpy(p->name,name);
    listAdd(l,p);
    printf("添加成功");
    
}