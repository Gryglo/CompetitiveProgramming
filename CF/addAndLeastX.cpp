#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 2e9;
struct Tree
{
    int sz;
    vector<int> t;
    vector<int> lazy;
    Tree(){}
    Tree(int sz1)
    {
        sz = sz1;
        t.resize(4 * sz);
        lazy.resize(4 * sz);
    }

    void push(int v, int l, int r)
    {
        if(lazy[v] == 0) return;
        t[v] += lazy[v];
        if(l != r)
        {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }

    int query(int v, int l, int r, int i, int x)
    {
        push(v, l, r);
        if(r < i) return INF;
        if(t[v] < x) return INF;
        if(l == r) return (t[v] >= x) ? l : INF;
        int m = (l + r) / 2;
        push(2 * v, l, m); 
        push(2 * v + 1, m + 1, r);
        int left = query(2 * v, l, m, i, x);
        if(left != INF) return left;
        return query(2 * v + 1, m + 1, r, i, x);
    }

    void update(int v, int l, int r, int tl, int tr, int x)
    {
        push(v, l, r);
        if(r < tl || l > tr) return;
        if(tl <= l && r <= tr)
        {
            lazy[v] += x;
            push(v, l, r);
        }
        else
        {
            int m = (l + r) / 2;
            update(2 * v, l, m, tl, tr, x);
            update(2 * v + 1, m + 1, r, tl, tr, x);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }   
    }

    void update(int l, int r, int x)
    {
        update(1, 0, sz - 1, l, r, x);
    }

    int query(int i, int x)
    {
        int ans = query(1, 0, sz - 1, i, x);
        if(ans == INF) return -1;
        return ans;
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
        int type; cin >> type;
        if(type == 1)
        {
            int l, r, x; cin >> l >> r >> x; r--;
            tree.update(l, r, x);
        }
        else
        {
            int x, i; cin >> x >> i;
            cout << tree.query(i, x) << '\n';
        }
    }
    return 0;
}