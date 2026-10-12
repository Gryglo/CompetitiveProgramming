#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<bool> dp(n + 1);
    dp[0] = true;
    for(int i = 1; i <= n; i++)
    {
        if(i - (a[i] + 1) >= 0)
            if(dp[i - (a[i] + 1)]) 
                dp[i] = true;
        if(i + a[i] <= n)
            if(dp[i - 1]) dp[i + a[i]] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}