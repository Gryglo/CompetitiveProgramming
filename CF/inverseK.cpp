#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Tree
{
    int n;
    vector<int> t;
    vector<int> lazy;

    Tree(){}
    Tree(int n1)
    {
        n = n1;
        t.resize(4 * n);
        lazy.resize(4 * n);
    }

    void push(int v, int l, int r)
    {
        if(lazy[v] == 0) return;
        if(lazy[v] % 2 != 0) t[v] = (r - l + 1) - t[v];
        if(l != r)
        {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }

    void update(int v, int l, int r, int tl, int tr)
    {
        push(v, l, r);
        if(r < tl || l > tr) return;
        if(tl <= l && r <= tr)
        {
            lazy[v] = 1;
            push(v, l, r);
        }
        else
        {
            int m = (l + r) / 2;
            update(2 * v, l, m, tl, tr);
            update(2 * v + 1, m + 1, r, tl, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    int query(int v, int l, int r, int k)
    {
        push(v, l, r);
        if(l == r) return l;
        int m = (l + r) / 2;
        push(2 * v, l, m);
        push(2 * v + 1, m + 1, r);
        if(k <= t[2 * v]) return query(2 * v, l, m, k);
        else return query(2 * v + 1, m + 1, r, k - t[2 * v]);
    }

    int query(int k)
    {
        return query(1, 0, n - 1, k);
    }

    void update(int l, int r)
    {
        update(1, 0, n - 1, l, r);
    }

};
int n, m;
Tree tree;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    tree = Tree(n);
}

int32_t main()
{
    init();
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int l, r; cin >> l >> r; r--;
            tree.update(l, r);
        }
        else
        {
            int k; cin >> k;
            cout << tree.query(k + 1) << '\n';
        }
    }
    return 0;
}