#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXLOG = 20;

int n, k;
vector<vector<int>> adj;

vector<vector<int>> up;
vector<int> parent;
vector<int> depth;
void computeLCA(int v, int d, int p)
{
    parent[v] = p;
    depth[v] = d;
    up[v][0] = p;
    for(int i = 1; i <= MAXLOG; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for(int u : adj[v])
    {
        if(u == p) continue;
        computeLCA(u, d + 1, v);
    }
}

int LCA(int a, int b)
{
    if(depth[a] != depth[b])
    {
        if(depth[a] < depth[b]) swap(a, b); // d[a] >
        for(int i = MAXLOG; i >= 0; i--)
            if(depth[up[a][i]] >= depth[b])
                a = up[a][i];
    }
    if(a == b) return a;

    for(int i = MAXLOG; i >= 0; i--)
    {
        if(up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
ll maxx = 0;
vector<ll> diff;
void setup()
{
    up.resize(n, vector<int>(MAXLOG + 1));
    depth.resize(n);
    adj.resize(n);
    parent.resize(n);
    diff.resize(n);
}
ll DFS_sum(int v, int p)
{
    ll sum = diff[v];
    for(int u : adj[v])
    {
        if(u == p) continue;
        sum += DFS_sum(u, v);
    }
    maxx = max(maxx, sum);
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    setup();
    for(int i = 0; i < n - 1; i++)
    {   
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    computeLCA(0, 0, 0);
    vector<ll> cntV(n);
    for(int i = 0; i < k; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        int lcaV = LCA(a, b);
        diff[a]++;
        diff[b]++;
        diff[lcaV]--;
        if(lcaV != 0)
            diff[up[lcaV][0]]--;
    }
    DFS_sum(0, 0);
    //cout << DFS_sum(0, 0);
    cout << maxx;
    return 0;
}