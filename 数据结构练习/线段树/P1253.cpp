#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+7 ;
const int in = 1e9+7 ;
#define ll long long 
ll arr[N]={0};
struct node
{
     ll l,r ,ma,lazzy ,gu;
}tr[N*4];
void pushup(ll p)
{
      tr[p].ma = max(tr[p<<1].ma ,tr[p<<1|1].ma) ;

}

void pushdown(ll p)
{    
    
     if(tr[p].lazzy)
     {
          tr[p<<1].ma+= tr[p].lazzy ;
          tr[p<<1|1].ma+= tr[p].lazzy ;
          tr[p<<1].lazzy+= tr[p].lazzy ;
          tr[p<<1|1].lazzy += tr[p].lazzy ;
          tr[p].lazzy = 0;
     }
}
void update(ll p ,ll l ,ll r ,ll x)
{
   
      if(l<=tr[p].l&&tr[p].r<=r)
      {
          tr[p].ma+= x ;
          tr[p].lazzy += x ;
          return ;
      }
         pushdown(p);

      
      ll m =  (tr[p].l+tr[p].r )>>1; 
      if(l<=m ) update(p<<1,l,r,x);
      if(r>m ) update(p<<1|1,l,r,x);
      pushup(p);
}
void upgu(ll p,ll l ,ll r , ll gu)
{  pushdown( p);
       if(l<=tr[p].l&&tr[p].r<=r)
       {
          tr[p].ma = gu ;
          tr[p].lazzy =0 ;
       }
      ll m =  (tr[p].l+tr[p].r )>>1; 
      if(l<=m ) update(p<<1,l,r,gu);
      if(r>m ) update(p<<1|1,l,r,gu);
      pushup(p);
      
     
}
ll query(ll p,ll l,ll r )
{
    if(l<=tr[p].l&&tr[p].r<=r)
      {
          return tr[p].ma ;
      }
      pushdown(p);
      ll m =  (tr[p].l+tr[p].r )>>1; 
      ll ma = -in ;
      if(l<=m )ma =max(ma, query(p<<1,l,r) );   
      if(r>m ) ma= max( ma, query(p<<1|1,l,r) );   
      pushup(p);
      return ma ;
    
}
void build(ll p ,ll l ,ll r )
{
     node temp = {l,r,arr[l],0,in};
     tr[p]=temp ;
     if(l==r) return ;
     ll m =(l+r)>>1 ;
     build(p<<1,l,m);
     build(p<<1|1,m+1,r);
     pushup(p);
}

void solve()
{
      ll n,m;
      cin>>n>>m;
      for(int i = 1 ;i<=n ;i++)cin>>arr[i];
      build(1,1,n);
      while(m--)
      {
          ll op,l,r,x ;
          cin>>op;
          switch(op)
          {
             case 1 :
             cin>>l>>r>>x;
             upgu(1,l,r,x);
             break ;
            case 2 :
            cin>>l>>r>>x;
            update(1,l,r,x);
            break; 
            case 3 :
            cin>>l>>r ;
            cout<<query(1,l,r)<<'\n';
          }
      }
      for(int i = 1 ; i<=n ;i++)
      {
          cout<<query(1,i,i)<<' ';
      }
      cout<<'\n';

}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0);
     solve();
}