#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
}

int32_t main()
{   
    init();
    vector<vector<int>> dp(n, vector<int>(n));
    for(int x = 2; x <= n; x++)
    {
        for(int l = 0; l + x - 1 < n; l++)
        {
            int r = l + x - 1;
            int add_v = a[r] - a[l];
            dp[l][r] = min(
                dp[l][r - 1] + add_v, 
                dp[l + 1][r] + add_v);
        }
    }
    cout << dp[0][n - 1];
    return 0;
}