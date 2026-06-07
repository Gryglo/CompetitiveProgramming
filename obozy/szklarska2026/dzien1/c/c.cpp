#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int dp[MAXN][MAXN];
vector<int> adj[MAXN];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) 
    {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) dp[i][j] = -1;
        dp[i][i] = 0;
    }

    int max_szlakow = 0;
    for (int v = n - 1; v >= 0; v--) 
    {
        for (int u : adj[v]) 
        {
            if (u < v) continue;
            for (int x = n - 1; x >= v; x--) 
            {
                if (x == v) continue;
                if (dp[u][x] != -1) 
                {
                    int nowa_dlugosc = dp[u][x] + 1;
                    if (nowa_dlugosc > dp[v][x]) 
                    {
                        dp[v][x] = dp[x][v] = nowa_dlugosc;
                        if (nowa_dlugosc > max_szlakow) max_szlakow = nowa_dlugosc;
                    }
                }
            }
        }
    }
    cout << max_szlakow + 1;
    return 0;
}