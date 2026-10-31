#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXX = 50 * 1e8 + 10;
//const int MAXX = 1e6 + 10;
void solve()
{
    int m, x;
    cin >> m >> x;
    vector<int> cost(m);
    vector<int> val(m);
    for(int i = 0; i < m; i++)
        cin >> cost[i] >> val[i];
    vector<int> dp(MAXX + 1);
    for(int i = 0; i < m; i++)
    {
        for(int j = x * i; (j - cost[i]) >= 0; j--)
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
        for(int j = x * i + 1; j <= MAXX; j++)
        {
            dp[j] = dp[j - 1];
        }
    }
    cout << dp[MAXX] << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}