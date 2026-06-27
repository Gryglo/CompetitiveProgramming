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
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 2, INF));
    for(int x = 0; x <= n; x++) dp[0][x] = 0;
    int lk = -1;
    for(int x = 0; x <= n - d; x++)
    {
        while(lk < k - 1 && zap[lk + 1] <= x + d) lk++;
        if(lk == -1) continue;
        for(int i = 0; i < k; i++)
        {
            int j = min(i + (z - 1), lk);
            ll cost = (j - i + 1) * (x + d) - (pref[j + 1] - pref[i]);
            dp[j + 1][x + d] = min(min(
                (x == 0) ? INF : dp[j + 1][x + d - 1], 
                (i > j) ? INF : dp[i][x] + cost), 
                dp[j + 1][x + d]);
        }
    }
    cout << dp[k][n];
}