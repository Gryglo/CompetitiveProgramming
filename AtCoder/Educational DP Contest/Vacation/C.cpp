#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) ans = max(ans, dp[n - 1][i]);
    cout << ans;
    return 0;
}