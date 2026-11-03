#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF = 1e14;
int n, m, k;
vector<int> c;
vector<vector<int>> p;
void init()
{
    cin >> n >> m >> k;
    c.resize(n);
    p.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> p[i][j];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    // n m k
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m + 1, vector<int>(k + 1, INF)));
    if(c[0] == 0)
        for(int i = 1; i <= m; i++) 
            dp[0][i][1] = p[0][i - 1];
    else dp[0][c[0]][1] = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(c[i] == 0)
            {
                for(int x = 1; x <= m; x++)
                {
                    dp[i][x][j] = min(dp[i][x][j], dp[i - 1][x][j] + p[i][x - 1]);
                    for(int y = 1; y <= m; y++)
                    {
                        if(y == x) continue;
                        dp[i][x][j] = min(dp[i][x][j], dp[i - 1][y][j - 1] + p[i][x - 1]);
                    }
                }
            }
            else
            {
                dp[i][c[i]][j] = min(dp[i][c[i]][j], dp[i - 1][c[i]][j]);
                for(int x = 1; x <= m; x++)
                {
                    if(c[i] == x) continue;
                    dp[i][c[i]][j] = min(dp[i][c[i]][j], dp[i - 1][x][j - 1]);
                }
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= m; i++)
        ans = min(ans, dp[n - 1][i][k]);
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}