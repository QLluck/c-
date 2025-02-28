#include <bits/stdc++.h>
using namespace std;
int kmp(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<int> arr(s2.size());
    for (int i = 1, len = 0; i < m; i++)
    {
        while(len && s2[i]!=s2[len])
            len = arr[len - 1];
        if(s2[len]==s2[i])
            arr[i] = ++len; 
    }
    for (int i = 0, len = 0;i<n; i++)
    {
          while(len&&s1[i]!=s2[len])
              len = arr[len - 1];
            
          if(s1[i]==s2[len])
            {
                
                if(++len ==m)
                {
                    cout << i - m + 2 << '\n';
                    
                }
            }
    }
    for (int i = 0; i < m; i++)
        cout << arr[i] <<' ';
    return 0;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    kmp(s1, s2);
} 
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
    return 0;
}