#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<string,int> mp;
    int ans = 0; 
    for (int i = 1; i <= n;i++)
    {
        string s;
        cin >> s;
         if(mp.count(s))
             continue;
         mp[s]++;
         ans++;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}