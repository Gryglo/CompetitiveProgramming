#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, W; cin >> n >> W;
    vector<int> w(n), v(n);
    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<int> dp(W + 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = W; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W];
    return 0;
}