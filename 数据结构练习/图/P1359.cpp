#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 7;
int n;
int it;
struct node
{
    int u, v, w;

} g[N];
int me[N] = {0};
int me2[N] = {0};
int find(int  x)
{
      if(me[x]==x )
          return me[x];
      return me[x] = find(me[x]);
        }
bool sort1(node &a,node&b)
{
 return a.w<b.w;     
}
int ans ;
bool kru()
{
   
    int cnt = 0 ; 
    for (int i = 1; i <= it; i++)
    {
        int x = find(me[g[i].u]);
        int y = find(me[g[i].v]);
        if (x != y&&!me2[i])
        {
            me[x] = y;
            me2[i] = 1;
            ans += g[i].w;
            cnt++   ; 
        }
    }
    return cnt == n - 1;
}
void solve()
{
    
    cin>>n ;
    for (int i = 1; i <= n;i++)
    me[i] = i;
        for (int i = 1; i < n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                g[++it].u = i;
                g[it].v = j;
                int w;
                cin >> w;
                g[it].w = w;
            }
        }
        sort(g + 1, g + n + 1, sort1);
 
      
        cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}