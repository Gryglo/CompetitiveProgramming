#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n; cin >> n;
    vector<int> a1(n), a2(n);
    for(int i = 0; i < n; i++) cin >> a1[i]; 
    for(int i = 0; i < n; i++) cin >> a2[i];
    vector<vector<ll>> dp(2, vector<ll>(n));
    dp[0][0] = a1[0];
    dp[1][0] = a2[0];
    for(int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + a1[i]);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + a2[i]);
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]);
    return 0;
}