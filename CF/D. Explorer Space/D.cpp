#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e12;
int n, m, k;
vector<vector<int>> r_move, d_move;

bool in_grid(int x, int y)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    r_move.resize(n, vector<int>(m, INF));
    d_move.resize(n, vector<int>(m, INF));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m - 1; j++)
            cin >> r_move[i][j];

    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m; j++) 
            cin >> d_move[i][j];
}
int32_t main()
{
    init();
    if(k % 2 != 0)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++) 
                cout << -1 << ' ';
            cout << '\n';
        }
        return 0;
    }
    k = k / 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            dp[i][j][0] = 0;
    
    for(int ck = 1; ck <= k; ck++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(in_grid(i + 1, j)) dp[i][j][ck] = min(dp[i][j][ck], dp[i + 1][j][ck - 1] + 2 * d_move[i][j]);
                if(in_grid(i - 1, j)) dp[i][j][ck] = min(dp[i][j][ck], dp[i - 1][j][ck - 1] + 2 * d_move[i - 1][j]);
                if(in_grid(i, j + 1)) dp[i][j][ck] = min(dp[i][j][ck], dp[i][j + 1][ck - 1] + 2 * r_move[i][j]);
                if(in_grid(i, j - 1)) dp[i][j][ck] = min(dp[i][j][ck], dp[i][j - 1][ck - 1] + 2 * r_move[i][j - 1]);
            }   
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << dp[i][j][k] << ' ';
        cout << '\n';
    }
    return 0;
}