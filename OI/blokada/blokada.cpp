#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = LLONG_MAX;

int n, m;
int maxMeetings;
vector<vector<int>> adj;
vector<vector<int>> t;
vector<int> depth;
vector<int> minDepth;
vector<int> childCount;
vector<bool> visited;

void DFS(int v, int currDepth) 
{
    visited[v] = true;
    depth[v] = currDepth;
    for (int u : adj[v]) 
    {
        if (!visited[u])
        {
            t[v].push_back(u);
            DFS(u, currDepth + 1);
            childCount[v] += childCount[u];
            minDepth[v] = min(minDepth[v], minDepth[u]);
        }
        else if (depth[u] < depth[v]) 
            minDepth[v] = min(minDepth[v], depth[u]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    maxMeetings = n * (n - 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.resize(n, false);
    t.resize(n);
    depth.resize(n);
    minDepth.resize(n, INF);
    childCount.resize(n, 1);
    minDepth[0] = -1;
    DFS(0, 0);

    for(int v = 0; v < n; v++)
    {
        //jezeli min depth jest wiekszy od depth to nie liczymy osobno tylko na koniec z reszta
        int rest = n - 1; //bo napewno juz tego jednego nie bedzie
        int result = 0;
        for(int u : t[v])
        {
            if(minDepth[u] < depth[v])
                continue;
            rest -= childCount[u];
            result += childCount[u] * (childCount[u] - 1);
        }

        result += rest * (rest - 1);
        cout << maxMeetings - result << '\n';
    }
    return 0;
}
