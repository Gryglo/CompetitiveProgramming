#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
#define f first
#define s second

int n, m;
vector<vector<pii>> adj;
vector<vector<pii>> t;

void MST()
{
    t.resize(n);
    //waga, v
    priority_queue<piii> pq;
    vector<bool> visited(n);
    visited[0] = true;
    for(pii e : adj[0])
        pq.push({-e.s, {e.f, 0}});

    while(!pq.empty())
    {
        piii curr = pq.top();
        pq.pop();
        if(visited[curr.s.f]) continue;
        visited[curr.s.f] = true;
        t[curr.s.s].push_back({curr.s.f, -curr.f});
        for(pii e : adj[curr.s.f])
        {
            if(visited[e.f]) continue;
            pq.push({-e.s, {e.f, curr.s.f}});
        }
    }
}

vector<vector<int>> up; //up[v][0...1]
vector<vector<int>> max_up; 
vector<int> depth;
const int MAXLOG = 20;
void DFS(int v, int d, int p, int w)
{
    depth[v] = d;
    up[v][0] = p;
    max_up[v][0] = w;
    for(int i = 1; i <= MAXLOG; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
        max_up[v][i] = 
        max(max_up[v][i - 1], max_up[up[v][i - 1]][i - 1]);
    }
    for(pii e : t[v])
        DFS(e.f, d + 1, v, e.s);
}

void compute_LCA()
{
    depth.resize(n);
    up.resize(n, vector<int>(MAXLOG + 1));
    max_up.resize(n, vector<int>(MAXLOG + 1));
    DFS(0, 0, 0, 0);
}

int LCA(int a, int b)
{
    if(depth[a] > depth[b])
        swap(a, b);
    //depth[b] > depth[a]
    int maxW = 0;
    for(int i = MAXLOG; i >= 0; i--)
        if(depth[up[b][i]] >= depth[a])
        {
            maxW = max(maxW, max_up[b][i]);
            b = up[b][i];
        }
    if(a == b)
        return maxW;
    for(int i = MAXLOG; i >= 0; i--)
    {
        if(up[a][i] != up[b][i])
        {
            maxW = max(maxW, max_up[a][i]);
            maxW = max(maxW, max_up[b][i]);
            a = up[a][i];
            b = up[b][i];
        }
    }
    maxW = max(maxW, max(max_up[a][0], max_up[b][0]));
    return maxW;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c; 
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    MST();
    compute_LCA();
    int q; cin >> q;
    while(q--)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        cout << LCA(a, b) << '\n';
    }
    return 0;
}