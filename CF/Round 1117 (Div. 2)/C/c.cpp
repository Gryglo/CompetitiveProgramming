#include <bits/stdc++.h>
using namespace std;


void DFS(int v, int d, vector<vector<int>>& adj, vector<int>& depth)
{
    depth[v] = d;
    for(int u : adj[v]) DFS(u, d + 1, adj, depth);
}

void solve()
{
    int n, m;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> p(n);
    for(int i = 1; i < n; i++)
    {
        cin >> p[i]; p[i]--;
        adj[p[i]].push_back(i);
    }
    vector<int> depth(n);
    DFS(0, 0, adj, depth);
    cin >> m;
    vector<pair<int, int>> ans;
    for(int i = 0; i < m; i++)
    {
        int a; cin >> a; a--;
        ans.push_back({depth[a], a});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() - 1 << ' ';
    for(int i = 1; i < ans.size(); i++)
        cout << ans[i].second + 1 << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}