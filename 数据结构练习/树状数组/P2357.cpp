#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N =2e5+7;
ll arr[N]={0};
struct node
{
     ll l,r,sum,lazzy;

}t[N*4];
void pushup(ll p)
{
      t[p].sum = t[p<<1].sum+ t[p<<1|1].sum ;

}
void pushdown(ll p)
{
     if(t[p].lazzy)
     {
         t[p<<1].sum+= t[p].lazzy*(t[p<<1].r-t[p<<1].l+1);
         t[p<<1|1].sum+= t[p].lazzy*(t[p<<1|1].r-t[p<<1|1].l+1);
         t[p<<1].lazzy+=t[p].lazzy;
         t[p<<1|1].lazzy+=t[p].lazzy;
         t[p].lazzy = 0 ;
     }
}
void update(ll p,ll l, ll r,ll k)
{
     if(l<=t[p].l&&t[p].r<=r)
     {
          t[p].sum+= k*(t[p].r - t[p].l +1);
          t[p].lazzy += k ;
          return; 
     }
     pushdown(p);
     ll m = (t[p].l+t[p].r)>>1;
     if(l<=m) update(p<<1,l,r,k);
     if(r>m) update(p<<1|1,l,r,k);
     pushup(p);
}
ll query(ll p,ll l,ll r)
{
      if(l<=t[p].l&&t[p].r<=r)
      {
          return t[p].sum ;
      }
      pushdown(p);
      ll sum = 0  ;
      ll m = (t[p].l+t[p].r)>>1;
      if(l<=m) sum+=query(p<<1,l,r);
      if(r>m) sum+=query(p<<1|1,l,r);
      return sum ;

}
void build(ll p,ll l,ll r)
{
     node temp ={l,r,arr[l],0};
     t[p]=temp ;
     if(l==r) return ;
     ll m = (l+r)>>1;
     build(p<<1,l,m);
     build(p<<1|1,m+1,r);
     pushup(p);
     
}
void solve()
{
     int n,m;
     cin>>n>>m;
     for(int i =1; i<=n ;i++)
     {
       cin>>arr[i];
     }
     build(1,1,n);
     while(m--)
     {
          ll q,l,r,k;
          cin>>q;
          if(q==1)
          {
             cin>>l>>r>>k;
             update(1,l,r,k);

          }
          else if(q==2)
          {  cin>>k;
             update(1,1,1,k);
          }
          else if(q==3)
          {  cin>>k;
             update(1,1,1,-k);
          }
          else if(q==4)
          {
            cin>>l>>r;
            cout<<query(1,l,r)<<'\n';
          }
          else if(q==5)
          {
             cout<<query(1,1,1)<<'\n';
          }
        
     }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}
