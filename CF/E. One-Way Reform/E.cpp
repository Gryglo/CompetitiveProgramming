#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n));
    vector<int> tin(n), tout(n);
    vector<int> cnt(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a][b] = true;
        adj[b][a] = true;
        cnt[a]++;
        cnt[b]++;
    }
    vector<vector<int>> g(n);
    bool finito = false;
    while(!finito)
    {
        finito = true;
        queue<int> q;
        vector<bool> vis;
        for(int i = 0; i < n; i++)
        {
            if(cnt[i] % 2 == 0)
            {
                finito = false;
                q.push(i);
                break;
            }
        }

        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(int u = 0; u < n; u++)
            {
                if(!adj[v][u]) continue;
                adj[v][u] = false;
                adj[u][v] = false;
                cnt[v]--;
                cnt[u]--;
                if(cnt[u] % 2 == 0)
                {
                    g[v].push_back(u);
                    q.push(u);
                }
                tout[v]++;
                tin[u]++;
            }   
            if(cnt[v] % 2 != 0)
            {   
                for(int u = 0; u < n; u++)
                {
                    if(!adj[v][u]) continue;
                    cnt[v]--;
                    cnt[u]--;
                    if(cnt[u] % 2 == 0)
                    {
                        g[u].push_back(v);
                        q.push(u);
                    }
                    tout[u]++;
                    tin[v]++;
                }   
            }
        }
    }
}

int32_t main()
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}