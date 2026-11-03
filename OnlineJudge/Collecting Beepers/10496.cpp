#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;
int man_dist(pii& a, pii& b)
{
    return abs(a.f - b.f) + abs(a.s - b.s);
}

void calc_dist(vector<pii>& a, vector<vector<int>>& adj_m)
{
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < a.size(); j++)
            adj_m[i][j] = man_dist(a[i], a[j]);
}

void compute_masks(int n, int r, int j, int curr_mask, vector<int>& masks)
{
    if(r == 0)
    {
        masks.push_back(curr_mask);
        return;
    }
    for(int i = j; i < n; i++)
    {
        if((curr_mask & (1 << i)) > 0) continue;
        compute_masks(n, r - 1, i + 1, curr_mask | (1 << i), masks);
    }
}

void compute_dp(vector<vector<int>>& adj_m, vector<vector<int>>& dp)
{
    int n = adj_m.size();
    int N = 1 << n;
    dp.resize(n + 1, vector<int>(N, INF));
    for(int i = 0; i < n; i++)
    {
        if(i == 0) continue;
        dp[i][1 | (1 << i)] = adj_m[0][i];
    }

    for(int r = 3; r <= n; r++)
    {
        vector<int> masks;
        compute_masks(n, r, 0, 0, masks);
        for(int mask : masks)
        {
            bitset<5> test1 = mask;
            for(int i = 1; i < n; i++)
            {
                if((mask & (1 << i)) == 0) continue;
                int curr_mask = mask & (~(1 << i));
                bitset<5> test = curr_mask;
                for(int j = 1; j < n; j++)
                {
                    if((curr_mask & (1 << j)) > 0)
                    {
                        dp[i][mask] = min(dp[i][mask], dp[j][curr_mask] + adj_m[i][j]);
                    }
                }
            }
        }
    }
}   

void solve()
{
    pii s_pos;
    cin >> s_pos.f >> s_pos.s;
    cin >> s_pos.f >> s_pos.s;
    int n; cin >> n;
    vector<pii> a(n + 1);
    a[0] = s_pos;
    for(int i = 1; i <= n; i++) cin >> a[i].f >> a[i].s;
    vector<vector<int>> adj_m(n + 1, vector<int>(n + 1));
    calc_dist(a, adj_m);
    vector<vector<int>> dp;
    compute_dp(adj_m, dp);
    int N = (1 << (n + 1));
    int ans = INF;
    for(int i = 1; i < n + 1; i++)
    {
        ans = min(ans, dp[i][N - 1] + adj_m[0][i]);
    }
    cout << "The shortest path has length " << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}