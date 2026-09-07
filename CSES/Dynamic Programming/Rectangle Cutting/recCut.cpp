#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    for(int i = 1; i <= n; i++) dp[i][1] = i;
    for(int i = 1; i <= m; i++) dp[1][i] = i;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == j) { dp[i][j] = 0; continue; }
            for(int x = 1; x <= i / 2; x++)
                dp[i][j] = min(dp[i][j], dp[i - x][j] + dp[x][j] + 1);
            for(int x = 1; x <= j / 2; x++)
                dp[i][j] = min(dp[i][j], dp[i][j - x] + dp[i][x] + 1);
        }
    }
    cout << dp[n][m];
    return 0;
}