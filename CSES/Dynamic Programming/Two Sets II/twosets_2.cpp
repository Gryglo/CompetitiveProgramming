#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long double MOD = 1e9 + 7;

int main()
{
    ll n; cin >> n;
    ll x = ((1 + n) * n) / 2;
    if(x % 2 == 1) { cout << 0; return 0; }
    x/=2;
    vector<long double> dp(x + 5);
    dp[0] = 0.5;
    for(ll i = 1; i <= n; i++) {
        for(ll j = x; j >= i; j--) {
            dp[j] = fmod(dp[j] + dp[j - i], MOD);
        }
    }
    cout << fixed << setprecision(0) << dp[x];
}