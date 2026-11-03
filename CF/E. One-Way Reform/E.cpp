#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<bool>> vis;
vector<vector<int>> adj;
vector<vector<int>> adj_dir;
vector<bool> added;
void euler_tour(int v, int n)
{
    added[v] = true;
    while(adj[v].size() > 0)
    {
        int u = adj[v].back();
        adj[v].pop_back();
        if(vis[v][u] || vis[u][v]) continue;
        vis[v][u] = true; vis[u][v] = true;
        euler_tour(u, n);
        if(v != n && u != n)
            adj_dir[v].push_back(u);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    adj_dir.assign(n + 1, vector<int>());
    vis.assign(n + 1, vector<bool>(n + 1));
    added.assign(n + 1, false);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(adj[i].size() % 2 != 0)
        {
            adj[i].push_back(n);
            adj[n].push_back(i);
        }
        else ans++;
    }
    euler_tour(n, n);
    for(int i = 0; i < n; i++)
        if(!added[i]) euler_tour(i, n);
    cout << ans << '\n';
    for(int i = 0; i < n; i++)
        for(int u : adj_dir[i]) 
            cout << i + 1 << ' ' << u + 1 << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}