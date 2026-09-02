#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int main()
{
    ll n, m; cin >> n >> m;
    vector<ll> input(n);
    for(int i = 0; i < n; i++) cin >> input[i];
    vector<ll> dp;
    if(input[0] == 0) { dp.resize(m + 2, 1); dp[0] = 0; dp[m + 1] = 0; }
    else { dp.resize(m + 2); dp[input[0]] = 1; }

    for(int i = 1; i < n; i++)
    {
        vector<ll> curr_dp(m + 2);
        if(input[i] == 0)
            for(int j = 1; j <= m; j++) 
                curr_dp[j] = (dp[j - 1] + dp[j] + dp[j + 1]) % MOD;
        else curr_dp[input[i]] = (dp[input[i] - 1] + dp[input[i]] + dp[input[i] + 1]) % MOD;
        dp = curr_dp;
    }
    ll ans = 0;
    for(int j = 1; j <= m; j++) ans = (ans + dp[j]) % MOD;
    cout << ans;
    return 0;
}