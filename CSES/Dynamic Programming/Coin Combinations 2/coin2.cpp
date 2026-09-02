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
    for(int coin : coins)
        for(int i = 0; i < x; i++)
            if(i + coin <= x)
                dp[i + coin] = (dp[i + coin] + dp[i]) % MOD;
    cout << dp[x];
    return 0;
}