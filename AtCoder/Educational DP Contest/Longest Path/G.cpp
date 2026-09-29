#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> dp;
vector<bool> vis;
void DFS(int v)
{       
    vis[v] = true;
    for(int u : adj[v])
    {
        if(!vis[u]) DFS(u);
        dp[v] = max(dp[v], dp[u] + 1);
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    dp.resize(n);
    vis.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }
}

int32_t main()
{
    init();
    int ans = 0;
    for(int v = 0; v < n; v++)
    {
        if(vis[v]) continue;
        DFS(v);
        ans = max(ans, dp[v]);
    }
    cout << ans; 
    return 0;
}