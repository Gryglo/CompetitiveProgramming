#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
vector<int> val;
vector<vector<int>> adj;
vector<int> order;
vector<int> tin, tout;
int timer = 0;
void DFS(int v, int p)
{
    tin[v] = timer++;
    order.push_back(val[v]);
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS(u, v);
    }
    tout[v] = timer++;
    order.push_back(val[v]);
}

struct Tree
{
    int N;
    vector<int> t;
    
    int query(int v, int l, int r, int tl, int tr)
    {
        if(r < tl || l > tr) return 0;
        if(tl <= l && r <= tr) return t[v];
        int m = (l + r) / 2;
        return query(2 * v, l, m, tl, tr) + query(2 * v + 1, m + 1, r, tl, tr);
    }

    void update(int v, int l, int r, int i, int x)
    {
        if(l == r) t[v] = x;
        else
        {
            int m = (l + r) / 2;
            if(i <= m) update(2 * v, l, m, i, x);
            else update(2 * v + 1, m + 1, r, i, x);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    void build(int v, int l, int r)
    {
        if(l == r) t[v] = order[l];
        else
        {
            int m = (l + r) / 2;
            build(2 * v, l, m);
            build(2 * v + 1, m + 1, r);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
    
    int query(int l, int r)
    { return query(1, 0, N - 1, l, r); }

    void update(int i, int x)
    { update(1, 0, N - 1, i, x); }

    void build()
    {
        N = order.size();
        t.resize(4 * N);
        build(1, 0, N - 1);
    }
};
Tree tree;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    val.resize(n);
    for(int i = 0; i < n; i++) cin >> val[i];
    adj.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tin.resize(n);
    tout.resize(n);
    DFS(0, -1);
    tree.build();
}

int32_t main()
{
    init();
    for(int i = 0; i < q; i++)
    {
        int type; cin >> type;
        if(type == 1)
        {
            int i, x; cin >> i >> x; i--;
            int l = tin[i];
            int r = tout[i];
            tree.update(l, x);
            tree.update(r, x);
        }
        else
        {
            int i; cin >> i; i--;
            int l = tin[i];
            int r = tout[i];
            int sum = tree.query(l, r);
            cout << (sum / 2) << '\n';
        }
    }
    return 0;
}