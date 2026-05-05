#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;
vector<int> SCC_root;
vector<vector<int>> SCC_graph;
vector<vector<int>> SCC_graph_rev;
vector<vector<int>> components;
int SCC_size = 0;

void init()
{
    adj.resize(n);
    adj_rev.resize(n);
    SCC_root.resize(n);
}

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
    for(int v = 0; v < g.size(); v++)
        if(!vis[v])
            DFS(v, g, vis, order);
    reverse(order.begin(), order.end());
}

void SCC()
{
    vector<int> order;
    topo_sort(adj, order);
    vector<bool> vis(n);
    for(int v : order)
    {
        if(vis[v]) continue;
        vector<int> component;
        DFS(v, adj_rev, vis, component);
        for(int u : component)
            SCC_root[u] = SCC_size;
        components.push_back(component);
        SCC_size++;
    }
    SCC_graph.resize(SCC_size);
    for(int v = 0; v < n; v++)
        for(int u : adj[v])
            if(SCC_root[v] != SCC_root[u])
                SCC_graph[SCC_root[v]].push_back(SCC_root[u]);
}

void find_candidates(vector<vector<int>>& g, vector<int>& order, vector<bool>& candidates)
{
    vector<int> order_idx(SCC_size);
    for(int i = 0; i < order.size(); i++)
        order_idx[order[i]] = i;
    vector<int> r(SCC_size, SCC_size);
    for(int v : order)
        for(int u : g[v])
            r[v] = min(r[v], order_idx[u]);
    candidates.resize(SCC_size, true);
    int lastR = 0;
    for(int i = 0; i < order.size(); i++)
    {
        if(i < lastR)
            candidates[order[i]] = false;
        lastR = max(lastR, r[order[i]]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    SCC();
    vector<int> order;
    topo_sort(SCC_graph, order);
    vector<bool> candidates1;
    find_candidates(SCC_graph, order, candidates1);

    reverse(order.begin(), order.end());
    SCC_graph_rev.resize(SCC_size);
    for(int v = 0; v < SCC_size; v++)
        for(int u : SCC_graph[v])
            SCC_graph_rev[u].push_back(v);
    vector<bool> candidates2;
    find_candidates(SCC_graph_rev, order, candidates2);
    
    vector<int> ans;
    for(int v = 0; v < SCC_size; v++)
        if(candidates1[v] && candidates2[v])
            for(int u : components[v])
                ans.push_back(u);
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int v : ans)
        cout << v + 1 << ' ';
    return 0;
}