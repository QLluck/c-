#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std ;
const int N =5e4+7 ;
int t[N]={0};
int lowbit(int x ){return x&-x;}
void add(int p,int x )
{
      while(p<N)
      {   t[p]+=x; 
         p+=lowbit(p);
      }
}
int count(int p)
{
      int res= 0 ;
      while(p)
      {
         res+= t[p];
         p-=lowbit(p);
      }
      return res ;
}
void solve()
{
      int n ;
      cin>>n;
      memset(t,0,sizeof(t));
      for(int i = 1; i <=n ;i++)
      {
         int a ;
         cin>>a ;
        
         add(i,a);
      }
      string s ;
      int i,j;
      while(cin>>s)
      {  

          if(s=="End") return ;
         cin>>i>>j;  
          if(s=="Add") add(i,j);
          if(s=="Sub") add(i,-j);
          if(s=="Query") cout<<count(j)-count(i-1)<<'\n';
          
       
      }
}
int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  cin>>t; 
 for(int i =1; i<=t; i++)
 {
   cout<<"Case "<<i<<':'<<'\n';
  solve() ;
 }
}