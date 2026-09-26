#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
using state = pair<ll, pair<int, int>>;

const ll INF = 1e18;
int n, m;
vector<vector<pil>> adj;

ll dijkstra()
{
    priority_queue<state> pq;
    vector<vector<ll>> dist(2, vector<ll>(n, INF));
    pq.push({0, {0, 0}}); dist[0][0] = 0; dist[1][0] = 0;
    while(!pq.empty())
    {
        state curr = pq.top();
        pq.pop();
        if(dist[curr.s.f][curr.s.s] < -curr.f) continue;
        for(pil u : adj[curr.s.s])
        {
            if(dist[0][curr.s.s] + u.s < dist[0][u.f])
            {
                dist[0][u.f] = dist[0][curr.s.s] + u.s;
                pq.push({-dist[0][u.f], {0, u.f}});
            }
            if(dist[0][curr.s.s] + (u.s / 2) < dist[1][u.f])
            {
                dist[1][u.f] = dist[0][curr.s.s] + (u.s / 2);
                pq.push({-dist[1][u.f], {1, u.f}});
            }
            if(dist[1][curr.s.s] + u.s < dist[1][u.f])
            {
                dist[1][u.f] = dist[1][curr.s.s] + u.s;
                pq.push({-dist[1][u.f], {1, u.f}});
            }
        }
    }
    return dist[1][n - 1];
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c});
    }
}

int main()
{
    init();
    cout << dijkstra();
    return 0;
}