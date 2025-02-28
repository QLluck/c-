#include <bits/stdc++.h>
using namespace std;
string getmin(string s)
{
    s = '#' + s + s;
    int n = s.size();
    int i = 1,j = 2;
    while(j<=n)
    {
        int k = 0; 
        while(k<n&&s[i+k]==s[j+k])
            k++;
        if(s[i+k]>s[j+k])
            i += k + 1;
        else
            j += k + 1;
        if(i==j)
            j++;
        if(i>j)
            swap(i, j);
        
    }
    return s.substr(i, n);
}
void solve()
{
    string s;
    cin >> s;
    s = getmin(s);
    cout << s << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
}