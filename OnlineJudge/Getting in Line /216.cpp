#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using ld = long double;
using pii = pair<int, int>;
const ld INF = 100000;
int n, N;
int t = 1;
vector<pii> p;
vector<vector<ld>> dist;

ld calc_dist(pii a, pii b)
{
    ld x = (a.f - b.f) * (a.f - b.f);
    ld y = (a.s - b.s) * (a.s - b.s);
    return sqrt(x + y) + 16;
}

pair<ld, vector<int>> compute_dp(int v)
{
    vector<vector<pair<ld, int>>> dp(n, vector<pair<ld, int>>(N, {INF, -1}));
    for(int i = 0; i < n; i++)
    {
        int mask = (1 << v);
        mask |= (1 << i);
        dp[i][mask] = { dist[v][i], v };
    }

    for(int mask = 3; mask < N; mask++)
    {
        if((mask & (1 << v)) == 0) continue;
        if(__builtin_popcount(mask) < 3) continue;
        for(int i = 0; i < n; i++)
        {
            if(i == v) continue;
            if((mask & (1 << i)) == 0) continue;
            int prev_mask = mask ^ (1 << i);
            for(int j = 0; j < n; j++)
            {
                if(j == v) continue;
                if((prev_mask & (1 << j)) == 0) continue;
                dp[i][mask] = min(dp[i][mask], {dp[j][prev_mask].f + dist[j][i], j});
            }
        }
    }
    int end_v = -1;
    ld end_val = INF;
    for(int i = 0; i < n; i++)
    {
        if(dp[i][N - 1].f < end_val)
        {
            end_v = i;
            end_val = dp[i][N - 1].f;
        }
    }

    vector<int> path;
    int curr_v = end_v;
    int curr_mask = N - 1;
    while(curr_v != v)
    {
        path.push_back(curr_v);
        int new_mask = curr_mask ^ (1 << curr_v);
        curr_v = dp[curr_v][curr_mask].s;
        curr_mask = new_mask;
    }
    path.push_back(v);
    return {end_val, path};
}

void solve()
{
    N = 1 << n;
    p.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i].f >> p[i].s;
    dist.assign(n, vector<ld>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist[i][j] = calc_dist(p[i], p[j]);
        }
    }
    ld min_path = INF;
    vector<int> path;
    for(int i = 0; i < n; i++)
    {
        pair<ld, vector<int>> curr = compute_dp(i);
        if(curr.f < min_path)
        {
            min_path = curr.f;
            path = curr.s;
        }
    }
    
    cout << fixed << setprecision(2);
    cout << "**********************************************************\n";
    cout << "Network #" << t << '\n';
    for(int i = 0; i < n - 1; i++)
    {
        cout << "Cable requirement to connect (" << p[path[i]].f << "," << p[path[i]].s << ") to (" 
        << p[path[i + 1]].f << "," << p[path[i + 1]].s << ") is "<< dist[path[i]][path[i + 1]] << " feet.\n";
    }
    cout << "Number of feet of cable required is " << min_path << ".\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n != 0)
    {
        solve();
        cin >> n;
        t++;
    }
    return 0;
}