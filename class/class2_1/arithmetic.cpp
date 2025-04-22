#include"stack.h"
#include"arithmetic.h"
int staCInt(stack::Stack<char>&  sta )
{
      int l = sta.size();
      int sum =1 ;
      int res= 0 ; 
      while(l)
      {  res+=(sta.top()-'0' ) *sum;
         sta.pop();
         sum*=10;
        l--;
      }
      return res; 
}
void jiShuan(stack::Stack<double> &sta,char c )
{   double a= sta.top();
    sta.pop();
    double b = sta.top();
    sta.pop();

      if(c=='+')
      {
         sta.push(b+a);
      }
      else if(c=='-')
      {
         sta.push(b-a);
      }
      else if(c=='*')
      {
         sta.push(b*a);
      }
      else if(c=='/')
      {
         sta.push( b/a ) ;
      }

}
double start(std::string s )
{  
    stack:: Stack<double> stai ;
     stack::Stack<char> stac ;
     stack::Stack<char> stak ; 
     stack::Stack<char> staz ;
     stack::Stack<char> staw;
     for(int i =0 ;i<(int)s.size() ;i++)
     {   if(s[i]==' ')continue;
         if('0'<=s[i]&&s[i]<='9')
         {
             staz.push(s[i]);
         }
         else 
         {
             if(!staz.empty())
               { //std::cout<<'1'<<std::endl;
                 stai.push(staCInt(staz));
                 staw.push('0');//表示数字位置
                if(!stac.empty())
                {
                 char c =stac.top();
                 if(c=='-')
                {
                     stac.pop();
                     stac.push('+');
                     int temp = stai.top();
                     stai.pop();
                     stai.push(-temp);
                }
              }
                  
               }
              if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')//如果当前为运算符号 就入符号栈
             {
                  stac.push(s[i]);
             }
             else //判断括号
             {
                 if(!stak.empty()&&stak.top()=='(' && s[i]==')')
                 {
                     
                      //计算当前括号内的数
                      while(1)
                      {  char c = staw.top();//如果左括号前只有一个数，就退出循环
                        staw.pop();
                        if(staw.top()=='(')
                        { 
                            stak.pop();
                            staw.pop();
                            staw.push(c);
                            break;
                        }
                        staw.push(c);
                        jiShuan(stai,stac.top());//不断计算，直到遇到左括号
                       //std::cout<<stai.top()<<std::endl;
                       stac.pop(); 
                       staw.pop();
                       
                      }
                 }
                 else 
                 {
                     stak.push(s[i]);
                     staw.push(s[i]);//表示左括号位置
                 }
             }

         }
        //  std::cout<<"------------"<<std::endl;
        //  std::cout<<"stai"<<stai.size()<<std::endl;
        //  std::cout<<"stak"<<stak.size()<<std::endl;
        //  std::cout<<"stac"<<stac.size()<<std::endl;
        //  std::cout<<"staz"<<staz.size()<<std::endl;
        //  std::cout<<"---------------"<<std::endl;
         
         
     }
     if(!staz.empty())stai.push(staCInt(staz));//末尾数字处理，
     while(stai.size()>1)//如果栈里有大于一个的数字字,就一直计算
     {
        jiShuan(stai,stac.top());
        stac.pop(); //当前运算符出栈
     } 
     //最终栈顶数据就是答案
     return stai.top();

}
