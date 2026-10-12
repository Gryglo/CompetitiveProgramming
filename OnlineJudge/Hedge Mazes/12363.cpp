#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;
int n, m, q;
vector<vector<int>> adj;
vector<int> depth;
vector<int> low;
vector<pii> p_bridge;
vector<int> SCC;
int cnt_SCC = 0;
void DFS(int v, int p)
{
    depth[v] = depth[p] + 1;
    low[v] = depth[v];
    SCC[v] = cnt_SCC;
    for(int u : adj[v])
    {
        if(u == p) continue;
        if(depth[u] != -1) low[v] = min(low[v], depth[u]);
        else
        {
            DFS(u, v);
            low[v] = min(low[v], low[u]);
        }
    }
    p_bridge[v].f = p;
    if(low[v] < depth[v]) p_bridge[v].s = false;
}

bool valid_path(int a, int b)
{
    if(SCC[a] != SCC[b]) return false;
    if(depth[a] < depth[b]) swap(a, b);

    while(depth[a] > depth[b])
    {
        if(!p_bridge[a].s) return false;
        a = p_bridge[a].f;
    }
    while(a != b)
    {
        if(!p_bridge[a].s) return false;
        if(!p_bridge[b].s) return false;
        a = p_bridge[a].f;
        b = p_bridge[b].f;
    }
    return true;
}

bool init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    if(n == 0 && m == 0 && q == 0) return false;
    adj.assign(n, vector<int>());
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    return true;
}

int32_t main()
{
    while(init()) 
    {
        depth.assign(n, -1);
        low.assign(n, INF);
        p_bridge.assign(n, {-1, true});
        SCC.assign(n, -1);
        for(int v = 0; v < n; v++)
        {
            if(depth[v] == -1) 
            {
                DFS(v, v);
                cnt_SCC++;
            }
        }
        while(q--)
        {
            int a, b; cin >> a >> b; a--; b--;
            cout << (valid_path(a, b) ? "Y" : "N") << '\n';
        }
        cout << "-\n";
    }
    return 0;
}