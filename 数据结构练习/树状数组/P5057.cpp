//翻转偶数为零 奇数为1
#include<bits/stdc++.h>
using namespace std ;
const int N =1e5+7 ;
int t[N]={0};
int lowbit(int x) {return x &-x;}
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
     int res =0  ;
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
     while(m--)
     {
         int q,l,r;
         cin>>q;
         if(q==1)
         {
             cin>>l>>r;
             add(l,1);
             add(r+1,-1);

         }
         else if(q==2)
         {
             cin>>l;
             int a = count(l)&1;
             cout<<a<<'\n';
         }
     }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}