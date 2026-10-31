#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e13;
int n;
vector<int> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}
int32_t main()
{
    init();
    vector<vector<int>> dp(n, vector<int>(n, INF));
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    for(int i = 0; i < n; i++)
        dp[i][i] = 0;
    for(int d = 2; d <= n; d++)
    {
        for(int l = 0; l + d - 1 < n; l++)
        {
            int r = l + d - 1;
            for(int j = l; j < r; j++) 
                dp[l][r] = min(dp[l][r], dp[l][j] + dp[j + 1][r] + (pref[r + 1] - pref[l]));
        }
    }
    cout << dp[0][n - 1];
    return 0;
}