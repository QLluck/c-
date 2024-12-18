//注释  被//标记的代码为废案
//一定要按程序退出 



//头文件标记处------------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//------------------------
//类定义处-------------------
struct student
{  //用于标记是否为学生账号
   int login;
   //用户名
   char userName[100] ;
   //密码
   char code[100] ;
   char name[100] ;

   


};
struct teacher
{ 
   int login;
   //用户名
   char userName[100] ;
   //密码
   char code[100] ;
   char name[100] ;

   teacher() : login(0) {} // Constructor to initialize login
};
struct op
{
    int login ;

};
struct accout
{     
      student student ;
      teacher teacher ;
       op op ;
       //实现链表
       accout * next ;


};
//---------------------
//函数声明处-------------------------
void menuLogin();
void loginChoose() ;
int checkFileEmpty() ;
void TimeOut();
int login(int choose);
void Recover() ;
void Inital() ;
int RepeatUsername(char userName[] );
void ListAccoutAdd(accout * TempAdd) ;
void Register();
//-------------------------
//全局变量定义处---------------------
accout *head,*p,*tail ;



//-------------------------
//函数定义处---------------------------

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
      printf("------------------按1登录学生账号-----------------\n");
      printf("------------------按2登录教师账号-----------------\n");
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
        if(login(1))
        {
          printf("登录成功\n") ;
          printf("欢迎学生%s",p->student.userName) ;
         printf("正在访问学生界面\n") ;
           printf("按任意键继续\n") ;
          TimeOut() ;
          
        }
        else
        {

        }
          
           //printf("按任意键继续\n") ;
           //TimeOut();
           break ;
        case  2 :
          
           if(login(2))
        {
          printf("登录成功\n") ;
          printf("欢迎教师 %s " , p->teacher.userName) ;
          printf("正在访问教师界面\n") ;
          printf("按任意键继续\n") ;
          TimeOut() ;
          
        }
        else
        {

        }
           break ;
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
           case 666666 :
           //printf("欢迎来到管理员界面") ;
           if(opLogin())
           {  
              opMenuChoose() ;
           }
           else
           {
              
              break ;
           }
           

           
           break ;
        default:
        printf("请您输入正常的选项\n") ;
        goto loginChooseCina ;


       }

}
}
//登录功能
//原理通过用户名来检查链表数据 如果对的话 p指向账号
int login(int choose)
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
     p=head ;
     char str[1000] ;
     char userName[1000] ;
     char code[1000] ;
    
         printf("请输入用户名:") ;
    switch(choose)
    {      case 1 :

         scanf("%s",userName) ;
         while(p!=NULL) 
         {
             
             if(!strcmp(userName,p->student.userName ))
             {int times = 3 ;
                while(times--)
               {
                  printf("请输入密码:") ;
   
                               
                  scanf("%s",code) ;
                   if(strcmp(code,p->student.code))
                   {
                       printf("密码错误\n还剩%d次机会\n",times) ;
                       
                    

                   }
                   else
                   {
                    return 1 ;
                   }


                  //  printf("登录成功\n") ;
                  //  printf("欢迎用户 %s \n",p->student.userName ) ;
                  //  printf("正在前往学生专属页面.......\n") ;
                  //  printf("按任意键继续......\n") ;
                  //  TimeOut() ;
                




               }
                 printf("输入三次密码错误,请重新登录\n") ;
                    return 0 ;
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
          return 0 ;
         
         

         break ;
         case 2 :

         scanf("%s",userName) ;
         while(p!=NULL) 
         {
             

             if(!strcmp(userName,p->teacher.userName ))
             {int times = 3 ;
                while(times--)
               {
                  printf("检请输入密码:") ;
    
                  scanf("%s",code) ;
                   if(strcmp(code,p->teacher.code))
                   {
                       printf("密码错误\n还剩%d次机会\n",times) ;
                       
                 

                   }
                   else
                   {
                    return 1 ;
                   }


                  //  printf("登录成功\n") ;
                  //  printf("欢迎用户 %s \n",p->teacher.userName ) ;
                  //  printf("正在前往教师专属页面.......\n") ;
                  //  printf("按任意键继续......\n") ;
                  //  TimeOut() ;
                   




               }
               printf("输入三次密码错误,请重新登录\n") ;
               return 0 ;
               


                 
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
          return 0;
         
         

         break ;
    }
     
     
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
   temp.student.login = 0 ; 
   temp.teacher.login = 0 ;
   //两个功能，注册学生账号，和教师账号
   printf("注册学生账号请按1,师生账号请按2,退出请按0\n") ;
    int a ;
RegisterCina: 
    scanf("%d",&a) ;

   switch (a) 
   {
         case 1 :
         printf("请输入账号名\n") ;
registerStudentUsername: 
         scanf("%s",temp.student.userName) ;
         //检测数据库中是否含有该账号
          if( RepeatUsername(temp.student.userName ))
          {
             printf("已有该用户存在，请重新输入用户名\n") ;
             goto registerStudentUsername ;

          }

          printf("请输入密码\n") ;
          scanf("%s",temp.student.code) ;
          temp.student.login = 1 ;
          break ;
         case 2 :
         printf("请输入账号名\n") ;
registerTeacherUsername: 
         scanf("%s",temp.teacher.userName) ;
         //检测数据库中是否含有该账号
          if( RepeatUsername(temp.teacher.userName ))
          {
             printf("已有该用户存在，请重新输入用户名\n") ;
             goto registerTeacherUsername ;

          }

          printf("请输入密码\n") ;
          scanf("%s",temp.teacher.code) ;

              temp.teacher.login = 1 ;
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
   //添加链表


   
   

    ListAccoutAdd(&temp) ;
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
     FILE *fp = fopen("//Users//jack5//c语言项目//学生信息管理系统//accout","r") ;
     if(fp==NULL)
     {
      printf("初始化失败,请联系管理员\n") ;
      fclose(fp) ;
      return ;
     }
      

     char str[10000] ;
     while( fgets(str, sizeof(str), fp) != NULL )
     {
              accout* temp = (accout*)malloc(sizeof(accout)) ;
              sscanf(str,"%d %d %*s %*s",&temp->student.login,&temp->teacher.login) ;
              if(temp->student.login)
              {
                  sscanf(str,"%*d %*d %s %s",temp->student.userName,temp->student.code) ;
              }
              else if(temp->teacher.login)
              {
                  sscanf(str,"%*d %*d %s %s",temp->teacher.userName,temp->teacher.code) ;

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
       FILE*fp = fopen("//Users//jack5//c语言项目//学生信息管理系统//accout","w") ;
       if(fp==NULL)
       {
         printf("写入文件失败，请联系管理员\n") ;
        

       }
       else
       {
        p = head ;
        while(p!=NULL)
        {
            if(p->student.login)
            {   printf("正在保存数据........\n") ;
                 fprintf(fp,"%d %d %s %s \n",p->student.login,p->teacher.login,p->student.userName,p->student.code)  ;
                     
            }
            else if(p->teacher.login)
            {
                  printf("正在保存数据........\n") ;
                 fprintf(fp,"%d %d %s %s \n",p->student.login,p->teacher.login,p->teacher.userName,p->teacher.code)  ;
                     
            }
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
    accout *temp = head ;
    while(temp!=NULL)
    {
        if(!strcmp(temp->student.userName,userName) )      
        {
         return 1 ;
        }
         if(!strcmp(temp->teacher.userName,userName) )      
        {
         return 1 ;
        }
 
       temp = temp->next ;
    }
    return 0 ;


  
     
}
//添加链表 原理
void ListAccoutAdd(accout * TempAdd)
{
     
     accout*temp = (accout*)malloc(sizeof(accout)) ;
     strcpy(temp->student.userName,TempAdd->student.userName) ;
     strcpy(temp->student.code,TempAdd->student.code) ;
     strcpy(temp->teacher.userName,TempAdd->teacher.userName) ;
     strcpy(temp->teacher.code,TempAdd->teacher.code) ;
         temp->student.login = TempAdd->student.login ;
         temp->teacher.login = TempAdd->teacher.login ;
         //待添加
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
void studentMenu()
{     
      printf("目前登录账号:%s",p->student.userName) ;
      printf("目前所在页面:学生页面") ;
      printf("------按1修改信息------") ;
      printf("------按2补充信息------") ;
      printf("------按3退出登录------") ;
      printf("------按4注销账号------") ;
      printf("------按5查看成绩------") ;
      printf("------按0退出系统------") ;
      printf("---------------------") ;


}
//学生页面选项()
void studentMenuChoose()
{
      while(1)
      { 
        studentMenu() ;
        int a ;
        scanf("%d",&a) ;

        switch(a)
        {

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












