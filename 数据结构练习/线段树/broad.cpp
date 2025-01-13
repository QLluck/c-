#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5+7 ;
int w[N]={0} ;
//输入 n个元素建立线段树
//线段树的建立

struct node
{
      int  l,r ,sum ,lazzy;
}tr[N*4] ;
void build(int p ,int l,int r)
{   node temp ={l, r, w[l], 0};
    tr[p] =temp ;
    if(l==r) return ;
    int m = (l+ r )>>1 ;
    build(p<<1 ,l ,m);
    build(p<<1|1, m+1,r ) ;
    tr[p].sum  =  tr[p<<1].sum + tr[p<<1|1].sum ;


}
//lazzy更新
void pushdown(int p)
{
      if(tr[p].lazzy)
      {
       tr[p<<1].sum += tr[p].lazzy*( tr[p<<1].r - tr[p<<1].l+1 );
       tr[p<<1|1].sum += tr[p].lazzy*( tr[p<<1|1].r - tr[p<<1|1].l+1 );
       tr[p<<1].lazzy+= tr[p].lazzy ;
       tr[p<<1|1].lazzy+= tr[p].lazzy ;
          tr[p].lazzy=0 ;
      }
}
//区间修改&&但点修改 
void update(int p,int  l,int r ,int k)
{
    if(l<=tr[p].l && tr[p].r<=r) //如果区间全覆盖  
   {
       tr[p].sum+=(tr[p].r - tr[p].l +1) * k  ;
    tr[p].lazzy+=k ;
       return ;
   }
   int m = (tr[p].l+ tr[p].r) >> 1 ;
   pushdown(p) ;
   if(l<=m) update(p<<1,l,r,k);
   if(r>m) update(p<<1|1,l,r,k);
   tr[p].sum=tr[p<<1].sum + tr[p<<1|1].sum ;
  
   
}

//区间查询
long long query(int p ,int l ,int r)
{
      if(l<=tr[p].l&&tr[p].r<=r ) return tr[p].sum ;

      int m = ( tr[p].l +tr[p].r)>>1 ;
      int sum = 0 ; 
      pushdown(p) ;

      if(   l<=m)  sum+= query(p<<1 , l,r);
      if(   r>m)  sum+= query(p<<1|1 , l,r);
      return sum ; 
 }
    void print()
    {
          for(int i = 1 ; i<=10 ;i++)
          {
             cout<<query(1,i,i)<<' ' ;
          }
          cout<<'\n' ;
    }
int main()
{
    build(1,1,100) ;

      while(1)
      {
         int a ;
         cout<<"1为单点修改2为区间修改3 3为区间查询,4为单点查询 5 为数组展示"<<'\n' ;
         cin>>a ;
         switch(a)
         {
             case 1:
          {   int x, k ;
             cin>>x>>k ;
             update(1,x,x,k) ;
             print() ;
             break ;
          }
             case 2 :
            { int l,r ,k ;
             cin>>l>>r>>k ;
             update(1,l,r,k) ;
             print() ;
             break ;
            }
             case 3:
          {   int l,r ;
             cin>>l>>r ;
             cout<<query(1,l,r)<<'\n';

             break ;
          }
             case 4:
         {    int x ;
             cin>>x ;
             cout<<query(1,x,x)<<'\n';
             break ;
         }
             



         }
      }
}

