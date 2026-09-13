#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

struct Tree
{
    int n;
    vector<pii> t;
    vector<int> lazy;

    Tree()
    {

    }

    pii merge(pii& a, pii& b)
    {
        return {a.f ^ b.f, a.s ^ b.s};
    }

    void push(int v, int l, int r)
    {
        if(lazy[v] == 0) return;
        if(lazy[v] % 2 != 0) swap(t[v].f, t[v].s);
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
        if(l > tr || r < tl) return;
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
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }

    void build(int v, int l, int r, vector<int>& a, string& mask)
    {
        if(l == r)
        {
            if(mask[l] == '0') t[v] = {a[l], 0};
            else t[v] = {0, a[l]};
        }
        else
        {
            int m = (l + r) / 2;
            build(2 * v, l, m, a, mask);
            build(2 * v + 1, m + 1, r, a, mask);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }

    void update(int l, int r)
    {
        update(1, 0, n - 1, l, r);
    }

    int query(int type)
    {
        if(type == 0) return t[1].f;
        return t[1].s;
    }

    void build(vector<int>& a, string& mask)
    {
        n = a.size();
        t.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1, a, mask);
    }

};

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    string mask; cin >> mask;
    Tree tree;
    tree.build(a, mask);

    int q; cin >> q;
    while(q--)
    {
        int t; cin >> t;
        if(t == 2)
        {
            int x; cin >> x;
            cout << tree.query(x) << ' ';
        }
        else
        {
            int l, r; cin >> l >> r; l--; r--;
            tree.update(l, r);
        }
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}