#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;

int cost_move(int a, int i, int j, vector<int>& x)
{
    int res = a * (x[j] - x[i]);
    return res;
}

int cost_fight(int b, int i, int j, vector<int>& x, vector<int>& pref)
{
    int res = b * ((pref[j] - pref[i]) - (j - i) * x[i]);
    return res;
}

void solve()
{
    int n, a, b; cin >> n >> a >> b;
    vector<int> x(n + 1);
    for(int i = 1; i <= n; i++) cin >> x[i];
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + x[i];
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i - 1; j >= 0; j--) 
            dp[i] = min(dp[i], dp[j] + cost_fight(b, j, i, x, pref) + cost_move(a, j, i, x));
    int ans = INF;
    for(int i = 0; i <= n; i++) ans = min(ans, dp[i] + cost_fight(b, i, n, x, pref));
    cout << ans << '\n';
}
int32_t main()
{
    int q; cin >> q;
    while(q--) solve();
    return 0;
}

/*


1
5 6 3
1 5 6 21 30

*/