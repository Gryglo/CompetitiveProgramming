#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
int n;
vector<char> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    char prev = 0;
    for(int i = 0; i < n; i++)
    {
        char x; cin >> x;
        if(prev != x) a.push_back(x);
        prev = x;
    }
    n = a.size();
}


int32_t main()
{
    init();
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) dp[i][i] = 1;
    for(int d = 2; d <= n; d++)
    {
        for(int i = 0; i + d - 1 < n; i++)
        {
            int l = i, r = i + d - 1;
            dp[l][r] = min(dp[l][r - 1] + 1, dp[l + 1][r] + 1);
            for(int j = i + 2; j <= r; j++)
            {
                if(a[j] == a[l]) dp[l][r] = min(dp[l][r], dp[l + 1][j] + dp[j][r] - 1);
            }
            for(int j = r - 2; j >= l; j--)
            {
                if(a[j] == a[r]) dp[l][r] = min(dp[l][r], dp[j][r - 1] + dp[l][j] - 1);
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}