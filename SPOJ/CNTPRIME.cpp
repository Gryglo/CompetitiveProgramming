#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<bool> prime;
void sieve(int N)
{
    prime.resize(N + 1, true);
    for(int i = 2; i * i <= N; i++)
    {
        if(!prime[i]) continue;
        for(int j = i * i; j <= N; j+=i) prime[j] = false;
    }
}

struct Tree
{
    int N = 1;
    vector<int> t;
    vector<int> lazy;

    void build(int v, int l, int r, vector<int>& a)
    {
        if(l == r) 
        {
            if(l < a.size()) t[v] = (prime[a[l]]) ? 1 : 0;
        }
        else
        {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    Tree(int n, vector<int>& a)
    {
        while(N < n) N*=2;
        t.resize(4 * N);
        lazy.resize(4 * N, -1);
        build(1, 0, N - 1, a);
    }

    void push(int v, int l, int r)
    {
        if(lazy[v] == -1) return;
        t[v] = (r - l + 1) * lazy[v];
        if(l != r)
        {
            lazy[2 * v] = lazy[v];
            lazy[2 * v + 1] = lazy[v];
        }
        lazy[v] = -1;
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
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    int query(int v, int l, int r, int tl, int tr)
    {
        push(v, l, r);
        if(r < tl || l > tr) return 0;
        if(tl <= l && r <= tr) return t[v];
        int m = (l + r) / 2;
        return query(2 * v, l, m, tl, tr) + query(2 * v + 1, m + 1, r, tl, tr);
    }

    void update(int l, int r, int x)
    {
        update(1, 0, N - 1, l, r, x);
    }

    int query(int l, int r)
    {
        return query(1, 0, N - 1, l, r);
    }
};

void solve(int q)
{
    cout << "Case " << q << ":\n";
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    Tree tree(n, a);
    for(int i = 0; i < m; i++)
    {
        int type; cin >> type;
        if(type == 0)
        {
            int l, r, x; cin >> l >> r >> x;
            l--; r--;
            tree.update(l, r, (prime[x]) ? 1 : 0);
        }
        else
        {
            int l, r; cin >> l >> r; l--; r--;
            cout << tree.query(l, r) << '\n';
        }
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve(1e6);
}

int32_t main()
{
    init();
    int q; cin >> q;
    for(int i = 1; i <= q; i++) solve(i);
    return 0;
}