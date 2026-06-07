#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<pii> tout;
void DFS(int v)
{
    vis[v] = true;
    for(int u : adj[v])
    {

    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    tout.resize(n);
    for(int i = 0; i < n; i++)
        tout[i].s = i;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        tout[a].f++;
        tout[b].f++;
    }
    sort(tout.begin(), tout.end());
    for(int i = 0; i < tout.size(); i++)
    {
        //mozliwe starty
        DFS();
    }
    
    return 0;
}