//注释  被//标记的代码为废案
//一定要按程序退出 



//头文件标记处------------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//------------------------
//宏定义处 
//string lne 字符串长度
#define STRINGLEN 100
//类定义处-------------------
// struct student
// {  //用于标记是否为学生账号
//    int login;
//    //用户名
//    char userName[100] ;
//    //密码
//    char code[100] ;
//    char name[100] ;

   


// };
// struct teacher
// { 
//    int login;
//    //用户名
//    char userName[100] ;
//    //密码
//    char code[100] ;
//    char name[100] ;

//    teacher() : login(0) {} // Constructor to initialize login
// };
struct Date
{
      int login;
   //用户名
   char userName[STRINGLEN] = "" ;
   //密码
   char code[STRINGLEN]="" ;
   char name[STRINGLEN] ="";


};
// struct op
// {
//     int login ;

// };
struct accout
{     
      // student student ;
      // teacher teacher ;
      //  op op ;
       //实现链表
       //date数据
       Date date ;
       accout * next ;


};
//---------------------
//函数声明处-------------------------
void menuLogin();
void loginChoose() ;
int checkFileEmpty() ;
void TimeOut();
struct accout* login();
void Recover() ;
void Inital() ;
int RepeatUsername(char userName[] );
void ListAccoutAdd(accout  TempAdd) ;
void Register();
struct accout*ListBack(struct accout*p1 );
//-------------------------
//全局变量定义处---------------------
accout *head,*p,*tail ;



//-------------------------
//函数定义处---------------------------
//链表功能及操作函数
//通过用户名来查找p指针 返回
struct accout* FoundList()
{
    //
    printf("请输入用户名\n");
    char str[STRINGLEN] ;
    scanf("%s",str) ;
    p =head->next ;
    
     while(p!=NULL)
     {
        if(strcmp(p->date.userName,str)==0)
        {
           return p ;

        }
       
        p=p->next ;
     }
     printf("未找到用户名请判断您所输入的用户名是否正确!\n") ;
     return NULL ;
}
//链表长度 返回链表数据个数
int ListLen()
{
  p = head->next ;
  int sum = 0 ;
  if(p!=NULL)
  {
    p=p->next ;
    sum++ ;
  }
  return sum ;
}
//链表删除 成功返回上一个指针
 struct accout * ListDelte()
{     struct accout*p1 ;

     if(! (p1= FoundList() ))//通过名字查找
     {
        return NULL ;//查找失败
     }
     p1 = ListBack(p1) ;
     struct accout *temp = p1->next ;
     p1->next = temp->next ;
     free(temp) ;
     printf("删除成功!\n") ;
     return p ;
     
}
//删除重载版
 struct accout * ListDelte(struct accout*p1)
{      
     
     p1 = ListBack(p1) ;
     struct accout *temp = p1->next ;
     p1->next = temp->next ;
     free(temp) ;
     printf("删除成功!\n") ;
     return p ;
     
}


//实现链表的上一个位
struct accout*ListBack(struct accout*p1 )
{
     if(p1 ==head) return NULL ;
     p = head ;
     while(p->next!=p1)p=p->next ;
     return p ;
}

//交换相邻两个链表数据 //注意不能为//失败返回 0;
int SwapList(struct accout *p1 ,struct accout*p2 )
{
     //锁头锁尾
     if(p1==head||p1==NULL||p2==head||p2==NULL)return 0 ;
     if( !(p1=ListBack(p1))) return 0 ;
     if( p2->next==NULL ) 
     { p2 = ListBack(p2) ;
       p2->next = p1->next ;
       p1->next->next = NULL ;
       tail = p1->next ;
       p1->next = p2; 
       return 1 ;
     } 
     p1->next->next = p2->next ;
     p2 ->next = p1->next ;
     p1->next = p2 ;
     return 1; 
}
//

//高级链表文件读入
void FileListRead(struct accout * temp , FILE*fp)
{

}
//链表修改
int ChangeList()
{
     if( !FoundList()) return 0 ;
     
}
int ChangeList(struct accout*p1)
{
      if(CodeList(p1))
      {
       while(1)
       {
         printf("请输入要更改的内容 1为账号名 2为密码 3为真实姓名 4返回\n") ;
         int a ;
         scanf("%d",&a) ;
         switch(a)
         {
              case 1 : 
              char username[STRINGLEN] ;
              scanf("%s",username) ;
              strcpy(p1->date.userName,username) ;
              printf("修改成功\n") ;
             PrintList(p1) ;
              break ;
              case 2 :
              char code[STRINGLEN] ;
                  scanf("%s",code) ;
              strcpy(p1->date.userName,code) ;
              printf("修改成功\n") ;
                  PrintList(p1) ;
              break ;
              case 3:
              char code[STRINGLEN] ;
                  scanf("%s",code) ;
              strcpy(p1->date.userName,code) ;
              printf("修改成功\n") ;
                  PrintList(p1) ;

              case 4:
              printf("正在返回......\n");
              printf("按任意键继续\n") ;
              TimeOut() ;
              return 0  ;
              break ;


         }     
       } 
      }
      else 
      {
         printf("正在返回.....\n") ;
         printf("按任意键继续\n") ;
         TimeOut() ;
       }
}
//链表密码判定
int CodeList(struct accout*p1)
{
    int times = 3 ;
    char code[STRINGLEN];
                while(times--)
               {
                  printf("请输入密码:") ;
   
                               
                  scanf("%s",code) ;
                   if(strcmp(code,p1->date.code))
                   {
                       printf("密码错误\n还剩%d次机会\n",times) ;
                       
                    

                   }
                   else
                   {
                    return 1 ;
                   }

               }
                 printf("输入三次密码错误,请重新尝试\n") ;
                    return 0 ;
}
//链表展示
void PrintList(struct accout*p1)
{
     printf("账号login:%d 用户名:%s真是姓名:%s\n",p1->date.login,p1->date.userName,p1->date.name) ;
}
void PrintList()
{   p = head->next ;
    while(p!=NULL)
    {
     printf("账号login:%d 用户名:%s 真是姓名:%s\n",p->date.login,p->date.userName,p->date.name) ;
   p = p->next ;
    }
} 


//第一部分登录与初始化函数-------------------
//实现按任意键退出
void TimeOut()
{
      while(   ( getchar())!='\n') ;
      getchar() ;
      return  ;
}
//登录界面图
void menuLogin()
{ 
     //显示登录主菜单
    
     printf("\n\n");
      printf("--------------欢迎来到学生信息管理系统------------\n");
      printf("--------------------------------------------------\n");
      printf("------------------按1登录账号---------------------\n");
      printf("------------------------------------------------\n");
      printf("------------------按3注册账号---------------------\n");
      printf("------------------按0退出系统-----------------------\n");
      printf("--------------------------------------------------\n");
      printf("\n\n") ;
     
      
}
//登录界面选项
void loginChoose()
{  while(1)
{
      menuLogin();

      int a = -1 ;
     // while((getchar())!='\n') ;
     // a = getchar() ;
loginChooseCina :
      scanf("%d",&a) ;
      switch (a)
       {

      
        case  1 :
    struct accout *p1 = head ;
      if(  p1=login() ) 
      {
       int  login = p1->date.login ;
      switch(login)
      {
         case 1 :
   //学生界面
       if(studentMenuChoose(p1) )
       {
          return ; 
       }
       else 
       {
            printf("感谢您的再次使用\n") ;
           printf("按任意键退出\n") ;

        TimeOut() ;
          return ;
       }
     
          break ;
                    
        case  2 :
          //教师界面函数调用    
           break ;

      }
      }
    
      break ;
          
       
        
          
           //printf("按任意键继续\n") ;
           //TimeOut();
           
 
        case  3 :
           Register();
          printf("注册成功\n") ;
           printf("按任意键继续\n") ;
           TimeOut() ;
           break ;
        case 0 :
          
           printf("感谢您的再次使用\n") ;
           printf("按任意键退出\n") ;

        TimeOut() ;


           return ;
           break ;
           
        default:
        printf("请您输入正常的选项\n") ;
        goto loginChooseCina ;


       }

}
}
//登录功能
//原理通过用户名来检查链表数据 如果对的话 p指向账号
struct accout* login()
{    //检测第一次
  //    FILE*fp =fopen("//Users//jack5//c语言项目//学生信息管理系统//accout","r") ;
  //    if(fp==NULL)
  //    {
  //       printf("打开文件失败\n请联系管理员\n" ) ;
  //         fclose(fp) ;
  //       return 0 ;
  //    }
  //    if(checkFileEmpty())
  //    {
  //       printf("检测到并没有任何用户数据\n请注册账号\n");
  //       fclose(fp) ;
  //       return 0;
  //    }
  //  fclose(fp) ;
     p=head->next ;
     char str[STRINGLEN] ;
     char userName[STRINGLEN] ;
     char code[STRINGLEN] ;
    
         printf("请输入用户名:") ;

         scanf("%s",userName) ;
         while(p!=NULL) 
         {
             
             if(!strcmp(userName,p->date.userName ))
          {
              if(CodeList(p)) return p ;
              else return NULL ;
          }
             else
             {
               printf("正在检测用户数据......\n") ;
             } 
             p = p->next ;

         } 
          printf("未检测到用户名\n请确认该用户是否存在\n") ;
          printf("按任意键返登录界面\n\n") ;

          TimeOut() ;
          return NULL ;
         
         


     
     
    return 0 ;


    
     
      




    
}
//检测文件是否存在 或为空
int checkFileEmpty()
{
   FILE *fp = fopen("//Users//jack5//c语言项目//学生信息管理系统//accout", "r");
    if (fp == NULL) 
    {
        printf("读取文件失败\n") ;
       printf("请联系管理员\n") ;
        return 0 ;
        
       
    }


    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    if (size == 0) {
         return 1 ;
    } else {
        return 0 ;
    }
    fclose(fp);
}
//注册功能
void Register()
{

   //移动链表指针p 到尾部
  //p =tail ;
   //新建结构体
   accout temp ;
  
   //两个功能，注册学生账号，和教师账号
   printf("注册账号请按1,师生账号请按2,退出请按0\n") ;
    int a ;
RegisterCina: 
    scanf("%d",&a) ;

   switch (a) 
   {
         case 1 :
       
          temp.date.login = 1 ;

          break ;
          case 2 :
          temp.date.login=2 ;
          break ;

          case 0 :
          printf("正在返回主界面\n\n") ;

          return ;
          break ;

          default:
          printf("请重新输入正确选项\n") ;
          goto RegisterCina ;
          break ;



   }
   

  printf("请输入账号名\n") ;
registerStudentUsername: 
         scanf("%s",temp.date.userName) ;
         //检测数据库中是否含有该账号
          if( RepeatUsername(temp.date.userName ))
          {
             printf("已有该用户存在，请重新输入用户名\n") ;
             goto registerStudentUsername ;

          }

          printf("请输入密码\n") ;
          scanf("%s",temp.date.code) ;

   
   
//添加到链表
    ListAccoutAdd(temp) ;
    printf("正在添加账号到链表中.....\n") ;
    // printf("添加成功\n") ;
    // printf("请到主界面登录\n") ;

   printf("\n\n") ;
   return ; 
  

    

}
//初始化程序 读取文件和 初始化链表
void Inital()
{   printf("正在给链表分配内存......\n") ;
     p = (accout*)malloc(sizeof(accout)) ;
     p->next = NULL ;
     head = p ;
     tail = p ;
     FILE *fp = fopen("accout.txt","r") ;
     if(fp==NULL)
     { fclose(fp) ;
      printf("正在配置文件夹\n") ;
      FILE *fp = fopen("accout.txt","w") ;
       fclose(fp) ;
       printf("配置成功!\n");
       printf("由于您是第一次登录,请先注册一个账号\n") ;
       Register() ; 
      return ;
     }
      

     char line[1000] ;
     while( fgets(line, sizeof(line), fp) != NULL )
     {    char *tok= strtok(line," ") ;
         accout* temp = (accout*)malloc(sizeof(accout)) ;

        sscanf(tok,"%d",&temp->date.login ) ;
        tok = strtok(NULL," ") ;

        sscanf(tok,"%s",temp->date.userName ) ;
        tok=strtok(NULL," ") ;
        sscanf(tok,"%s",temp->date.code) ;
        tok=strtok(NULL," ") ;
        sscanf(tok,"%s",temp->date.name) ;
        tok=strtok(NULL," ") ;


        while(tok!=NULL)
        {
              //待添加数据
        }

              tail->next = temp ;
              tail = temp ;
              tail->next = NULL ;
              printf("正在初始化链表.....\n") ;
     }



   
    printf("初始化成功\n") ;
    
     fclose(fp) ;



 }
//回收链表申请的内存 并写入文件
 void Recover()
 {
          //清空文件
       FILE*fp = fopen("accout.txt","w") ;
       if(fp==NULL)
       {
         printf("写入文件失败，请联系管理员\n") ;
        

       }
       else
       {
        p = head->next ;
        while(p!=NULL)
        {
           
             printf("正在保存数据........\n") ;
                 fprintf(fp,"%d  %s %s %s\n",p->date.login,p->date.userName,p->date.code,p->date.name)  ;
                     
           
        
            p=p->next ;

        }
         printf("保存成功!\n") ;
       }
       
       



       fclose(fp) ;
       





      accout*temp ;
      while(head!=NULL)
      {
           temp = head->next ;
           free(head) ;
           head = temp ;
           printf("正在回收链表内存.....\n") ;
      }
      printf("回收成功\n欢迎您的再次使用!\n") ;
 }  
//检测数据库中是否含有该账号
int RepeatUsername(char userName[] )
{
   
    //遍历链表
    accout *temp = head->next ;
    while(temp!=NULL)
    {
        if(!strcmp(temp->date.userName,userName) )      
        {
         return 1 ;
        }
   
 
       temp = temp->next ;
    }
    return 0 ;


  
     
}
//添加链表 原理
void ListAccoutAdd(accout  TempAdd)
{
     
         //待添加
   struct accout *temp = (struct accout*)malloc(sizeof(struct accout)) ;
   temp->date.login = TempAdd.date.login ;
   strcpy(temp->date.userName,TempAdd.date.userName) ;
   strcpy(temp->date.code,TempAdd.date.code) ;
   strcpy(temp->date.name,TempAdd.date.name) ;
     tail ->next = temp ;
     tail = temp ;
     tail->next = NULL ;
}
//---------------------------------
//第二部分
//具体操作的实现 
//修改身份信息 用户名 密码  性别 地址 电话 教师
//
//学生页面绘图
void studentMenu(struct accout*p1)
{     
      printf("目前登录账号:%s",p1->date.userName) ;
      printf("目前所在页面:学生页面") ;
      printf("------按1修改信息------") ;
      printf("------按2查看信息------") ;
      printf("------按3退出登录------") ;
      printf("------按4注销账号------") ;
      printf("------按5查看成绩------") ;
      printf("------按0退出系统------") ;
      printf("---------------------") ;


}
//学生页面选项()
int studentMenuChoose(struct accout*p1)
{
      while(1)
      { 
        studentMenu(p1) ;
        int a ;
        scanf("%d",&a) ;

        switch(a)
        {
                case 1:
                ChangeList(p1) ;
                break ;
                case 2 :
                PrintList(p1) ;
                printf("按任意键继续\n") ;
                TimeOut() ;
                break ;
                case 3 :
                printf("正在退出....") ;
                printf("按任意键继续\n");
                TimeOut() ;
                return 1 ;
                case 4 :
                printf("确定要删除吗?\n");
                printf("继续按1 返回按0") ;
                int b;
                scanf("%d",&b);
                if(b==1)
                {
                     printf("注意此操作无法撤销，一旦销毁用户数据将消失!\n");
                     printf("注意此操作无法撤销，一旦销毁用户数据将消失!\n");
                     printf("注意此操作无法撤销，一旦销毁用户数据将消失!\n");
                     printf("继续按1 放回按0");
                     int c ;
                     scanf("%d",&c) ;
                     if(c==1)
                     {
                         ListDelte(p1) ;

                     }
                     else 
                     {
                         printf("正在返回....\n") ;
                         break ;
                     }
                }
                else 
                {printf("正在返回....\n") ;
                  break ;
                }
                
                break ;
                case 5:
                //待实现
                break ;
                case 0 :
                return 0 ;
                break ;
                
                
                
                
        }


      }
}
                                               
//---------------------------------
//op部分
int opMenuChoose()
{
     char opAccount[100] ="QLluck" ;
     char opCode[100]="123454321" ;
     char code[100] ;
     char account[100] ;
     printf("请输入账号:") ;
       scanf("%s",account) ;
       if(strcmp(opAccount,account)) 
       {
          printf("账号输入错误\n") ;
          return 0 ;
       }

     printf("\n请输入密码:") ; 
      scanf("%s",code) ;
      if(strcmp(code,opCode))
      {
          printf("密码输入错误\n") ;
          return 0 ;
      }
      printf("登录成功!\n") ;
      return 1 ;

}   
void opMenu()
{
  printf("------------") ;
  printf("按1展示所有账号") ;
}
void opLogin()
{

}


//-----------------

int main()
{     
     //先进行文件查找 记录登录账号和 所有数据
     //初始化
    Inital();

      loginChoose() ;

     //回收
       Recover();


     
}












