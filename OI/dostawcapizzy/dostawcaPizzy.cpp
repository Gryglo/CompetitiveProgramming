#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
ll result = 0; 
vector<int> parent;
vector<vector<pair<int, int>>> adj;

//          dist  end_v
vector<pair<ll, int>> dist_down; 
vector<ll> dist_up;
vector<bool> taken;

//                profit  end_v
priority_queue<pair<ll, int>> paths;

pair<ll, int> DFS(int v, int p, ll distance)
{
    parent[v] = p;
    dist_up[v] = distance;

    pair<ll, int> max_dist_down = {0, -1};
    for(pair<int, int> u : adj[v])
    {
        if(u.first == p)
            continue;
        max_dist_down = max(DFS(u.first, v, distance + u.second), max_dist_down);
    }
    if(max_dist_down.second == -1)
    {
        dist_down[v] = {0, v};
        return {distance, v};
    }
    dist_down[v] = {max_dist_down.first - distance, max_dist_down.second};
    return max_dist_down;
}

void markPath(int v)
{
    if(v == -1 || taken[v])
        return;
    taken[v] = true;
    for(pair<int, int> u : adj[v])
    {
        if(u.first == parent[v] || taken[u.first])
            continue;
        ll currPathProfit = dist_down[u.first].first + u.second - dist_up[v];
        if(currPathProfit <= 0)
            continue;
        
        paths.push({currPathProfit, dist_down[u.first].second});
    }
    markPath(parent[v]);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        result += (w * 2);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    parent.resize(n);
    dist_up.resize(n);
    dist_down.resize(n);
    taken.resize(n);
    DFS(0, -1, 0);

    result -= dist_down[0].first;
    markPath(dist_down[0].second);

    for(int i = 1; i < k; i++)
    {
        if(paths.empty())
            break;
        pair<ll, int> newPath = paths.top();
        paths.pop();
        result -= newPath.first;
        markPath(newPath.second);
    }

    cout << result << '\n';
    return 0;
}