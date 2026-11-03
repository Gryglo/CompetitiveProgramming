#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int n;
vector<vector<int>> adj;
vector<vector<int>> dp;
void DFS_DP(int v, int p)
{
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS_DP(u, v);
        dp[0][v] = (dp[0][v] * (dp[0][u] + dp[1][u])) % MOD;
        dp[1][v] = (dp[1][v] * dp[0][u]) % MOD;
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    dp.resize(2, vector<int>(n, 1));
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int32_t main()
{
    init();
    DFS_DP(0, -1);
    int ans = (dp[0][0] + dp[1][0]) % MOD;
    cout << ans << '\n';
    return 0;
}