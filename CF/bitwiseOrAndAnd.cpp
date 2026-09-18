#include <bits/stdc++.h>
#define int long long
using namespace std;
const int FULL = (1LL << 32LL) - 1;
int n, m;
struct Tree
{
    vector<int> t;
    vector<int> lazy;

    Tree(){}
    void build()
    {
        t.resize(4 * n);
        lazy.resize(4 * n);      
    }

    void push(int v, int l, int r)
    {
        if(lazy[v] == 0) return;
        t[v] |= lazy[v];
        if(l != r)
        {
            lazy[2 * v] |= lazy[v];
            lazy[2 * v + 1] |= lazy[v];
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
            t[v] = t[2 * v] & t[2 * v + 1];
        }
    }

    int query(int v, int l, int r, int tl, int tr)
    {
        push(v, l, r);
        if(r < tl || l > tr) return FULL;
        if(tl <= l && r <= tr) return t[v];
        else
        {
            int m = (l + r) / 2;
            return query(2 * v, l, m, tl, tr) & query(2 * v + 1, m + 1, r, tl, tr);
        }
    }

    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }

    void update(int l, int r, int x)
    {
        update(1, 0, n - 1, l, r, x);
    }
};
Tree tree;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    tree.build();
}

int32_t main()
{
    init();
    for(int i = 0; i < m; i++)
    {
        int type; cin >> type; 
        if(type == 1)
        {
            int l, r, x; cin >> l >> r >> x; r--;
            tree.update(l, r, x);
        }
        else
        {
            int l, r; cin >> l >> r; r--;
            cout << tree.query(l, r) << '\n';
        }
    }
    return 0;
}