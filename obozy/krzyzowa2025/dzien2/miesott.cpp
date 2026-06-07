#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using plm = pair<pair<ll, int>, vector<int>>;
using pii = pair<int, ll>;

const ll INF = LLONG_MAX;

int n, m;
vector<int> dirty;
vector<vector<pii>> adj;

ll dijkstra1(int start, int target)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<int, int>>> q;
    vector<ll> dist(n, INF); 
    q.push( { 0, start } );
    dist[start] = 0;
    while(!q.empty())
    {
        int v = q.top().second;
        q.pop();

        for(pair<int, ll> edge : adj[v])
        {
            int u = edge.first;
            ll w = edge.second;

            if(dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                q.push( { dist[u], u } );
            }
        }
    }
    return dist[target];
}

/* ll dijkstra2(int start, int target)
{
    priority_queue<pair<ll, pair<int, vector<int>>>, vector<pair<ll, pair<int, vector<int>>>>, greater<pair<int, int>>> q;
    vector<ll> dist(n, INF); 
    q.push( { 0, start } );
    dist[start] = 0;
    while(!q.empty())
    {
        int v = q.top().second;
        q.pop();

        for(pair<int, ll> edge : adj[v])
        {
            int u = edge.first;
            ll w = edge.second;

            if(dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                q.push( { dist[u], u } );
            }
        }
    }
    return dist[target];
} */


void subtask3()
{
    priority_queue<plm> pq;
    vector<ll> dist(n, INF); 
    vector<int> one(6);
    one[dirty[0]]++;
    pq.push({{0, 0}, one});
    dist[0] = 0;
    ll ansDist = INF;
    while(!pq.empty())
    {
        plm curr = pq.top();
        int v = curr.first.second;
        ll d = -curr.first.first;
        if(v == n - 1)
        {
            ansDist = d;
            break;
        }
        pq.pop();
        vector<int> median = curr.second;

        for(pair<int, ll> edge : adj[v])
        {
            int u = edge.first;
            ll w = edge.second;

            if(dist[u] >= d + w)
            {
                dist[u] = d + w;
                vector<int> median2(median);
                median2[dirty[u]]++;
                pq.push( {{-dist[u], u}, median2} );
            }
        }
    }

    int minMedian = 0;
    //mediana z nastepny
    while(!pq.empty())
    {
        plm curr = pq.top();
        int v = curr.first.second;
        ll d = -curr.first.first;
        if(d != ansDist || v != n - 1)
            break;
        pq.pop();
        vector<int> median = curr.second;
        ll elCnt = 0;
        for(int i = 0; i <= 5; i++)
            elCnt += median[i];
        //elcnt nieparzyste wiec
        ll targetIdx = elCnt / 2 + 1;
        ll currSum = 0;
        for(int i = 0; i <= 5; i++)
        {
            currSum += median[i];
            if(currSum >= targetIdx)
            {
                minMedian = max(minMedian, i);
                break;
            }
        }
    }
    cout << ansDist << ' ' << minMedian;
}

int main()
{
    fastio;
    cin >> n >> m;
    dirty.resize(n);
    bool isAllOne = true;
    bool allLowerThanFive = true;
    for(int i = 0; i < n; i++)
    {
        cin >> dirty[i];
        if(dirty[i] != 1)
            isAllOne = false;
        if(dirty[i] > 5)
            allLowerThanFive = false;
    }
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w; a--; b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a,w});
    }
    if(isAllOne)
    {
        cout << dijkstra1(0, n - 1) << " " << 1;
        return 0;
    }
    if(allLowerThanFive)
    {
        subtask3();
        return 0;
    }
    priority_queue<plm> pq;
    vector<ll> dist(n, INF); 
    vector<int> one;
    one.push_back(dirty[0]);
    pq.push({{0, 0}, one});
    dist[0] = 0;
    ll ansDist = INF;
    while(!pq.empty())
    {
        plm curr = pq.top();
        int v = curr.first.second;
        ll d = -curr.first.first;
        if(v == n - 1)
        {
            ansDist = d;
            break;
        }
        pq.pop();
        vector<int> median = curr.second;

        for(pair<int, ll> edge : adj[v])
        {
            int u = edge.first;
            ll w = edge.second;

            if(dist[u] >= d + w)
            {
                dist[u] = d + w;
                vector<int> median2(median);
                median2.push_back(dirty[u]);
                pq.push( {{-dist[u], u}, median2} );
            }
        }
    }

    int minMedian = 0;
    //mediana z nastepny
    while(!pq.empty())
    {
        plm curr = pq.top();
        int v = curr.first.second;
        ll d = -curr.first.first;
        if(d != ansDist || v != n - 1)
            break;
        pq.pop();
        vector<int> median = curr.second;
        auto m = median.begin() + median.size() / 2;
        nth_element(median.begin(), m, median.end());
        minMedian = max(minMedian, median[median.size() / 2]);
    }
    cout << ansDist << ' ' << minMedian;
}