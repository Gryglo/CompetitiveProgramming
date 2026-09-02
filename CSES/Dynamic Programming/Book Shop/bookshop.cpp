#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x; cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    vector<int> dp(x + 5);
    for(int j = 0; j < n; j++)
    {
        for(int i = x; i > 0; i--)
        {
            dp[i] = max(dp[i], dp[i - 1]);
            if(i >= price[j]) dp[i] = max(dp[i], pages[j] + dp[i - price[j]]);
        }
    }
    cout << dp[x];
}