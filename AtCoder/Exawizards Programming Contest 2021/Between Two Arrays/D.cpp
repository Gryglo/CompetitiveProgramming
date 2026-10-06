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
    for(int i = 0; i <= MAXV; i++) dp[0][i] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i - 1]; j <= b[i - 1]; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
        for(int j = b[i - 1] + 1; j <= MAXV; j++)
        {
            if(j > 0) dp[i][j] = dp[i][j - 1];
        }
    }
    cout << dp[n][b[n - 1]];
    return 0;
}