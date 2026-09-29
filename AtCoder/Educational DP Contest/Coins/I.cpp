#include <bits/stdc++.h>
using namespace std;
using ld = long double;
ld n;
vector<ld> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}
int main()
{
    init();
    vector<vector<ld>> dp(n, vector<ld>(n + 1));
    dp[0][0] = (ld)1 - a[0];
    dp[0][1] = a[0];
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] * ((ld)1 - a[i]);
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * a[i] 
            + dp[i - 1][j] * ((ld)1 - a[i]);
        }
    }
    ld ans = 0;
    int m = ceil(n / 2);
    for(int i = m; i <= n; i++) ans += dp[n - 1][i];
    cout << fixed << setprecision(10) << ans;
    return 0;
}