#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x + 5, INF); dp[0] = 0;
    for(int coin : coins) 
        for(int i = coin; i <= x; i++) dp[i] = min(dp[i], dp[i - coin] + 1);
    cout << ((dp[x] == INF) ? -1 : dp[x]);
    return 0;
}