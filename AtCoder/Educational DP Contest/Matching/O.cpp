#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int MOD = 1e9 + 7;
int n;
vector<vector<int>> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}

int32_t main()
{
    init();
    int N = (1 << n);
    vector<int> dp(N);
    dp[0] = 1;
    for(int mask = 1; mask < N; mask++)
    {
        int i = __builtin_popcount(mask) - 1;
        for(int j = 0; j < n; j++)
        {
            if((mask & (1 << j)) == 0) continue;
            if(a[i][j] == 0) continue;
            int prev_mask = mask ^ (1 << j);
            dp[mask] = (dp[mask] + dp[prev_mask]) % MOD; 
        }
    }
    cout << dp[N - 1];
    return 0;
}