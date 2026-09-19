#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXLOG = 38;
int n;
vector<int> a;

struct Vertex
{
    int sum = 0;
    vector<int> bit_cnt;
    Vertex()
    {
        bit_cnt.resize(MAXLOG + 1);
    }

    Vertex(int val)
    {
        sum = val;
        bit_cnt.resize(MAXLOG + 1);
        int i = 0;
        while(val > 0)
        {
            if(val % 2 != 0) bit_cnt[i]++;
            val /= 2; i++;
        }
    }

    void calc_sum()
    {
        sum = 0;
        int pending = 0;
        int p = 1;
        for(int i = 0; i <= MAXLOG; i++)
        {   
            if((bit_cnt[i] + pending) % 2 != 0) sum += p;
            pending = (bit_cnt[i] + pending) / 2;
            p*=2;
        }
    }
};

struct Tree
{
    vector<Vertex> t;
    vector<int> lazy;
    Tree() {}

    void merge(Vertex& l, Vertex& r, Vertex& v)
    {
        for(int i = 0; i <= MAXLOG; i++) v.bit_cnt[i] = l.bit_cnt[i] + r.bit_cnt[i];
        v.sum = l.sum + r.sum;
    }
    
    void push(int v, int l, int r)
    {
        if(lazy[v] == 0) return;
        int seg_size = r - l + 1;
        for(int i = 0; i <= MAXLOG; i++)
            if(lazy[v] & (1LL << i)) t[v].bit_cnt[i] = seg_size - t[v].bit_cnt[i];
        t[v].calc_sum();
        if(l != r)
        {
            lazy[2 * v] ^= lazy[v];
            lazy[2 * v + 1] ^= lazy[v];
        }
        lazy[v] = 0;
    }

    void update(int v, int l, int r, int tl, int tr, int x)
    {
        push(v, l, r);
        if(r < tl || l > tr) return;
        if(tl <= l && r <= tr)
        {
            lazy[v] = x;
            push(v, l, r);
        }
        else
        {
            int m = (l + r) / 2;
            update(2 * v, l, m, tl, tr, x);
            update(2 * v + 1, m + 1, r, tl, tr, x);
            merge(t[2 * v], t[2 * v + 1], t[v]);
        }
    }

    int query(int v, int l, int r, int tl, int tr)
    {
        push(v, l, r);
        if(r < tl || l > tr) return 0;
        if(tl <= l && r <= tr) return t[v].sum;
        else
        {
            int m = (l + r) / 2;
            return query(2 * v, l, m, tl, tr) + query(2 * v + 1, m + 1, r, tl, tr);
        }
    }

    void build(int v, int l, int r)
    {
        if(l == r) t[v] = Vertex(a[l]);
        else
        {
            int m = (l + r) / 2;
            build(2 * v, l, m);
            build(2 * v + 1, m + 1, r);
            merge(t[2 * v], t[2 * v + 1], t[v]);
        }
    }

    void build()
    {
        t.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int l, int r, int x)
    { update(1, 0, n - 1, l, r, x); }

    int query(int l, int r)
    { return query(1, 0, n - 1, l, r); }
};
Tree tree;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    tree.build();
}

int32_t main()
{
    init();
    int m; cin >> m;
    for(int i = 0; i < m; i++)
    {
        int type; cin >> type; 
        if(type == 1)
        {
            int l, r; cin >> l >> r; l--; r--;
            cout << tree.query(l, r) << '\n';
        }
        else
        {
            int l, r, x; cin >> l >> r >> x; l--; r--;
            tree.update(l, r, x);
        }
    }
    return 0;
}