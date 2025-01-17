//树状数组实现区间全加
#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define lowbit(x) x&-x
const int N= 2e5+7;
ll t1[N]={0};
ll t2[N]={0};
ll arr[N]={0};
void add(ll p , ll k)
{
     ll pos = p ;
     while(p<N)
     {
          t1[p]+=k ;
          t2[p]+=pos*k;
          p+=lowbit(p);
     }
}
ll count(ll p)
{
     ll pos = p ;
     ll res= 0 ;
     while(p)
     {
         res+= (pos+1)*t1[p] - t2[p];
         p-=lowbit(p);
     }
     return res ;
}
void solve()
{
     int n,m;
     cin>>n>>m ;
     for(int i =1 ;i<=n ;i++)cin>>arr[i];
     for(int i =1; i<=n ;i++)
     {
          add(i,arr[i]-arr[i-1]);
     }
     while(m--)
     {
          ll q,l,r,k;
          cin>>q;
          switch(q)
          {
              case 1:
              cin>>l>>r>>k;
              add(l,k);
              add(r+1,-k);
              break;
              case 2:
              cin>>k;
              add(1,k);
              add(2,-k);
              break;
              case 3:
              cin>>k;
              add(1,-k);
              add(2,k);
              break;
              case 4:
                cin>>l>>r;
                cout<<count(r)-count(l-1)<<'\n';
                break;
                case 5 :
                cout<<count(1)<<'\n';
                break;
          }
     }

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}