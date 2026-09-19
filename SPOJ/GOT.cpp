#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int MAXLOG = 17;
int n, q;
vector<int> val;
vector<vector<int>> adj;
vector<int> tin, tout;
vector<pii> euler_tour;
vector<vector<int>> up;
vector<int> depth;
int timer = 0;
void DFS(int v, int p)
{
    depth[v] = (p == -1) ? 0 : depth[p] + 1;
    up[0][v] = (p == -1) ? 0 : p;
    for(int x = 1; x <= MAXLOG; x++) up[x][v] = up[x - 1][up[x - 1][v]];
    tin[v] = timer++;
    euler_tour.push_back({val[v], 1});
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS(u, v);
    }
    tout[v] = timer++;
    euler_tour.push_back({val[v], -1});
}

int LCA(int a, int b)
{
    if(a == b) return a;
    if(depth[a] < depth[b]) swap(a, b); //b wyzej a nizej
    for(int x = MAXLOG; x >= 0; x--)
    {
        if(depth[up[x][a]] >= depth[b]) a = up[x][a];
    }
    //rowny poziom
    if(a == b) return a;
    for(int x = MAXLOG; x >= 0; x--)
    {
        if(up[x][a] != up[x][b])
        {
            a = up[x][a];
            b = up[x][b];
        }
    }
    return up[0][a];
}

struct Vertex
{
    int cnt = 0;
    Vertex* l = nullptr;
    Vertex* r = nullptr;

    Vertex(int cnt)
    { this->cnt = cnt; }

    Vertex(Vertex* l, Vertex* r)
    {
        this->l = l;
        this->r = r;
        cnt = l->cnt + r->cnt;
    }
};

struct Tree
{
    vector<Vertex*> roots;
    int query(Vertex* vl, Vertex* vr, int l, int r, int i)
    {
        if(l == r)
        {
            int curr_cnt = vr->cnt - vl->cnt;
            return curr_cnt;
        }
        int m = (l + r) / 2;
        if(i <= m) return query(vl->l, vr->l, l, m, i);
        return query(vl->r, vr->r, m + 1, r, i);
    }

    int query(int l, int r, int x)
    {
        //0 euler_tour.size() -1 
        return query(roots[l], roots[r + 1], 0, n, x);
    }

    Vertex* update(Vertex* v, int l, int r, int i, int x)
    {
        if(l == r) return new Vertex(v->cnt + x);
        int m = (l + r) / 2;
        if(i <= m) return new Vertex(update(v->l, l, m, i, x), v->r);
        return new Vertex(v->l, update(v->r, m + 1, r, i, x));
    }

    Vertex* build(int l, int r)
    {
        if(l == r) return new Vertex(0);
        int m = (l + r) / 2;
        return new Vertex(build(l, m), build(m + 1, r));
    }
    void build()
    {
        //0 - n
        roots.resize(euler_tour.size() + 1);
        roots[0] = build(0, n);
        for(int i = 0; i < euler_tour.size(); i++)
        {
            roots[i + 1] = update(roots[i], 0, n, euler_tour[i].f, euler_tour[i].s);
        }
    }
};
Tree tree;

bool is_on_path(int a, int b, int x)
{
    int l = tin[a];
    int r = tin[b];
    int res = tree.query(l, r, x);
    return res > 0;
}

void init()
{
    timer = 0;
    euler_tour.clear();
    val.assign(n, 0);
    adj.assign(n, vector<int>());
    tin.assign(n, 0); tout.assign(n, 0);
    depth.assign(n, 0);
    up.assign(MAXLOG + 1, vector<int>(n, 0));
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(0, -1);
    tree.build();
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> q)
    {
        init();
        for(int i = 0; i < q; i++)
        {
            int a, b, x; cin >> a >> b >> x; a--; b--;
            int v_lca = LCA(a, b);
            if(is_on_path(v_lca, a, x) || is_on_path(v_lca, b, x)) cout << "Find\n";
            else cout << "NotFind\n";
        }
        cout << '\n';
    }
    return 0;
}   