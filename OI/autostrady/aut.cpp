/* 
    -=-=-=-=-=-=-
    TASK: AUTOSTRADY
    SCORE: 100
    LINK: https://szkopul.edu.pl/problemset/problem/FKqZZxq392rXuZdedx7vm5kh/site/?key=statement
    -=-=-=-=-=-=-
*/
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

const int INF = INT_MAX;
const pii NO_VAL = {-INF, -1};

struct Tree
{
    vector<pii> t;
    int size;
    Tree() {}
    Tree(int size) { this->size = size; t.resize(4 * size, NO_VAL); }
    void update(int v, int l, int r, int i, pii x)
    {
        if(l == r) t[v] = x;
        else
        {
            int m = (l + r) / 2;
            if(i <= m) update(2 * v, l, m, i, x);
            else update(2 * v + 1, m + 1, r , i, x);
            t[v] = max(t[2 * v], t[2 * v + 1]);
        }
    }

    pii query(int v, int l, int r, int tl, int tr)
    {
        if(l > tr || r < tl) return NO_VAL;
        if(tl <= l && r <= tr) return t[v];
        else
        {
            int m = (l + r) / 2;
            return max(
                query(2 * v, l, m, tl, tr),
                query(2 * v + 1, m + 1, r, tl, tr)
            );
        }
    }

    void update(int i, pii x) { update(1, 0, size - 1, i, x); }
    pii query(int l, int r) { return query(1, 0, size - 1, l, r); }
};

int n, k;
vector<pii> road;
vector<short> side;
Tree t_r;
Tree t_l;
vector<set<pii>> e_end;
vector<set<pii>> e_start;

void add_edge(int i)
{
    e_end[road[i].f].insert({road[i].s, i});
    e_start[road[i].s].insert({-road[i].f, i});
    t_r.update(road[i].f, *e_end[road[i].f].rbegin());
    t_l.update(road[i].s, *e_start[road[i].s].rbegin());
}

void rem_edge(int i)
{   
    e_end[road[i].f].erase({road[i].s, i});
    e_start[road[i].s].erase({-road[i].f, i});
    if(e_end[road[i].f].empty()) t_r.update(road[i].f, NO_VAL);
    else t_r.update(road[i].f, *e_end[road[i].f].rbegin());
    if(e_start[road[i].s].empty()) t_l.update(road[i].s, NO_VAL);
    else t_l.update(road[i].s, *e_start[road[i].s].rbegin());
}

bool check_side(int x)
{
    t_r = Tree(n + 1);
    t_l = Tree(n + 1);
    e_start = vector<set<pii>>(n + 1);
    e_end = vector<set<pii>>(n + 1);
    for(int i = 0; i < k; i++) if(side[i] == x) add_edge(i);
    for(int i = 0; i < k; i++)
    {
        if(side[i] != x) continue;
        int l = road[i].f, r = road[i].s;
        pii max_r = t_r.query(l + 1, r - 1);
        pii min_l = t_l.query(l + 1, r - 1);
        min_l.f = -min_l.f;
        if(max_r.f > r || min_l.f < l) return false;
    }
    return true;
}

bool check_ans() { return (check_side(0) && check_side(1)); }

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    road.resize(k);
    side.resize(k, 2);
    for(int i = 0; i < k; i++) 
        cin >> road[i].f >> road[i].s;
    t_r = Tree(n + 1);
    t_l = Tree(n + 1);
    e_start.resize(n + 1);
    e_end.resize(n + 1);
}

int main()
{
    init();
    for(int i = 1; i < k; i++) add_edge(i);
    queue<int> q;
    int idx = 0;
    q.push(0); 
    side[0] = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        int l = road[curr].f, r = road[curr].s;
        pii max_r = t_r.query(l + 1, r - 1); 
        pii min_l = t_l.query(l + 1, r - 1);
        min_l.f = -min_l.f;
        while(max_r.f > r || min_l.f < l)
        {
            if(max_r.f > r)
            {
                q.push(max_r.s);
                side[max_r.s] = (side[curr] + 1) % 2;
                rem_edge(max_r.s);
                max_r = t_r.query(l + 1, r - 1);
            }
            else
            {
                q.push(min_l.s);
                side[min_l.s] = (side[curr] + 1) % 2;
                rem_edge(min_l.s);
                min_l = t_l.query(l + 1, r - 1);
                min_l.f = -min_l.f; 
            }
        }
        while(q.empty() && idx < k)
        {
            if(side[idx] == 2) 
            { 
                q.push(idx); 
                side[idx] = 0; 
                rem_edge(idx); 
            }
            idx++;
        }
    }
    if(!check_ans()) { cout << "NIE";return 0; }
    for(short& c : side) cout << ((c == 0) ? "N" : "S") << '\n';
    return 0;
}