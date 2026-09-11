#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n + 2);
    for(int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1] + 1;
        if(i + a[i] + 1 <= n) dp[i] = min(dp[i], dp[i + a[i] + 1]);
    }
    cout << dp[0] << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}