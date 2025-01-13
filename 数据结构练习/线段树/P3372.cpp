
#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define int long long 
const int N = 1e5+7 ;
ll arr[N]={0} ;
struct node
{
      ll l,r ,sum,lazzy ;

}tr[N*4] ;

void pushup(ll p)
{
    tr[p].sum = tr[p<<1].sum + tr[p<<1|1].sum ;
 }
 void pushdown(ll p)
 {
      if(tr[p].lazzy)
      {
          tr[p<<1].sum += tr[p].lazzy*(tr[p<<1].r - tr[p<<1].l+1) ;
          tr[p<<1|1].sum += tr[p].lazzy*(tr[p<<1|1].r - tr[p<<1|1].l+1) ;
          tr[p<<1].lazzy+=tr[p].lazzy ;
          tr[p<<1|1].lazzy+=tr[p].lazzy ;
          tr[p].lazzy=0 ;
      }
 }
 void build(ll p ,ll l,ll r)
 {
      node temp ={l,r,arr[l],0};
      tr[p]=temp ;
      if(l==r) return ;
      int m =(l+r)>>1 ;
      build(p<<1, l ,m  );
      build(p<<1|1, m+1 ,r  );
      pushup(p) ;
 }
 void update(ll p,ll l,ll r,ll k)
 {
       if(l<=tr[p].l&&tr[p].r<=r) 
       {
         
          tr[p].lazzy+= k ;
          tr[p].sum+=  k*(tr[p].r-tr[p].l+1) ;

         return ;
       }
       pushdown(p) ;
      ll m =  (tr[p].l + tr[p].r)>>1 ;
       if(l<=m) update(p<<1,l,r,k);
       if(r>m) update(p<<1|1,l,r,k);
       pushup(p) ;
 }
 ll query(ll p ,ll l ,ll r )
 {
      if(l<=tr[p].l&& tr[p].r<=r) return tr[p].sum ;
      ll m  = (tr[p].l  + tr[p].r) >>1 ;
      pushdown(p) ;
      ll sum = 0 ; 
       if(l<=m) sum+=query(p<<1,l,r) ;
       if(r>m) sum+=query(p<<1|1,l,r) ;
      return sum ;
    
      
       
 }
 void solve()
 {
     int n,m;
     cin>>n>>m ;
     for(int i = 1 ; i<=n ;i++) cin>>arr[i] ;
     build(1,1,n) ;

    
     while(m--)
      
     {   
        int a ;cin>>a ;
        ll  x,y,k ;
          switch(a)
          {
             case 1: 
             cin>>x>>y>>k;
             update(1,x,y,k) ;
             break ;
             case 2:
              cin>>x>>y ;
              cout<<query(1,x,y)<<'\n' ;
              break ;
          }
     }
     
 }
 signed main()
 {
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
 } 