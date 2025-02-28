#include<bits/stdc++.h>
using namespace std;
int kmp(string s )
{
    vector<int> arr(s.size());

    for (int i = 1, len = 0;i<s.size(); i++)
    {
        while (len&&s[i] != s[len])
        {
            len = arr[len - 1];
        }
        if(s[i]==s[len])
        {
            arr[i] = ++len;
            //cout << arr[i] <<' ' ;
        }
   }
   cout << s.size() - arr[s.size()-1];
   return 0;
}
void solve()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    kmp(s);
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}