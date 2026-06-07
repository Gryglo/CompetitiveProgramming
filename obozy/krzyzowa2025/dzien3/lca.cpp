#include <bits/stdc++.h>
using namespace std;

const int MAXLOG = 20;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

void DFS(int v, int p)
{
    up[v][0] = p;
    for(int i = 1; i <= MAXLOG; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for(int u : adj[v])
    {
        if(u == p)
            continue;
        depth[u] = depth[v] + 1;
        DFS(u, v);
    }
}


int lca(int v, int u)
{
    //wyrownaj v do u
    if(depth[v] < depth[u])
        swap(v, u);

    if(u == v)
        return u;

    for(int i = MAXLOG; i >= 0; i--)
    {
        if(depth[up[v][i]] < depth[u])
            continue;
        v = up[v][i];
    }

    if(u == v)
        return u;

    //sa na tych samych wysokosciach wiec skaczemy razem
    for(int i = MAXLOG; i >= 0; i--)
    {
        if(up[v][i] == up[u][i])
            continue;
        v = up[v][i];
        u = up[u][i];
    }

    return up[v][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    up.resize(n, vector<int>(MAXLOG + 1));
    depth.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> m;

    vector<int> visitOrder(m);
    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;
        visitOrder[i] = a;
    }

    DFS(0, 0);

    int result = 0;
    int lastV = 0;
    for(int i = 0; i < m; i++)
    {
        int currV = visitOrder[i];
        int common = lca(currV, lastV);
        result += (depth[currV] - depth[common]);
        result += (depth[lastV] - depth[common]);
        lastV = currV;
    }
    cout << result;
    return 0;
}