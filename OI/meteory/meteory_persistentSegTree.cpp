#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q;
vector<vector<int>> country_i;
vector<int> country_need;

struct Rain
{ int l = -1, r = -1, x = -1; };
vector<Rain> rains;

struct Vertex
{
    ll sum = 0;
    Vertex* l = nullptr;
    Vertex* r = nullptr;
    Vertex(ll sum) { this->sum = sum; }
    Vertex(Vertex* l, Vertex* r) { this->l = l; this->r = r; }
};

struct Tree
{
    vector<Vertex*> roots;
    ll query(Vertex* v, int l, int r, int i)
    {
        if(l == r) return v->sum;
        int m = (l + r) / 2;
        if(i <= m) return query(v->l, l, m, i) + v->sum;
        else return query(v->r, m + 1, r, i) + v->sum;
    }

    Vertex* update(Vertex* v, int l, int r, int tl, int tr, ll x)
    {
        if(r < tl || l > tr) return v;
        if(tl <= l && r <= tr) 
        {
            Vertex* next = new Vertex(v->l, v->r);
            next->sum = v->sum + x;
            return next;
        }
        int m = (l + r) / 2;
        Vertex* next = new Vertex(update(v->l, l, m, tl, tr, x), update(v->r, m + 1, r, tl, tr, x));
        next->sum = v->sum;
        return next;
    }

    Vertex* build(int l, int r)
    {
        if(l == r) return new Vertex(0);
        int m = (l + r) / 2;
        return new Vertex(build(l, m), build(m + 1, r));
    }

    ll query(int i, int t_idx) { return query(roots[t_idx], 0, m - 1, i); }
    
    void build()
    {
        roots.resize(q + 1);
        roots[0] = build(0, m - 1);
        for(int i = 0; i < q; i++)
        {
            if(rains[i].l > rains[i].r)
            {
                Vertex* curr = update(roots[i], 0, m - 1, rains[i].l, m - 1, rains[i].x);
                roots[i + 1] = update(curr, 0, m - 1, 0, rains[i].r, rains[i].x);
            }
            else roots[i + 1] = update(roots[i], 0, m - 1, rains[i].l, rains[i].r, rains[i].x);
        }
    }

};
Tree tree;

ll sum_sector(int country, int t_idx)
{
    ll sum = 0;
    for(int i : country_i[country]) sum += tree.query(i, t_idx);
    return sum;
}

int min_rain_i(int country)
{
    int ans = -1;
    int l = 1, r = q;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(sum_sector(country, m) >= country_need[country])
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return ans;
}

void init()
{
    cin >> n >> m;
    country_i.resize(n);
    for(int i = 0; i < m; i++) 
    {
        int x; cin >> x;
        country_i[x - 1].push_back(i);
    }
    country_need.resize(n);
    for(int i = 0; i < n; i++) cin >> country_need[i];
    cin >> q;
    rains.resize(q);
    for(int i = 0; i < q; i++)
    {
        cin >> rains[i].l >> rains[i].r >> rains[i].x;
        rains[i].l--; rains[i].r--;
    }
    tree.build();
}

int32_t main()
{
    init();
    for(int i = 0; i < n; i++)
    {   
        int min_i = min_rain_i(i);
        if(min_i == -1) cout << "NIE\n";
        else cout << min_i << '\n';
    }
    return 0;
}