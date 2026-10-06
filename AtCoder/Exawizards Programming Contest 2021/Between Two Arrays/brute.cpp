#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXV = 3000;
const int MOD = 998244353;
int n;
vector<int> a, b;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n); b.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
}

int32_t main()
{
    init();
    vector<vector<int>> dp(n + 1, vector<int>(MAXV + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i - 1]; j <= b[i - 1]; j++)
        {
            for(int k = j; k >= 0; k--)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= b[n - 1]; i++)
    {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans;
    return 0;
}