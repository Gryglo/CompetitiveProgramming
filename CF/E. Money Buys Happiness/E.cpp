#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e10;
void solve()
{
    int m, x;
    cin >> m >> x;
    vector<int> cost(m);
    vector<int> val(m);
    for(int i = 0; i < m; i++)
        cin >> cost[i] >> val[i];
    int MAXH = 0;
    for(int i = 0; i < m; i++) MAXH += val[i];
    vector<int> dp(MAXH + 10, INF);
    dp[0] = 0;
    for(int i = 0; i < m; i++)
    {
        int curr_money = i * x;
        for(int j = MAXH; j - val[i] >= 0; j--)
        {
            if(dp[j - val[i]] + cost[i] <= curr_money)
                dp[j] = min(dp[j], dp[j - val[i]] + cost[i]);
        }
    }
    for(int i = MAXH; i >= 0; i--)
    {
        if(dp[i] <= x * (m - 1))
        {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}