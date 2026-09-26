#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;
vector<vector<int>> adj_SCC;
vector<int> SCC_i;
vector<int> SCC_size;

void DFS(int v, vector<vector<int>>& g, vector<bool>& vis, vector<int>& output)
{
    vis[v] = true;
    for(int u : g[v])
    {
        if(vis[u]) continue;
        DFS(u, g, vis, output);
    }
    output.push_back(v);
}

void topo_sort(vector<vector<int>>& g, vector<int>& order)
{
    vector<bool> vis(g.size());
    for(int i = 0; i < g.size(); i++) if(!vis[i]) DFS(i, g, vis, order);
    reverse(order.begin(), order.end());
}

void SCC()
{
    SCC_i.resize(n);
    vector<int> order;
    topo_sort(adj, order);
    vector<bool> vis(n);
    for(int v : order)
    {
        if(vis[v]) continue;
        vector<int> component;
        DFS(v, adj_rev, vis, component);
        for(int u : component) SCC_i[u] = adj_SCC.size();
        adj_SCC.push_back(vector<int>());
        SCC_size.push_back(component.size());
    }

    for(int v = 0; v < n; v++)
        for(int u : adj[v])
            if(SCC_i[v] != SCC_i[u]) adj_SCC[SCC_i[v]].push_back(SCC_i[u]);

}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    adj_rev.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
}
int32_t main()
{
    init();
    SCC();
    vector<int> dp(adj_SCC.size());
    vector<int> SCC_order;
    topo_sort(adj_SCC, SCC_order);
    reverse(SCC_order.begin(), SCC_order.end());
    for(int v : SCC_order)
    {
        dp[v] = SCC_size[v];
        for(int u : adj_SCC[v]) dp[v] += dp[u]; 
    }
    for(int i = 0; i < n; i++) cout << dp[SCC_i[i]] - 1 << '\n';
    return 0;
}