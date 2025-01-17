#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int N = 5e5+7 ;
int arr[N]={0};
int so[N]={0};
int  t[N]={0};
int lowbit(int x) {return x&-x;}
void add(int p,int x)
{
     while(p<N)
     {
          t[p]+=x ;
          p+=lowbit(p);
     }
}
int count(int p)
{   int res= 0 ;
    while(p)
    {
          res+=t[p];
          p-=lowbit(p);
    }
return res ;
}
void solve()
{
      int n;
      cin>>n; 
      ll ans= 0 ;
      map<int ,int > mp ;
      for(int i =1 ;  i<=n ;i++)
       {  cin>>arr[i];
        so[i]=arr[i];
       }
       sort( so+1 , so +n+1);
       for(int i =1; i<=n ;i++)
       {
          if(mp.count(so[i])) continue ;
          mp[so[i]]=i ;
       }
      
      for(int i =n ;i>=1; i--)
      {
          ans+= count( mp[arr[i]] -1) ;
          add( mp[arr[i]],1 );
      }
      cout<<ans<<'\n';
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve() ;
}
