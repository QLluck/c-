#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+7 ;
struct node
{
     int l,r ,of,dow,lazzy ;
}tr[N*4] ;
void pushup(int p )
{
      tr[p].dow = tr[p<<1].dow + tr[p<<1|1].dow ;
      tr[p].of = tr[p<<1].of + tr[p<<1|1].of ;

}
void pushdown(int p )
{
     if(tr[p].lazzy)
     {
      swap(tr[p<<1].of ,tr[p<<1].dow) ;
      swap(tr[p<<1|1].of ,tr[p<<1|1].dow) ;
      tr[p<<1].lazzy = !tr[p<<1].lazzy ;
      tr[p<<1|1].lazzy =!tr[p<<1|1].lazzy ;
      tr[p].lazzy=!tr[p].lazzy ;
     }
}
void build(int p ,int l,int r)
{
      node temp ={  l,r,0,1,0} ;
      tr[p] =temp ;
      if(l==r) return ;
      int m = (l+r)>>1 ;
      build(p<<1,l,m);
      build(p<<1|1,m+1,r);
      pushup(p) ;

}
void update(int p,int l,int r )
{
     if(l<=tr[p].l&&tr[p].r<=r ) 
     {
          swap(tr[p].of ,tr[p].dow) ;
          tr[p].lazzy =!tr[p].lazzy ;
         return ;
     }
     pushdown(p);
     int m = (tr[p].l+tr[p].r)>>1 ;
     if(l<=m) update(p<<1,l,r) ;
     if(r>m)update(p<<1|1,l,r); 
     pushup(p) ;
}
int query(int p ,int l,int r)
{
      if(l <=tr[p].l && tr[p].r<=r) return tr[p].of ;
      pushdown(p) ;
      int sum = 0 ; 
      int m  =(tr[p].l + tr[p].r)>>1 ;
      if(l<=m) sum+= query(p<<1,l,r) ;
      if(r>m) sum+= query(p<<1|1,l,r) ;
      return sum ;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    build(1,1,n) ;
    while(m--)
    {
        int a,x,y;
        cin>>a;
        switch(a)
        {
             case 0:
             cin>>x>>y;
             update(1,x,y);
             break ;
             case 1 :
              cin>>x>>y;
              cout<<query(1,x,y)<<'\n' ;
              break ;


        }

        
    }
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0) ;
     solve() ;
}