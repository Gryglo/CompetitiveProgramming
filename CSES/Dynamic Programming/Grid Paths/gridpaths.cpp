#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main()
{
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int x = 0; x < n; x++) for(int y = 0; y < n; y++) cin >> grid[x][y];
    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][0] = 1;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            if(grid[x][y] == '*') continue;
            if(x + 1 < n) dp[x + 1][y] = (dp[x + 1][y] + dp[x][y]) % MOD;
            if(y + 1 < n) dp[x][y + 1] = (dp[x][y + 1] + dp[x][y]) % MOD;
        }
    }
    cout << ((grid[n - 1][n - 1] == '*') ? 0 : dp[n - 1][n - 1]);
    return 0;
}