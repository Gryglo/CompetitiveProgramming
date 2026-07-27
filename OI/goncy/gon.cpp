#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> path;
vector<bool> path_added;
vector<int> first_p, second_p;
int next_v = -1;
int next_v_p = -1;

void update_next_v()
{
    for(int u = 0; u < n; u++)
        if(path_added[u]) 
            for(int v : adj[u])
                if(!path_added[v]) { next_v = v; next_v_p = u; return; }
}

void DFS(int v, int p, bool& on_path, vector<bool>& vis)
{
    vis[v] = true;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(u == p || vis[u]) continue;
        if(path_added[u]) { on_path = true; return; }
        DFS(u, v, on_path, vis);
        if(on_path) { path[v].push_back(u); path_added[u] = true; return; }
    }
}

void add_to_path()
{
    bool on_path = false;
    vector<bool> vis(n, false);
    path[next_v_p].push_back(next_v);
    path_added[next_v] = true;
    DFS(next_v, next_v_p, on_path, vis);
    update_next_v();
}

void follow_path(int v, vector<bool>& vis)
{
    vis[v] = true;
    first_p.push_back(v);
    for(int i = path[v].size() - 1; i >= 0; i--)
    {
        int u = path[v][i];
        if(vis[u]) continue;
        follow_path(u, vis);
    }
}

void make_paths()
{
    vector<bool> vis(n, false);
    follow_path(0, vis);
    second_p.push_back(0);
    for(int i = first_p.size() - 1; i >= 1; i--) second_p.push_back(first_p[i]);
}

void print_ans()
{
    for(int i = 0; i < first_p.size(); i++)
        cout << first_p[i] + 1 << ((i < first_p.size() - 1) ? " " : "");
    cout << endl;
    for(int i = 0; i < second_p.size(); i++)
        cout << second_p[i] + 1 << ((i < second_p.size() - 1) ? " " : "");
    cout << endl;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    path.resize(n);
    path_added.resize(n);
    next_v = adj[0][0];
    next_v_p = 0;
    path_added[0] = true;
}
int main()
{
    init();
    while(!path_added[next_v]) add_to_path();
    make_paths();
    print_ans();
    return 0;
}