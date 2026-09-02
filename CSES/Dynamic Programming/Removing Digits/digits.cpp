#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e9;

int main()
{
    ll n; cin >> n;
    vector<ll> dp(n + 2, INF);
    dp[n] = 0;
    for(ll x = n; x >= 0; x--)
    {
        string curr = to_string(x);
        for(char c : curr)
        {
            int d = c - '0';
            if(x - d >= 0) dp[x - d] = min(dp[x - d], dp[x] + 1);
        }
    }   
    cout << dp[0]; 
    return 0;
}