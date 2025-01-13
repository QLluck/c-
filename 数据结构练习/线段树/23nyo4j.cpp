#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =1e5+7 ;

struct node
{
     ll l,r,sum,ma,lazzy;
}tr[N*4];

void pushup(ll p )
{
      tr[p].sum= tr[p<<1].sum + tr[p<<1|1].sum ;
      tr[p].ma= max(  tr[p<<1].ma,tr[p<<1|1].ma );
}
void  pushdown(ll p)
{
      if(tr[p].lazzy)
      {
            tr[p<<1].sum += tr[p].lazzy*(tr[p<<1].r- tr[p<<1].l +1);
            tr[p<<1|1].sum += tr[p].lazzy*(tr[p<<1|1].r- tr[p<<1|1].l +1);
            tr[p<<1].lazzy+=tr[p].lazzy ;
            tr[p<<1|1].lazzy += tr[p].lazzy ;
            tr[p<<1].ma += tr[p].lazzy ;
            tr[p<<1|1].ma += tr[p].lazzy ;
  tr[p].lazzy = 0 ;
      }
}
void build(ll p ,ll l ,ll r )
{
      node temp= {l,r,0,0,0};
      tr[p]=temp ;
      if(l==r) return ;
      ll m = (l +r)>>1; 
      build(p<<1,l,m);
      build(p<<1|1,m+1,r);
      pushup(p);
}
void update(ll p,ll l,ll r ,ll k)
{
      if(l<=tr[p].l&&tr[p].r<=r)
      {
          tr[p].sum+= k*(tr[p].r -tr[p].l+1) ;
          tr[p].lazzy+=k;
          tr[p].ma += k ;
          return ;
      }
      pushdown(p);
      ll m = (tr[p].l+ tr[p].r)>>1 ;
      if(l<=m) update(p<<1,l,r,k);
      if(r>m) update(p<<1|1,l,r,k);
      pushup(p);
}
ll mm(ll p)
{
     return tr[p].ma ;
}
void solve()
{
      ll n,m;
      cin>>n>>m ;
      build(1,1,n);
      int ans= 1 ;
     for(int i =1; i<=n ;i++)
      {
          ll l ,r ,x ;
          cin>>l>>r>>x ;
          update(1,l,r,x) ;
          if(ans && tr[1].ma >=m)
          {
             ans =0 ;
             cout<<i<<'\n';
          }
      }
      if(ans)
      {
         cout<<"impossible"<<'\n';
      }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}