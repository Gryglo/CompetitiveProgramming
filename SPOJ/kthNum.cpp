#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> a;
int num_cnt = 0;
unordered_map<int, int> order, rev_order;
struct Vertex
{
    int val = 0;
    Vertex *l = nullptr, *r = nullptr;

    Vertex(int val)
    {
        this->val = val;
    }
    Vertex(Vertex* l, Vertex* r)
    {
        this->l = l;
        this->r = r;
        val = l->val + r->val;
    }
};
struct Tree
{
    vector<Vertex*> roots;

    Vertex* update(Vertex* v, int l, int r, int i)
    {
        if(l == r) return new Vertex(v->val + 1);
        int m = (l + r) / 2;
        if(i <= m) return new Vertex(update(v->l, l, m, i), v->r);
        return new Vertex(v->l, update(v->r, m + 1, r, i));
    }

    Vertex* build(int l, int r)
    {
        if(l == r) return new Vertex(0);
        int m = (l + r) / 2;
        return new Vertex(build(l, m), build(m + 1, r));
    }

    int query(Vertex* vl, Vertex* vr, int l, int r, int k)
    {
        if(l == r) return rev_order[l];
        int m = (l + r) / 2;
        int left = vr->l->val - vl->l->val;
        if(left >= k) return query(vl->l, vr->l, l, m, k);
        return query(vl->r, vr->r, m + 1, r, k - left);
    }

    int query(int l, int r, int k)
    {
        return query(roots[l], roots[r + 1], 0, num_cnt - 1, k);
    }

    void build()
    {
        //tree of counts of values so
        roots.resize(n + 1);
        roots[0] = build(0, num_cnt - 1);
        for(int i = 0; i < n; i++) roots[i + 1] = update(roots[i], 0, num_cnt - 1, order[a[i]]);
    }

};
Tree tree;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> a2(a);
    sort(a2.begin(), a2.end());
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && a2[i] == a2[i - 1]) continue;
        order[a2[i]] = num_cnt;
        rev_order[num_cnt++] = a2[i];
    }
    tree.build();
}

int32_t main()
{
    init();
    for(int i = 0; i < m; i++)
    {
        int l, r, k; cin >> l >> r >> k; l--; r--;
        cout << tree.query(l, r, k) << '\n';
    }
    return 0;
}