#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
struct Point {
    int x, y, g_idx;
    Point(int x, int y, int idx) {
        this->x = x; this->y = y;
        this->g_idx = idx;
    }
    Point() { }
};
const int INF = 6e9;
int n;
vector<vector<pii>> adj;
vector<Point> p;

bool sort_points_x(const Point& a, const Point& b) {
    return a.x < b.x;
}

void add_edge(int v, int u, int c, vector<vector<pii>>& g)
{
    g[v].push_back({u, c});
    g[u].push_back({v, c});
}

int add_node()
{
    adj.push_back(vector<pii>());
    return adj.size() - 1;
}

void connect_p(int& i, int k, vector<Point>& new_order, int& curr_i) {
    int d = abs(k - p[i].x);
    int next_node = add_node();
    add_edge(p[i].g_idx, next_node, d, adj);
    if(curr_i > 0) add_edge(next_node, next_node - 1, p[i].y - new_order[curr_i - 1].y, adj);
    new_order[curr_i++] = p[i];
    i++;
}

void merge(int l, int r) {
    if(l == r) return;
    int m = (l + r) / 2;
    int k = p[m].x;
    merge(l, m); merge(m + 1, r);
    vector<Point> new_order(r - l + 1);
    int curr_i = 0;
    int l_i = l, r_i = m + 1;
    while(l_i <= m && r_i <= r) {
        if(p[l_i].y <= p[r_i].y) {
            connect_p(l_i, k, new_order, curr_i);
        }
        else {
            connect_p(r_i, k, new_order, curr_i);
        } 
    }
    while(l_i <= m) { connect_p(l_i, k, new_order, curr_i); }
    while(r_i <= r) { connect_p(r_i, k, new_order, curr_i); }
    for(int i = l; i <= r; i++) p[i] = new_order[i - l];
}

vector<vector<pii>> compressed_adj;
void dijkstra_compress_g()
{
    compressed_adj.resize(n);
    priority_queue<pii> pq;
    vector<pii> dist(adj.size(), { INF, INF });
    vector<bool> vis(adj.size());
    for(int i = 0; i < n; i++)
    {
        pq.push({0, i});
        vis[i] = true;
        dist[i] = {0, i};
    }

    while(!pq.empty())
    {
        pii curr = pq.top();
        pq.pop();
        if(dist[curr.s].f < -curr.f) continue;
        vis[curr.s] = true;
        for(pii e : adj[curr.s])
        {
            if(vis[e.f] && (dist[curr.s].s != dist[e.f].s))
                add_edge(dist[curr.s].s, dist[e.f].s, dist[curr.s].f + e.s + dist[e.f].f, compressed_adj);
            if(dist[curr.s].f + e.s < dist[e.f].f)
            {
                dist[e.f] = {dist[curr.s].f + e.s, dist[curr.s].s};
                pq.push({-dist[e.f].f, e.f});
            }
        }
    }

}

int min_tree_sum()
{
    priority_queue<pii> pq;
    vector<int> edge(n, INF);
    vector<bool> vis(n);
    pq.push({0, 0});
    edge[0] = 0;
    while(!pq.empty())
    {
        pii curr = pq.top();
        pq.pop();
        if(vis[curr.s]) continue;
        if(edge[curr.s] < -curr.f) continue;
        vis[curr.s] = true;
        for(pii e : compressed_adj[curr.s])
        {   
            if(!vis[e.f] && edge[e.f] > e.s)
            {
                edge[e.f] = e.s;
                pq.push({-edge[e.f], e.f});
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++) sum += edge[i];
    return sum; 
}

void init() {
    cin >> n;
    p.resize(n);
    for(int i = 0; i < n; i++) {   
        int x, y; cin >> x >> y;
        p[i] = Point(x, y, i);
    }
}

int32_t main() {
    init();
    adj.resize(n);
    sort(p.begin(), p.end(), sort_points_x);
    merge(0, n - 1);
    dijkstra_compress_g();
    cout << min_tree_sum();
    return 0;
}