#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, N;
vector<vector<int>> a;

int add_cost(int i, int mask)
{
    int res = 0;
    for(int j = 0; j < n; j++)
        if((mask & (1 << j)) > 0) 
            res += a[i][j];
    return res;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    N = 1 << n;
    a.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}

int32_t main()
{
    init();
    vector<int> gsum(N);
    vector<int> dp(N);
    for(int mask = 1; mask < N; mask++)
    {
        int temp = mask;
        int bit_i = -1;
        while(temp > 0) { bit_i++; temp /= 2; }
        int prev_mask = mask ^ (1 << bit_i);
        dp[mask] = max(dp[mask], dp[prev_mask]);
        for(int sub = prev_mask; sub > 0; sub = (sub - 1) & prev_mask)
        {
            // 0 0 0 1 1 1 0 1 1 0
            // 0 0 0 0 1 1 0 1 0 0
            int cost = add_cost(bit_i, sub);
            gsum[sub | (1 << bit_i)] = gsum[sub] + cost;
            int rest_mask = prev_mask ^ sub;
            dp[mask] = max(dp[mask], gsum[sub | (1 << bit_i)] + dp[rest_mask]);
        }
    }
    cout << dp[N - 1] << '\n';
    return 0;
}