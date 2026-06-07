#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

ll n, K;
int main()
{
    fastio;
    cin >> n >> K;
    vector<ll> ciag(n);
    vector<ll> pref(n);

    bool increase = true;
    for(int i = 0; i < n; i++)
    {
        cin >> ciag[i];
        if(i == 0)
            pref[0] = ciag[i];
        else
        {
            if(ciag[i - 1] > ciag[i])
                increase = false;
            pref[i] = pref[i - 1] + ciag[i];
        }
    }
    
    ll ans = 0;
    vector<vector<ll>> dp(n, vector<ll>(K + 1));
    dp[0][1] = pref[0];
    for(int i = 1; i < n; i++)
    {
        for(int k = 1; k <= K; k++)
        {
            //dp[i][k]
            dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - 1] + pref[i]);
            ans = max(ans, dp[i][k]);
        }
    }
    cout << ans;
}