#include<bits/stdc++.h>

using namespace std;
int n, m;

void dfs(vector<int> g[],int me[] ,int x )
{
   if(me[x])
       return;
   me[x] = 1;
   cout << x << ' ';

   for (int i = 0; i < g[x].size(); i++)
   {
      // cout << x << ' ' << g[x][i] << '\n';
       dfs(g, me, g[x][i]);
    }
   
    return ;
}
void bfs(vector<int> g[] , int me[] )
{
      queue<int >que;
      que.push(1);
      me[1] = 1;
    
      while(!que.empty())
      {
          int u = que.front();
          que.pop();
          cout << u << ' ';
          for (int i = 0; i < g[u].size(); i++)
          { 
            if(me[g[u][i]])
                continue;
            me[g[u][i]] = 1;
            que.push(g[u][i]);
          }
      }
}


void solve()
{
   cin>>n>>m;
   vector<int> g[n + 1];
   for (int i = 1; i <= m;i++)
   {
       int x, y;
       cin >> x >> y;
       g[x].push_back(y);
       
   }
   for (int i = 1; i <= n; i++)
       sort(g[i].begin(), g[i].end());
   int me[n + 1];
   memset(me, 0, sizeof(me));

   dfs(g, me, 1);
   cout << '\n';
   memset(me, 0, sizeof(me));
   bfs(g, me);
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}