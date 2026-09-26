#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<bool> is_blocked;
vector<int> c_blocked;
vector<vector<int>> adj;
vector<int> parent;

void DFS(int v, int p)
{
    parent[v] = p;
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS(u, v);
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    is_blocked.resize(n);
    c_blocked.resize(n);
    parent.resize(n);
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
    int ans = 1;
    int q; cin >> q;
    while(q--)
    {
        int v; cin >> v;
        if(v > 0)
        {
            v--;
            if(parent[v] != -1)
            {
                c_blocked[parent[v]]++;
                ans += ((adj[v].size() - 1) - c_blocked[v]) + (!is_blocked[parent[v]]) - 1;
            } 
            else ans += adj[v].size() - c_blocked[v] - 1;
            is_blocked[v] = true;
        }
        else
        {
            v = -v; v--;
            if(parent[v] != -1)
            {
                c_blocked[parent[v]]--;
                ans -= (adj[v].size() - 1 - c_blocked[v] + (!is_blocked[parent[v]])) - 1;
            } 
            else ans -= (adj[v].size() - c_blocked[v]) - 1;
            is_blocked[v] = false;
        }   
        cout << ans << '\n';
    }
    return 0;
}