#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1'000'000;
const ll MOD = 1e9 + 7;

void mod_add(ll& a, ll b) { a = (a + b) % MOD; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //dp[2][n]
    vector<vector<ll>> dp(2, vector<ll>(MAXN + 1));
    // 0 -> bez lini
    // 1 -> z linia
    dp[0][0] = 1; dp[1][0] = 1;
    for(int i = 1; i <= MAXN; i++)
    {
        mod_add(dp[0][i], dp[0][i - 1]);
        mod_add(dp[0][i], dp[1][i - 1]);
        mod_add(dp[0][i], dp[0][i - 1]);
        mod_add(dp[1][i], dp[0][i - 1]);
        mod_add(dp[1][i], dp[1][i - 1]);
        mod_add(dp[1][i], dp[1][i - 1]);
        mod_add(dp[1][i], dp[1][i - 1]);
        mod_add(dp[1][i], dp[1][i - 1]);
    }
    
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        cout << ((dp[0][x - 1] + dp[1][x - 1]) % MOD) << '\n';
    }
    return 0;
}