#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int n, k;
vector<int> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}

int32_t main()
{
    init();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for(int i = 0; i <= k; i++) dp[0][i] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            if(j - a[i - 1] > 0) dp[i][j] = (dp[i][j] + MOD - dp[i - 1][j - a[i - 1] - 1]) % MOD;
        }
    }
    if(k == 0) cout << dp[n][0];
    else cout << ((dp[n][k] + MOD - dp[n][k - 1]) % MOD);
    return 0;
}

//dp[i - 1][j - 0, j - a[i]]
// j j - 1 j - 2 a[i] + 1
// a[i] = 7
// j = 5
// 5 4 3 2 1 0
// j - max(0, j - a[i])
//j = 10
// a[i] = 4
// 10 9 8 7 6
// 0  1 2 3 4
// 5 4 3 2 1
// 0 1 2 3 4
/*
new_dp[i][j] = dp[i][0] + dp[i][1] + ... + dp[i][j - 1] + dp[i][j]
for(int x = 0; x <= min(j, a[i - 1]); x++)
{
    dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
}
*/
//sumy prefiksowe