#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;

int me[N] = {0};
int n, m;
int dfs( vector<int> g[], int x)
{
      if(me[x])
          return me[x]=max(me[x] ,x);
       me[x] = x ;
       int ma = x; 
      cout << x << '\n';
      for (int i = 0; i < g[x].size(); i++)
      {
          ma = max(dfs(g,g[x][i]), ma);
      }
  
      return me[x] = max(me[x], ma);
}

void solve()
{
    cin >> n >> m;
    vector<int> g[n+1];
    for(int i = 1; i <= n;i++)
        g[i].reserve(m);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u>> v;
        g[u].push_back(v);

    }
    for (int i = 1; i <= n;i++)
        dfs(g,i);
    for (int i = 1; i <= n;i++ )
        cout << me[i] << ' ';
}
 
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}