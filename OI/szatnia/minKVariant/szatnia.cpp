#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using event = pair<pii, int>;

int n, p;
vector<int> plan_c;
vector<int> item_c;
vector<event> events; //(pos, typ, idx)
vector<pii> item_end;
vector<int> plan_end;
vector<bool> ans;

vector<int> t;
vector<int> lazy;

void push(int v, int l, int r)
{
    t[v] += lazy[v];
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
    if(l > tr || r < tl) return;
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
    update(1, 0, p - 1, l, r, x);
}

int query(int v, int l, int r, int i)
{
    push(v, l, r);
    if(l == r) return t[v];
    int m = (l + r) / 2;
    if(i <= m) return query(2 * v, l, m, i);
    else return query(2 * v + 1, m + 1, r, i);
}

int query(int i)
{
    return query(1, 0, p - 1, i);
}

void init()
{
    cin >> n;
    item_c.resize(n);
    item_end.resize(n);
    for(int i = 0; i < n; i++)
    {
        int c, a, b; cin >> c >> a >> b;
        item_c[i] = c;
        events.push_back({{a, 0}, i});
        events.push_back({{b, 1}, i});
    }
    cin >> p;
    plan_end.resize(p);
    plan_c.resize(p);
    for(int i = 0; i < p; i++)
    {
        int m, k, s; cin >> m >> k >> s;
        plan_c[i] = k;
        events.push_back({{m, 2}, i});
        events.push_back({{m + s, 3}, i});
    }

    t.resize(4 * p);
    lazy.resize(4 * p);
    ans.resize(p);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    sort(events.begin(), events.end());
    int start_c = -1;
    for(int i = 0; i < events.size(); i++)
    {
        event curr = events[i];
        int type = curr.f.s;
        if(type == 2) plan_end[curr.s] = ++start_c;
        else if(type == 0) item_end[curr.s].f = start_c;
        else if(type == 1) item_end[curr.s].s = start_c;
    }
    
    for(int i = 0; i < events.size(); i++)
    {
        event curr = events[i];
        int type = curr.f.s; 
        if(type == 0) 
        {
            if(item_end[curr.s].f + 1 > item_end[curr.s].s) continue;
            update(item_end[curr.s].f + 1, item_end[curr.s].s, item_c[curr.s]);
        }
        else if(type == 1)
        {
            if(item_end[curr.s].f + 1 > item_end[curr.s].s) continue;
            update(item_end[curr.s].f + 1, item_end[curr.s].s, -item_c[curr.s]);
        }
        else if(type == 3) ans[curr.s] = (query(plan_end[curr.s]) >= plan_c[curr.s]);
    }
    
    for(int i = 0; i < p; i++)
    {
        if(ans[i]) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}