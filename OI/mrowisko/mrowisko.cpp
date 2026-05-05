#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int MAXN = 1000000 + 5;
int n, g;
ll k;

vector<int> g_cnt;
vector<vector<int>> adj;

int v1, v2;

vector<ll> divs;

void DFS(int v, int p, ll div)
{
    if(adj[v].size() == 1)
    {
        divs.push_back(div);
        return;
    }
    div *= adj[v].size() - 1;
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS(u, v, div);
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> g >> k;
    adj.resize(n);
    g_cnt.resize(g);
    for(int i = 0; i < g; i++)
        cin >> g_cnt[i];
    sort(g_cnt.begin(), g_cnt.end());
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        if(i == 0)
        {
            v1 = a; v2 = b;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(v1, v2, 1);
    DFS(v2, v1, 1);
    ll ans = 0;
    //9
    //przedzial [k * 9, (k + 1) * 9]
    for(int i = 0; i < divs.size(); i++)
    {
        int minL = n, maxR = -1;

        int l = 0, r = g - 1;
        while(l <= r) //first true
        {
            int m = (l + r) / 2;
            if(g_cnt[m] / divs[i] >= k)
            {
                minL = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        l = 0, r = g - 1;
        while(l <= r) //last true
        {
            int m = (l + r) / 2;
            if(g_cnt[m] / divs[i] <= k) // 1 2 3 4 5 6 8 10 15
            {
                maxR = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        if(minL <= maxR)
            ans += (maxR - minL + 1);
    }
    cout << ans * k;
    return 0;
}