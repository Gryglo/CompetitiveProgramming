#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
struct Point
{
    int x, y, g_i;
    Point(int x1, int y1, int g_i1)
    {
        x = x1;
        y = y1; 
        g_i = g_i1;
    }
    Point(){}
};
const int INF = 10e9;
int n, d;
vector<Point> p;
vector<vector<pii>> adj;
bool sort_x(const Point& a, const Point& b)
{
    return a.x < b.x;
}
int new_node()
{
    adj.push_back(vector<pii>());
    return adj.size() - 1;
}
void add_edge(int v, int u, int c, vector<vector<pii>>& g)
{
    g[v].push_back({u, c});
    g[u].push_back({v, c});
}
void connect_p(int& i, int& k, vector<Point>& order, int& curr_i)
{
    int d = abs(k - p[i].x);
    int u = new_node();
    add_edge(p[i].g_i, u, d, adj);
    if(curr_i > 0) add_edge(u, u - 1, p[i].y - order[curr_i - 1].y, adj);
    order[curr_i++] = p[i];
    i++;
}
void merge(int l, int r)
{
    if(l == r) return;
    int m = (l + r) / 2;
    int k = p[m].x;
    merge(l, m);
    merge(m + 1, r);
    int l_i = l, r_i = m + 1, curr_i = 0;
    vector<Point> order(r - l + 1);
    while(l_i <= m && r_i <= r) connect_p((p[l_i].y <= p[r_i].y) ? l_i : r_i, k, order, curr_i);
    while(l_i <= m) connect_p(l_i, k, order, curr_i);
    while(r_i <= r) connect_p(r_i, k, order, curr_i);
    for(int i = l; i <= r; i++) p[i] = order[i - l];
}

vector<vector<pii>> compressed_g;
void compress_g()
{
    compressed_g.resize(n);
    priority_queue<pii> pq;
    vector<int> dist(adj.size(), INF);
    vector<int> parent(adj.size(), INF);
    vector<bool> vis(adj.size(), false);
    for(int i = 0; i < n; i++)
    {
        pq.push({0, i});
        dist[i] = 0;
        parent[i] = i;
        vis[i] = true;
    }
    while(!pq.empty())
    {
        pii curr = pq.top();
        pq.pop();
        int v = curr.s;
        if(dist[curr.s] < -curr.f) continue;
        vis[v] = true;
        for(pii e : adj[v])
        {
            if(vis[e.f] && parent[e.f] != parent[v])
                if(dist[v] + e.s + dist[e.f] <= d)
                    add_edge(parent[e.f], parent[v], dist[v] + e.s + dist[e.f], compressed_g);
            if(dist[e.f] > dist[v] + e.s)
            {
                dist[e.f] = dist[v] + e.s;
                parent[e.f] = parent[v];
                pq.push({-dist[e.f], e.f});
            }
        }
    }
}
void BFS(int v, vector<bool>& vis)
{   
    queue<int> q;
    vis[v] = true;
    q.push(v);
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(pii e : compressed_g[v])
        {
            if(!vis[e.f]) 
            {
                vis[e.f] = true;
                q.push(e.f);
            }
        }
    }
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    p.resize(n);
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        p[i] = Point(x, y, i);
    }
    adj.resize(n);
}
int32_t main()
{
    init();
    sort(p.begin(), p.end(), sort_x);
    merge(0, n - 1);
    compress_g();
    int ans = 0;
    vector<bool> vis(n);
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            BFS(i, vis);
            ans++;
        }
    }
    cout << ans;
    return 0;
}