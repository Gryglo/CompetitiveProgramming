/*************************************************************************}
{*                                                                       
{*   Zadanie: Zapiekanki (zap)                                           
{*   Score:   20                                                        
{*   Link:    https://szkopul.edu.pl/problemset/problem/w-dbshXVyRol4LIT9jeP-bNn/site/?key=statement                   
{*                                                                       
{*************************************************************************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = INT_MAX * 1e9;
int k, z;
ll d, n;
vector<ll> zap;
vector<ll> pref;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> z >> d;
    zap.resize(k);
    for(int i = 0; i < k; i++) cin >> zap[i];
    n = zap[k - 1] + d * ceil((double)k / z);
    pref.resize(k + 1);
    for(int i = 0; i < k; i++) pref[i + 1] = pref[i] + zap[i];
}

int main()
{
    init();
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 2));
    int lk = k - 1;
    for(int x = n; x >= 0; x--)
    {
        while(lk >= 0 && x + d < zap[lk]) lk--;
        for(int i = k - 1; i >= 0; i--)
        {
            if(x > n - d) { dp[i][x] = INF; continue; }
            int j = min(i + z - 1, lk);
            ll cost = (j - i + 1) * (x + d) - (pref[j + 1] - pref[i]);
            dp[i][x] = min(dp[i][x + 1], (lk == -1) ? INF : dp[j + 1][x + d] + cost);
        }
    }
    cout << dp[0][0];
}