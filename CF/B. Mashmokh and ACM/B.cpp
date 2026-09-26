#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 2001;
int n, k;
vector<vector<int>> divs(MAXN + 1);
void compute_divs()
{   
    int cnt = 0;
    for(int i = 1; i <= MAXN; i++)
    {
        for(int j = 1; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                divs[i].push_back(j);
                if(i / j != j) divs[i].push_back(i / j);
            }
        }
        cnt += divs[i].size();
    }
    //cout << cnt;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
}

int32_t main()
{
    init();
    compute_divs();
    vector<int> dp(n + 1, 1);
    dp[0] = 0;
    //vector<vector<int>> dp(k, vector<int>(n + 1));
    for(int i = 1; i < k; i++)
    {
        vector<int> next_dp(n + 1);
        for(int j = 1; j <= n; j++)
            for(int x : divs[j]) next_dp[j] = (next_dp[j] + dp[x]) % MOD;
        dp = next_dp;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans + dp[i]) % MOD;
    cout << ans;
    return 0;
}