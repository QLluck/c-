#include<bits/stdc++.h>
using namespace std ;
#define lowbit(x) x&-x
const int N =5e5+7 ;
#define ll long long 
int t[N]={0};
int arr[N]={0};
int a[N]={0};
void add(int p,int x)
{
      while(p<N)
      {
         t[p]+=x;
         p+=lowbit(p);
      }
}
int count(int p)
{
     int res= 0 ;
     while(p)
     {
         res+= t[p];
         p-=lowbit(p);
     }
     return res; 
}

void solve()
{
   int n;
   cin>>n;
   for(int i = 1; i<=n ;i++)
{cin>>arr[i];
a[i]=arr[i];
 
}
   map<int ,int >mp;
   sort(arr+1,arr+n+1);
   for(int i=1; i<=n ;i++)
   {
      if(mp.count(arr[i]))continue ;
      mp[arr[i]] = i;
   }
   ll ans= 0 ;
   for(int i=1;i<=n; i++)
   {
      add(mp[a[i]],1);
      ans+= count(N) - count(mp[a[i]]);

   }
   cout<<ans<<'\n';



    
}
int main()
{
     ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
     solve();
}