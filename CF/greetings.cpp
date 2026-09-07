#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Tree
{
    vector<int> t;
    int n;
    Tree(int n)
    {
        this->n = n;
        t.resize(4 * n);
    }

    void update(int v, int l, int r, int i, int x)
    {
        if(l == r) { t[v] += x; return; }
        int m = (l + r) / 2;
        if(i <= m) update(2 * v, l, m, i, x);
        if(i > m) update(2 * v + 1, m + 1, r, i, x);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int query(int v, int l, int r, int tl, int tr)
    {
        if(r < tl || l > tr) return 0;
        if(tl <= l && r <= tr) return t[v];
        int m = (l + r) / 2;
        return query(2 * v, l, m, tl, tr) + query(2 * v + 1, m + 1, r, tl, tr);
    }

    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }

    void place(int i)
    {
        update(1, 0, n - 1, i, 1);
    }
};

void solve()
{
    int n; cin >> n;
    vector<pll> a(n);
    vector<pll> order(n);
    vector<int> i_end(n);
    for(int i = 0; i < n; i++) 
    {
        int l, r; cin >> l >> r;
        a[i].f = l; a[i].s = i;
        order[i] = {r, i};
    }
    sort(order.begin(), order.end());
    for(int i = 0; i < n; i++) i_end[order[i].s] = i;
    Tree ends(n + 5);
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += ends.query(i_end[a[i].s], n - 1);
        //a[i].s
        ends.place(i_end[a[i].s]);
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}