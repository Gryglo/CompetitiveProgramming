#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const ld INF = 1e15;

int n, m;
vector<vector<ld>> graph;

bool isNegativeCycle(ld decrease)
{
    vector<vector<ld>> dist(n, vector<ld>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                dist[i][j] = INF;
            else
                dist[i][j] = graph[i][j] - decrease;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0.0)
        {
            return true;
        }
    }
    return false; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    graph.assign(n, vector<ld>(n, INF));

    for(int i = 0; i < m; i++)
    {
        int u, v;
        ld w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u][v] = min(graph[u][v], w);
    }

    if (!isNegativeCycle(2000000.0))
    {
        cout << "NIE\n";
        return 0;
    }

    ld l = 0.0, r = 1000000.0;
    ld result = r;

    for(int step = 0; step < 70; step++)
    {
        ld mid = (l + r) / 2.0;
        if(isNegativeCycle(mid))
        {
            result = mid;
            r = mid;
        }
        else
        {
            l = mid; 
        }
    }

    cout << fixed << setprecision(8) << result << "\n";
    return 0;
}