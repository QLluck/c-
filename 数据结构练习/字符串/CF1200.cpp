#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

string kmp(string &s2, string &s1)
{   
    vector<int> arr(min(s1.size(),s2.size() ) ) ;
    for (int i = 1, len = 0; i < min(s1.size(),s2.size() ); i++)
    {
        while (len && s1[i] != s1[len]) 
        if (s1[i] == s1[len])
            arr[i] = ++len;
    }
    for (int i = max(0, (int)(s2.size() -s1.size()) ), len = 0; i <  s2.size(); i++)
    {
        while (len && s2[i] != s1[len])
            len = arr[len - 1];
        if (s2[i] == s1[len])
        {
            ++len;
        }
        if (i == s2.size() - 1)
        {
            string s = s2 + s1.substr(len, s1.size() - len);
            return s;
        }
    }
    return "";
}
void solve()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    for (int i = 1; i < n; i++)
    {
        string s2;
        cin >> s2;
        s1 = kmp(s1, s2);
    }
    cout << s1<<'\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}