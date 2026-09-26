#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge
{
    int u, idx, a, b;
};

int n, m;
vector<vector<Edge>> adj;

vector<bool> vis;
vector<int> depth;
vector<int> low;
vector<int> v_in, v_out;
vector<bool> bridge;

vector<bool> dir_e;
vector<int> vis_e;
int ans = 0;
void DFS(int v, int p, int e_idx)
{
    vis[v] = true;
    depth[v] = depth[p] + 1;
    low[v] = depth[v];
    for(Edge e : adj[v])
    {
        int u = e.u;
        if(e.idx == e_idx) continue;
        if(vis[u]) 
        {
            low[v] = min(low[v], depth[u]);
            if(e.b == u) dir_e[e.idx] = true;
            else dir_e[e.idx] = false;
        }
        else
        {
            DFS(u, v, e.idx);
            if(e.b == u) dir_e[e.idx] = false;
            else dir_e[e.idx] = true;
            if(low[u] > depth[v]) ans++;
            low[v] = min(low[v], low[u]); 
        } 
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n);
    low.resize(n);
    depth.resize(n);
    bridge.resize(n);

    vis_e.resize(m);
    dir_e.resize(m);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back({b, i, a, b});
        adj[b].push_back({a, i, a, b});
    }
}
int32_t main()
{
    init();
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            ans++;
            DFS(i, i, -1);
        } 
            
    }
    cout << ans << '\n';
    for(int i = 0; i < m; i++)
    {
        if(dir_e[i]) cout << '<';
        else cout << '>';
    }
    return 0;
}