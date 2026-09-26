#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int>> adj;
vector<set<int>> colors;
vector<int> ans;
void merge(int v, int u)
{
    if(colors[v].size() < colors[u].size()) swap(colors[v], colors[u]);
    for(int x : colors[u]) colors[v].insert(x);
    colors[u].clear();
}
void DFS(int v, int p)
{
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS(u, v);
        merge(v, u);
    }
    ans[v] = colors[v].size();
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    ans.resize(n);
    colors.resize(n);
    for(int i = 0; i < n; i++) 
    {
        int x; cin >> x;
        colors[i].insert(x);
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
int32_t main()
{
    init();
    DFS(0, -1);
    for(int x : ans) cout << x << ' ';
    return 0;
}