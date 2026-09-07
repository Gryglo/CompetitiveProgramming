#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector<vector<int>> dp(n + 2, vector<int>(m + 2));
    vector<vector<pii>> adj(n + 2, vector<pii>(m + 2));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dp[i - 1][j] >= dp[i][j]) 
            { dp[i][j] = dp[i - 1][j]; adj[i][j] = {i - 1, j}; }
            if(dp[i][j - 1] >= dp[i][j]) 
            { dp[i][j] = dp[i][j - 1]; adj[i][j] = {i, j - 1}; }
            if(a[i - 1] == b[j - 1] && dp[i - 1][j - 1] + 1 >= dp[i][j]) 
            { dp[i][j] = dp[i - 1][j - 1] + 1; adj[i][j] = {i - 1, j - 1}; }
        }
    }
    cout << dp[n][m] << '\n';
    if(dp[n][m] == 0) return 0;
    pii curr = { n, m };
    vector<int> ans;
    while(curr.f != 0 && curr.s != 0)
    {
        if(adj[curr.f][curr.s] == make_pair(curr.f - 1, curr.s - 1)) 
            ans.push_back(a[curr.f - 1]);
        curr = adj[curr.f][curr.s];
    }
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
    return 0;
}