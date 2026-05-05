#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = INT_MAX;

int n;
vector<vector<int>> adj;
vector<int> t;
vector<bool> visited;
vector<int> inDeg;
vector<int> inDegTemp;
vector<ll> dp;
vector<ll> diffs;
bool cycle = false;

ll DFS(int v)
{
    visited[v] = true;
    if(dp[v] != 0)
        return dp[v];
    ll maxx = 0;
    for(int u : adj[v])
    {
        if(visited[u] && dp[u] == 0)
        {
            cycle = true;
            return 0;
        }
        maxx = max(maxx, DFS(u));
    }
    dp[v] = maxx + t[v];
    return dp[v];
}


void DFS2(int v, ll diff)
{
    diffs[v] = max(diffs[v], diff);
    if(inDegTemp[v] == 0)
    {
        ll currMax = 0;
        for(int u : adj[v])
            currMax = max(currMax, dp[u]);
        for(int u : adj[v])
        {
            inDegTemp[u]--;
            DFS2(u, diffs[v] - (currMax - dp[u]));
        }
    }
}

void init()
{
    adj.resize(n);
    t.resize(n);
    inDeg.resize(n);
    dp.resize(n);
    diffs.resize(n, -INF);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    init();
    bool whole_cycle = true;
    for(int i = 0; i < n; i++)
    {
        int ti, ki; cin >> ti >> ki;
        t[i] = ti;
        if(ki == 0)
            whole_cycle = false;
        inDeg[i] = ki;
        for(int j = 0; j < ki; j++)
        {
            int x; cin >> x; x--;
            adj[x].push_back(i);
        }
    }

    if(whole_cycle)
    {
        cout << "CYKL";
        return 0;
    }
    for(int v = 0; v < n; v++)
    {
        if(inDeg[v] == 0) 
        {
            visited.assign(n, false);
            DFS(v);
            if(cycle)
            {
                cout << "CYKL";
                return 0;
            }
        }
    }

    ll maxx = 0;
    for(int i = 0; i < n; i++)
        maxx = max(maxx, dp[i]);
    cout << maxx << '\n';

    inDegTemp = vector<int>(inDeg);
    for(int v = 0; v < n; v++)
        if(inDeg[v] == 0) 
            DFS2(v, dp[v] - maxx);

    int q; cin >> q;
    while(q--)
    {
        int v, x; cin >> v >> x; v--;
        if(diffs[v] + x > 0)
            cout << "TAK\n";
        else    
            cout << "NIE\n";
    }
    return 0;
}