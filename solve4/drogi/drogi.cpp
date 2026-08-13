#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int n, m;
vector<vector<int>> adj;
vector<int> depth;
vector<int> min_d;

int DFS(int v, int p)
{
    depth[v] = depth[p] + 1; min_d[v] = depth[v];
    int cntB = 0;
    for(int u : adj[v])
    {
        if(u == p) continue;
        if(depth[u] != -1) { min_d[v] = min(min_d[v], depth[u]); continue; }
        cntB += DFS(u, v); 
        min_d[v] = min(min_d[v], min_d[u]);
    }
    if(min_d[v] > depth[p] && cntB == 0) return 1;
    return cntB;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    depth.resize(n, -1);
    min_d.resize(n, INF);
    depth[0] = 0;
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
    int ans = DFS(0, 0);
    cout << (ans / 2 + (ans % 2));
    return 0;
}