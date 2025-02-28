//上一个方法用不了 这次换一个解决办法
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> t[N];
int me[N] = {0};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m;i++)
    {
        int x, y;
        cin >> x >> y;
        t[y].push_back(x) ;
    }
    map<int,int> mp;
    for(int i = n ; i>=1; i--)
    {
        t[i].push_back(i);
        me[i] = max(i,me[i]);
        for (int j = 0; j < t[i].size(); j++)
        {
             if(mp.count(t[i][j]))
                 continue;
             me[t[i][j]] = i;
             cout << me[i] << ' ';
             mp[t[i][j]] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}