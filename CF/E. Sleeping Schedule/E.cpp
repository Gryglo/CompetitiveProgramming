#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, h, l, r;
vector<int> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h >> l >> r;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) a[i]--;
}
int32_t main()
{
    init();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i - 1];
        for(int x = 0; x <= i; x++)
        {
            dp[i][x] = dp[i - 1][x];
            if(x > 0) dp[i][x] = max(dp[i][x], dp[i - 1][x - 1]);
            int curr_h = (sum + x) % h;
            if(l <= curr_h && curr_h <= r) dp[i][x]++;
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) ans = max(ans, dp[n][i]);
    cout << ans;
    return 0;
}