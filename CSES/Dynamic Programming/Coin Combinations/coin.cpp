#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main()
{
    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for(ll i = 0; i < n; i++) cin >> coins[i];

    vector<ll> dp(x + 5);
    dp[0] = 1;
    for(ll i = 1; i <= x; i++)
        for(ll coin : coins)
            if(i - coin >= 0) dp[i] = (dp[i] + dp[i - coin]) % MOD;
    cout << dp[x];
    return 0;
}