#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
const int MAX_A = 1002;
vector<int> dp_w(MAX_A + 1, INF);
void compute_min_weights()
{
    dp_w[1] = 0;
    for(int i = 1; i <= MAX_A; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            int next = i + i/j;
            if(next > MAX_A) continue;
            dp_w[next] = min(dp_w[next], dp_w[i] + 1);
        }
    }
}

void solve()
{
    int n, k; 
    cin >> n >> k;
    vector<int> a(n), c(n), w(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    int all_cost = 0;
    for(int i = 0; i < n; i++) 
    {
        w[i] = dp_w[a[i]];
        all_cost += w[i];
    }
    if(all_cost <= k)
    {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += c[i];
        cout << sum <<'\n';
        return;
    }
    //max_w = 12
    vector<int> dp(k + 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = k; j >= w[i]; j--)
        {
            if(j > 0) dp[j] = max(dp[j], dp[j - 1]);
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    cout << dp[k] << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    compute_min_weights();
    int q; cin >> q;
    while(q--) solve();
    return 0;
}