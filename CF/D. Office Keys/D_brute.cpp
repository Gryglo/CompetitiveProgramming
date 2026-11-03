#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e14;
int n, k, finish_pos;
vector<int> p, c;
int calc_dist(int start, int mid, int finish)
{
    return abs(start - mid) + abs(mid - finish);
}
void init()
{
    cin >> n >> k >> finish_pos;
    p.resize(n); c.resize(k);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < k; i++) cin >> c[i];
    sort(p.begin(), p.end());
    sort(c.begin(), c.end());
}

int32_t main()
{
    init();
    vector<vector<int>> dp(n, vector<int>(k, INF));
    for(int i = 0; i < k; i++)
        dp[0][i] = calc_dist(p[0], c[i], finish_pos);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int z = 0; z < j; z++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][z], calc_dist(p[i], c[j], finish_pos)));
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < k; i++) ans = min(ans, dp[n - 1][i]);
    cout << ans << '\n';
    return 0;
}
