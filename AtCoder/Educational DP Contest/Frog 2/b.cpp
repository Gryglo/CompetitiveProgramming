#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = i - 1; j >= max(0LL, i - k); j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }   
    cout << dp[n - 1];
    return 0;
}