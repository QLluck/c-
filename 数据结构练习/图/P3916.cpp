#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> t[N];
int me[N] = {0};
int dfs(int  x)
{
      if(me[x])
          return me[x];
    
      me[x] =  x ;
      for (int i = 0; i < t[x].size(); i++)
      {   
          me[x] = max(me[x], dfs(t[x][i]));
      }
          return me[x] ;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m;i++)
    {
        int x, y;
        cin >> x >> y;
        t[x].push_back(y);
    }
    for (int i = 1; i <= n;i++)
    {
         if(me[i])
             cout << me[i] << ' ';
          else 
          {
              cout<<dfs(i)<<' ' ;
              
            }
    }
}
 
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}