#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;

void DFS(int v, vector<int>& vert)
{
    // 2 sasiadow wszyscy na cyklu
    vis[v] = true;
    vert.push_back(v);
    for(int u : adj[v]) if(!vis[u]) DFS(u, vert);
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main()
{
    init();
    int ans = 0;
    for(int v = 0; v < n; v++)
    {
        if(!vis[v]) 
        {
            vector<int> curr; DFS(v, curr);
            bool valid = true;
            for(int c : curr)
                if(adj[c].size() != 2) { valid = false; break; }
            ans += valid;
        }
    }   
    cout << ans;
    return 0;
}