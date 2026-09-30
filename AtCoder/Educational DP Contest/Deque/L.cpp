#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n;
vector<int> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}
int32_t main()
{
    init();
    vector<vector<pii>> dp(n, vector<pii>(n));
    for(int i = 0; i < n; i++) dp[i][i] = {a[i], 0};
    for(int k = 1; k <= n; k++)
    {
        for(int i = 0; i + k < n; i++)
        {
            dp[i][i + k] = max(
                make_pair(a[i] + dp[i + 1][i + k].s, dp[i + 1][i + k].f), 
                make_pair(a[i + k] + dp[i][i + k - 1].s, dp[i][i + k - 1].f));
        }
    }
    cout << (dp[0][n - 1].f - dp[0][n - 1].s);
    return 0;
}