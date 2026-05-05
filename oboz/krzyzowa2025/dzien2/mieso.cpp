#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using pli = pair<ll, int>;
using pil = pair<int, ll>;
#define f first
#define s second
const ll INF = LLONG_MAX;

int n, m;
vector<int> dirty;
vector<vector<pli>> adj;
vector<vector<int>> dag;
vector<int> toposort;
vector<int> inDeg;

void doTopoSort()
{
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        toposort.push_back(v);
        for(int u : dag[v])
        {
            inDeg[u]--;
            if(inDeg[u] == 0)
                q.push(u);
        }
    }
}

bool canBeMedian(int x)
{
    vector<ll> balanse(n, -INF);
    if(dirty[0] >= x)
        balanse[0] = 1;
    else
        balanse[0] = -1;
    for(int i = 0; i < n; i++)
    {
        int v = toposort[i];
        for(int u : dag[v])
        {
            ll newBalanse = balanse[v];
            if(dirty[u] >= x)
                newBalanse++;
            else
                newBalanse--;
            balanse[u] = max(balanse[u], newBalanse);
        }
    }
    return balanse[n - 1] > 0;
}

int main()
{
    fastio;
    cin >> n >> m;
    dirty.resize(n);
    for(int i = 0; i < n; i++)
        cin >> dirty[i];
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w; a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    //                -dist v
    priority_queue<pli> pq;
    vector<ll> dist(n, INF);
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty())
    {
        pli curr = pq.top();
        pq.pop();
        int v = curr.s;
        ll d = curr.f;
        for(pil edge : adj[v])
        {
            int u = edge.f;
            ll w = edge.s;
            if(dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                pq.push({-(dist[v] + w), u});
            }
        }
    }
    dag.resize(n);
    inDeg.resize(n);
    for(int i = 0; i < n; i++)
    {
        for(pil edge : adj[i])
        {
            int u = edge.f;
            ll w = edge.s;
            if(dist[u] == dist[i] + w)
            {
                dag[i].push_back(u);
                inDeg[u]++;
            }
        }
    }
    doTopoSort();

    int l = 1, r = 1e9;
    while(l < r)
    {
        int m = (l + r) / 2;
        if(l + 1 == r)
        {
            if(canBeMedian(r))
                l = r;
            break;
        }
        if(!canBeMedian(m))
            r = m - 1;
        else
            l = m;
    }
    cout << dist[n - 1] << ' ' << l;

}