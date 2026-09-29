#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_V = 100000;
const int INF = 1e14;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, W; cin >> n >> W;
    vector<int> w(n), v(n);
    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<int> dp(MAX_V + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = MAX_V; j >= v[i]; j--) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    
    for(int i = MAX_V; i >= 0; i--)
    {
        if(dp[i] <= W)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}