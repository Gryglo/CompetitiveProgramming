#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e14;
void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> cold(k + 1), hot(k + 1);
    for(int i = 1; i <= k; i++) cin >> cold[i];
    for(int i = 1; i <= k; i++) cin >> hot[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, INF)));
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    for(int i = 1; i <= n; i++)
    {    
        for(int j = 0; j <= k; j++)
        {
            dp[i][0][j] = min(dp[i][0][j], dp[i - 1][0][j] + (a[i - 1] == a[i] ? hot[a[i]] : cold[a[i]]));
            dp[i][1][j] = min(dp[i][1][j], dp[i - 1][1][j] + (a[i - 1] == a[i] ? hot[a[i]] : cold[a[i]]));
            //    j     a[i - 1]
            //    a[i]  a[i - 1]
            dp[i][0][a[i - 1]] = min(dp[i][0][a[i - 1]], dp[i - 1][1][j] + (j == a[i] ? hot[a[i]] : cold[a[i]]));
            //    a[i - 1] j
            //    a[i - 1] a[i]                         
            dp[i][1][a[i - 1]] = min(dp[i][1][a[i - 1]], dp[i - 1][0][j] + (j == a[i] ? hot[a[i]] : cold[a[i]]));
        }
    }
    int ans = INF;
    for(int i = 0; i <= k; i++)
    {
        ans = min(ans, dp[n][0][i]);
        ans = min(ans, dp[n][1][i]);
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}