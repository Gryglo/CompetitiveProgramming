#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;

void DFS(int v, vector<vector<int>>& g, vector<bool>& vis)
{
    vis[v] = true;
    for(int u : g[v])
    {
        if(vis[u]) continue;
        DFS(u, g, vis);
    }
}

void init()
{
    adj.resize(n);
    adj_rev.resize(n);
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
    
    vector<int> ans;
    for(int v = 0; v < n; v++)
    {
        vector<bool> vis1(n);
        DFS(v, adj, vis1);
        vector<bool> vis2(n);
        DFS(v, adj_rev, vis2);
        bool valid = true;
        for(int u = 0; u < n; u++)
        {
            if(!vis1[u] && !vis2[u])
            {
                valid = false;
                break;
            }
        }
        if(valid)
            ans.push_back(v);
    }
    cout << ans.size() << '\n';
    for(int v : ans)
        cout << v + 1 << ' ';
    return 0;
}