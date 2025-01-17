#include<bits/stdc++.h>
using namespace std ;
const int N =1e2+7;
int t[N]={0};
int lowbit(int x) {return x&-x;}
void add(int p,int x)
{
     while(p<N)
     {
          t[p]+=x ;
          p+=lowbit(p);
     }
}
int count(int p)
{
     int res= 0 ;
     while(p)
     {
         res+=t[p];
         p-=lowbit(p);
     }
     return res; 

}
void solve()
{
     int n,m;
     cin>>n>>m;
     while(m--)
     {
         int l,r;
         cin>>l>>r;
         add(l,1);
         add(r+1,-1);
     }
     for(int i  = 1; i<=n ;i++)
     {
          int a = count(i);
          if(a!=1)
          {
            cout<<i<<' '<<a<<'\n';
            return ;
          }
     }
     cout<<"OK"<<'\n';
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}