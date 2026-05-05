#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;
const int MAXN = 100005;
const ll MOD = 1001;
ll n;
ll d, a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> a >> b;
    if(a > b) swap(a, b); //a < b
    
    vector<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = (a + b) % MOD;
    for(int i = 3; i <= n; i++)
    {
        //i/2 - max d = 1
        ll ans = INF;
        for(int x = 1; x < i; x++)
        {
            int second = i - x;
            if(abs(second - x) > d) continue;
            //3 - 1 = 2
            //1
            ll val = (x * a + second * b) % MOD;
            ans = min(ans, val + dp[x] + dp[second]);
        }
        dp[i] = ans;
    }
    cout << dp[n];
    return 0;
}