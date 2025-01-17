#include<bits/stdc++.h>
using namespace std ;
const int N =5e5+7;
int t[N]={0};
int arr[N]={0} ;
int lowbit(int x)
{
      return x&-x ;
}
void add(int p,int x )
{
      while(p<N)
      {
          t[p]+=x ;
          p+=lowbit(p);
      }
}
int count(int p)
{  int res=0 ;
     while(p)
     {    res+=t[p];
          p-=lowbit(p);
     }
     return res ;
}
void solve()
{
     int n,m ;
     cin>>n>>m;
     
     for(int i = 1 ; i<=n ;i++) cin>>arr[i];
     for(int i = 1 ; i<=n ;i++) add(i, arr[i]-arr[i-1]);
     while(m--)
     {
          int a,l,r,k;
          cin>>a;
          if(a==1)
          {
              cin>>l>>r>>k;
                add(l,k);
                add(r+1,-k);

          }
          else  if(a==2)
          
          {      cin>>k;
                        cout<<count(k)<<'\n' ;
          }
     }
}
int main()
{
      ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
      solve();
}