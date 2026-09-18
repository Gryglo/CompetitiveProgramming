#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

int n, q;
vector<pii> seg;

int num_cnt = 0;
map<int, int> order;

struct Vertex
{
    int sum = 0, cnt = 0;
    Vertex* l = nullptr;
    Vertex* r = nullptr;

    Vertex(){}
    Vertex(int sum, int cnt)
    {
        this->sum = sum;
        this->cnt = cnt;
    }

    Vertex(Vertex* l, Vertex* r)
    {
        this->l = l;
        this->r = r;
        sum = l->sum + r->sum;
        cnt = l->cnt + r->cnt;
    }
};

struct Tree
{
    vector<Vertex*> roots;
    
    Vertex* update(Vertex* v, int l, int r, int i, int val)
    {
        if(l == r) return new Vertex((int) v->sum + val, (int) v->cnt + 1);
        int m = (l + r) / 2;
        if(i <= m) return new Vertex(update(v->l, l, m, i, val), v->r);
        return new Vertex(v->l, update(v->r, m + 1, r, i, val));
    }    

    pii query(Vertex* vl, Vertex* vr, int l, int r, int k)
    {
        int curr_sum = vr->sum - vl->sum;
        int curr_cnt = vr->cnt - vl->cnt;
        if(curr_cnt <= k)
        {
            return {curr_sum, curr_cnt};
        }
        if(l == r)
        {
            // curr_cnt > k
            int val = curr_sum / curr_cnt;
            return {val * k, k};
        }
        int m = (l + r) / 2;
        pii right = query(vl->r, vr->r, m + 1, r, k);
        int rest_k = k - right.s;
        pii left = {0, 0};
        if(rest_k > 0)
        {
            left = query(vl->l, vr->l, l, m, rest_k);
        }
        return {right.f + left.f , right.s + left.s};
    }
    
    Vertex* build(int l, int r)
    {
        if(l == r) return new Vertex();
        int m = (l + r) / 2;
        return new Vertex(build(l, m), build(m + 1, r));
    }
    
    int query(int l, int r, int k)
    {
        if(k <= 0) return 0;
        return query(roots[l], roots[r + 1], 0, num_cnt - 1, k).f;
    }

    void build()
    {
        // 7 
        // 0 1 2 3 4 5 6 
        roots.resize(n + 5);
        roots[0] = build(0, num_cnt - 1);
        for(int i = 0; i < n; i+=2)
        {
            roots[i / 2 + 1] = update(roots[i / 2], 0, num_cnt - 1, order[seg[i].s], seg[i].s); 
        }
    }
};
Tree tree;

int find_seg(int i)
{
    int ans = 0;
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(i >= seg[m].f)
        {
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return ans;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    seg.resize(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
        seg[i] = {(i > 0) ? seg[i - 1].f + seg[i - 1].s : 0, a[i]};
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        if(i == 0 || a[i] != a[i - 1]) order[a[i]] = num_cnt++;
    }
    tree.build();
}

int32_t main()
{
    init();
    for(int i = 0; i < q; i++)
    {
        int l, r, k; cin >> l >> r >> k; l--; r--;
        int seg_l = find_seg(l);
        int seg_r = find_seg(r);
        if(seg_l == seg_r)
        {
            if(seg_l % 2 != 0) cout << 0 << '\n';
            else cout << (r - l + 1) << '\n';
            continue;
        }
        if(k == 0)
        {
            cout << 0 << '\n'; 
            continue;
        }

        // 0 1 2 3 4 5 6 7 8 
        // x x x x 0 0 x x x x
        //   l           r
        //4 - 1
        // 

        int tl = seg_l / 2 + 1, tr = seg_r / 2;
        int l_s = 0, r_s = 0;
        if(seg_l % 2 == 0)
        {
            l_s = seg[seg_l].f + seg[seg_l].s - l;
        }
        if(seg_r % 2 == 0) 
        {
            tr--;
            r_s = r - seg[seg_r].f + 1;
        }
        if(tl > tr)
        {
            if(k >= 2) cout << (l_s + r_s) << '\n';
            else cout << max(l_s, r_s) << '\n';
            continue;
        }

        int ans1 = tree.query(tl, tr, k / 2); //bez koncow
        int ans2 = tree.query(tl, tr, (k - 1) / 2); //z jednym koncem
        int ans3 = tree.query(tl, tr, (k - 2) / 2); // z dwoma koncami

        int ans = ans1;
        if(k >= 1) ans = max(ans, ans2 + max(l_s, r_s));
        if(k >= 2) ans = max(ans, ans3 + l_s + r_s);
        cout << ans << '\n';
    }
    return 0;
}