#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int MAXV = 100 + 5;
void solve()
{
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++)
    {
        string line;
        getline(cin >> ws, line);
        stringstream ss(line);
        int x;
        while(ss >> x) a[i].push_back(x);
    }
    vector<vector<int>> dp(n, vector<int>(MAXV + 1, 0));
    dp[0].assign(MAXV + 1, -1);
    for(int x : a[0])
        dp[0][x] = (a[0].size() - 1);
    for(int i = 0; i <= MAXV; i++)
        if(dp[0][i] == -1) dp[0][i] = a[0].size();
    for(int i = 1; i < n; i++)
    {
        for(int x : a[i])
        {
            for(int j = 0; j <= MAXV; j++)
            {
                if(j == x) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }
    int ans = 0;
    for(int x : a[n - 1]) ans = (ans + dp[n - 1][x]) % MOD;
    cout << ans << '\n';
}
int32_t main()
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}