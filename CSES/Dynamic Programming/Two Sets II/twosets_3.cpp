#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MOD = 1e9 + 7;
 
int main()
{
    ll n; cin >> n;
    ll x = ((1 + n) * n) / 2;
    if(x % 2 == 1) { cout << 0; return 0; }
    x/=2;
    vector<ll> dp(x + 5);
    dp[0] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = x; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    cout << ((dp[x] % 2 == 0) ? (dp[x] / 2) : ((dp[x] + MOD) / 2));
}