#include<bits/stdc++.h>
using namespace std ;
const int inf = 1e9+7 ;
const int N = 5e4 + 7 ;
struct node
{
     int l,r,ma,lazzy ;

}t[N]={0};
void pushup(int p )
{
      t[p].ma = max(t[p<<1].ma,t[p<<1|1].ma);
}
void pushdown(int p)
{
     if(t[p].lazzy)
     {
          t[p<<1].ma+=t[p].lazzy;
          t[p<<1|1].ma+=t[p].lazzy;
          t[p<<1].lazzy+= t[p].lazzy;
          t[p<<1|1].lazzy+= t[p].lazzy;
           t[p].lazzy=0;
     }
}
void update(int p ,int l ,int r ,int k)
{
      if(l<=t[p].l&&t[p].r<=r)
      {
           t[p].ma+= k ;
           t[p].lazzy +=k ;
           return ;
      }
      pushdown(p);
      int m = (t[p].l+t[p].r)>>1 ;
      if(l<=m) update(p<<1,l,r,k);
      if(r>m) update(p<<1|1,l,r,k);
      pushup(p);

 
}
int query(int p,int l,int r)
{
      if(l<=t[p].l&&t[p].r<=r) return t[p].ma ;
      pushdown(p);
      int m =(t[p].l + t[p].r)>>1 ;
      int ma = -inf;
      if(l<=m) ma=max(ma,query(p<<1,l,r));
      if(r>m) ma=max(ma,query(p<<1|1,l,r));
      return ma ;
}
void build(int p, int l,int r )
{
      node temp={l,r,0,0};
      t[p]=temp;
      if(l==r) return ;
      int m =(l+r)>>1; 
      build(p<<1,l,m);
      build(p<<1|1,m+1,r);
      pushup(p) ;

}
void solve()
{
     int n ,m;
     cin>>n>>m ;
     build(1,1,n);
     while(m--)
     {
         int k,l,r;
         cin>>k>>l>>r;
         if(k==1)
         {
              update(1,l,r,1);

         }
         else if(k==2) cout<<query(1,l,r)<<'\n';
     }
}
int main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  solve();
}