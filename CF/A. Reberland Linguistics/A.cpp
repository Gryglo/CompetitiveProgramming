#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    n = a.size();
    for(int i = 0; i < 3; i++) a += '0';
}
int32_t main()
{
    init();
    vector<vector<bool>> dp(n + 3, vector<bool>(2));
    dp[n][0] = dp[n][1] = true;
    set<string> ans;
    for(int i = n - 2; i >= 5; i--)
    {
        string curr = string(1, a[i]);
        curr += a[i + 1];
        dp[i][0] = dp[i + 2][1];
        if(a[i] != a[i + 2] || a[i + 1] != a[i + 3])
            dp[i][0] = max(dp[i][0], dp[i + 2][0]);
        if(dp[i][0]) ans.insert(curr);
        curr += a[i + 2]; 
        dp[i][1] = dp[i + 3][0];
        if(a[i] != a[i + 3] || a[i + 1] != a[i + 4] || a[i + 2] != a[i + 5])
            dp[i][1] = max(dp[i][1], dp[i + 3][1]);
        if(dp[i][1]) ans.insert(curr);
    }
    cout << ans.size() << '\n';
    for(string x : ans)
        cout << x << '\n';
    return 0;
}