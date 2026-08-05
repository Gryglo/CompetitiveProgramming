#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> level;
vector<int> parent;
vector<int> minv, maxv, sz;

int find(int v)
{
    if(parent[v] == v) return v;
    return find(parent[v]);
}

int merge_union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) { sz[pa]++; return pa; }
    if(level[pa] < level[pb]) swap(pa, pb);
    if(level[pa] == level[pb]) level[pa]++;
    parent[pb] = pa;
    minv[pa] = min(minv[pa], minv[pb]);
    maxv[pa] = max(maxv[pa], maxv[pb]);
    sz[pa] += sz[pb] + 1;
    return pa;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    level.resize(n); parent.resize(n);
    minv.resize(n); maxv.resize(n); sz.resize(n);
    for(int i = 0; i < n; i++) parent[i] = i;
    for(int i = 0; i < n; i++) minv[i] = i;
    for(int i = 0; i < n; i++) maxv[i] = i;
}

int32_t main()
{
    init();
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        int v = merge_union(a, b);
        cout << ((maxv[v] - minv[v]) * sz[v]) << '\n';
    }
    return 0;
}