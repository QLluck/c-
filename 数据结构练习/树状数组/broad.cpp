#include<bits/stdc++.h>
using namespace std ;
const int N =5e5+7 ;
int t[N]={0};
int lowbit(int x) {return x&-x ;}
void add(int p,int x )
{
     while(p<N)
     {
          t[p]+=x ;
          p+=lowbit(p);
     }
}
int count(int p)
{  int res =0  ;
    while(p)
    {
          res+=t[p];
          p-=lowbit(p);
    }
    return res ;
}
void solve()
{
      int n,m;
      cin>>n>>m;
      for(int i =1 ; i<=n ;i++)
      { int x ;
      cin>>x;
          add(i,x);
      }
      while(m--)
      {
          int q,x,y;
          cin>>q>>x>>y ;
          switch(q)
          {
              case 1 :
              add(x,y);
              break ;
              case 2 :
              cout<<count(y)-count(x-1)<<'\n';
              break;

          }
      }
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}