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
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(k + 1, INF)));
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        /*
        x
              1  2
        dp[i][x][y] = dp[i - 1][1...k][y]
        
              1  2
        dp[i][y][x] = dp[i - 1][y][1...k]
        */

        for(int j = 0; j <= k; j++)
        {
            for(int y = 0; y <= k; y++)
            {
                dp[i][a[i]][j] = min(dp[i][a[i]][j], dp[i - 1][y][j] + (y == a[i] ? hot[a[i]] : cold[a[i]]));
            }
        }

        for(int j = 0; j <= k; j++)
        {
            for(int y = 0; y <= k; y++)
            {
                dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j][y] + (y == a[i] ? hot[a[i]] : cold[a[i]]));
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= k; i++)
    {
        ans = min(ans, dp[n][a[n]][i]);
        ans = min(ans, dp[n][i][a[n]]);
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