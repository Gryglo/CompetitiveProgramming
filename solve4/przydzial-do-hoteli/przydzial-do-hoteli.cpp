#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int sz, S;
    vector<int> t;
    private:
        void build(int v, int l, int r, vector<int>& a)
        {
            if(l == r) { t[v] = (l < sz) ? a[l] : -1; }
            else
            {
                int m = (l + r) / 2;
                build(2 * v, l, m, a);
                build(2 * v + 1, m + 1, r, a);
                t[v] = max(t[2 * v], t[2 * v + 1]);
            }
        }

        int query(int v, int l, int r, int tl, int tr)
        {
            if(l > r || l > tr || r < tl) return -1;
            if(tl <= l && r <= tr) return t[v];
            int m = (l + r) / 2;
            return max(query(2 * v,     l,     m, tl, tr), 
                       query(2 * v + 1, m + 1, r, tl, tr));
        }

        void update(int v, int l, int r, int i, int x)
        {
            if(l == r) { t[v] -= x; return; }
            int m = (l + r) / 2;
            if(i <= m) update(2 * v,     l,     m, i, x);
            else       update(2 * v + 1, m + 1, r, i, x);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }

    public:
        void build(vector<int>& a)
        {
            sz = a.size(); S = 1;
            while(S < sz) S *= 2;
            t.resize(4 * S);
            build(1, 0, S - 1, a);
        }
        void update(int i, int x) { update(1, 0, S - 1, i, x); }
        int query(int l, int r) { return query(1, 0, S - 1, l, r); }
};


int n, q;
Tree t;
vector<int> hotels, queries;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    hotels.resize(n); queries.resize(q);
    for(int i = 0; i < n; i++) cin >> hotels[i];
    for(int i = 0; i < q; i++) cin >> queries[i];
    t.build(hotels);
}

int find_hotel(int x)
{
    int l = 0, r = n - 1;
    int curr_hotel = n;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(t.query(l, m) >= x)
        {
            curr_hotel = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return curr_hotel;
}


int main()
{   
    init();
    for(int& x : queries)
    {
        int curr_hotel = find_hotel(x);
        if(curr_hotel == n) { cout << 0 << ' '; continue; }
        t.update(curr_hotel, x);
        cout << curr_hotel + 1 << ' ';
    }
    return 0;
}