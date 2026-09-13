#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n = 0, q = 0;
vector<int> a;
struct Tree
{
    int N;
    vector<int> t;
    vector<int> lazy;
    Tree()
    {
        N = 1;
        while(N < n) N*=2;
        t.resize(4 * N);
        lazy.resize(4 * N);
    }

    void push(int v, int l, int r)
    {
        if(lazy[v] == 0) return;
        t[v] += (r - l + 1) * lazy[v];
        if(l != r)
        {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
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
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    void update(int l, int r, int x)
    {
        update(1, 0, N - 1, l, r, x);
    }

    void push_all(int v, int l, int r)
    {
        push(v, l, r);
        if(l == r) return;
        int m = (l + r) / 2;
        push_all(2 * v, l, m);
        push_all(2 * v + 1, m + 1, r);
    }

    int query(int i)
    {
        return t[N + i];
    }    
};
Tree tree;


void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    tree = Tree();
}

int32_t main()
{
    init();
    for(int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r; l--; r--;
        tree.update(l, r, 1);
    }
    tree.push_all(1, 0, tree.N - 1);
    sort(tree.t.begin() + tree.N, tree.t.begin() + tree.N + n);
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i = 0; i < n; i++) sum += tree.t[tree.N + i] * a[i];
    cout << sum;
    return 0;
}