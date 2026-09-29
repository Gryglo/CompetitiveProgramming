#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int n, m;
vector<vector<char>> board;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    board.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> board[i][j];
}
int32_t main()
{
    init();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == '#') continue;
            if(i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}