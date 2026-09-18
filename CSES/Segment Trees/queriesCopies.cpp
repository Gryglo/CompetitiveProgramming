#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
vector<int> a;

struct Tree
{
    struct Vertex
    {
        int val = 0;
        Vertex* l = nullptr;
        Vertex* r = nullptr;
        Vertex(){}
        Vertex(int val1) { val = val1; }
        Vertex(Vertex* l, Vertex* r)
        {
            this->l = l;
            this->r = r;
            val = l->val + r->val;
        }
    };
    vector<Vertex*> roots;
    
    int query(Vertex* v, int l, int r, int tl, int tr)
    {
        if(r < tl || l > tr) return 0;
        if(tl <= l && r <= tr) return v->val;
        else
        {
            int m = (l + r) / 2;
            return query(v->l, l, m, tl, tr) + query(v->r, m + 1, r, tl, tr);
        }
    }

    Vertex* update(Vertex* v, int l, int r, int i, int x)
    {
        if(l == r) return new Vertex(x);
        else
        {
            int m = (l + r) / 2;
            if(i <= m) return new Vertex(update(v->l, l, m, i, x), v->r);
            else return new Vertex(v->l, update(v->r, m + 1, r, i, x));
        }
    }
    
    Vertex* build(int l, int r)
    {
        if(l == r) return new Vertex(a[l]);
        else
        {
            int m = (l + r) / 2;
            return new Vertex(build(l, m), build(m + 1, r));
        }
    }   

    int query(int k, int l, int r)
    {
        return query(roots[k], 0, n - 1, l, r);
    }

    void update(int k, int i, int x)
    {
        roots[k] = update(roots[k], 0, n - 1, i, x);
    }

    void copy_arr(int k)
    {
        roots.push_back(new Vertex(roots[k]->l, roots[k]->r));
    }

    void build()
    {
        roots.push_back(build(0, n - 1));
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
            int k, i, x; cin >> k >> i >> x; k--; i--;
            tree.update(k, i, x);
        }
        else if(type == 2)
        {
            int k, l, r; cin >> k >> l >> r; k--; l--; r--;
            cout << tree.query(k, l, r) << '\n';
        }
        else
        {
            int k; cin >> k; k--;
            tree.copy_arr(k);
        }
    }
    return 0;
}