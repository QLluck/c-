#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =1e5+7 ;
ll t[N]={0};
ll lowbit(ll x)
{
      return x&-x ;
}
void add(ll p, ll x)
{
      while(p<N)

      {
          t[p]+=x ;
          p+=lowbit(p);
      }
}
ll count(ll p)
{   ll res= 0 ;
      while(p)
      {
          res+=t[p];
          p-=lowbit(p);
      }
      return res ;
}
void solve()
{
     ll n,m;
     cin>>n>>m;
     while(m--)
     {
        char c ;
        ll l, r ;
        cin>>c>>l>>r;
        if(c=='x') add(l,r);
        else if(c=='y') cout<<count(r)-count(l-1)<<'\n';
     }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}