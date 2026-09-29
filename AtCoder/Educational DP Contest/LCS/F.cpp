#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b; cin >> a >> b;
    vector<vector<pair<int, pii>>> dp(a.size() + 1, vector<pair<int, pii>>(b.size() + 1));
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            if(a[i] == b[j]) dp[i + 1][j + 1] = {dp[i][j].f + 1, {i, j}};
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(
                make_pair(dp[i][j + 1].f, make_pair(i, j + 1)), 
                make_pair(dp[i + 1][j].f, make_pair(i + 1, j)))); 
        }
    }
    string ans;
    pii pos = {a.size(), b.size()};
    while(pos.f != 0 && pos.s != 0)
    { 
        pii next = dp[pos.f][pos.s].s;
        if(dp[pos.f][pos.s].f > dp[next.f][next.s].f) ans = a[pos.f - 1] + ans;
        pos = next;
    }
    cout << ans;
    return 0;
}