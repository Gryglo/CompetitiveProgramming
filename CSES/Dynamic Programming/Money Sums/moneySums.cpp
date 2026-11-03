#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_VAL = 100005;
int n;
vector<int> coins;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    coins.resize(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
}
int32_t main()
{
    init();
    vector<bool> dp(MAX_VAL + 1);
    dp[0] = true;
    for(int coin : coins)
        for(int i = MAX_VAL; i - coin >= 0; i--)
            dp[i] = max(dp[i], dp[i - coin]);
    int ans = 0;
    for(int i = 1; i <= MAX_VAL; i++)
        if(dp[i]) ans++;
    cout << ans << '\n';
    for(int i = 1; i <= MAX_VAL; i++)
        if(dp[i]) cout << i << ' ';
    return 0;
}