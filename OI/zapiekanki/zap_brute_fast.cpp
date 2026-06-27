/*************************************************************************}
{*                                                                       
{*   Zadanie: Zapiekanki (zap)                                           
{*   Score:   40                                                   
{*   Link:    https://szkopul.edu.pl/problemset/problem/w-dbshXVyRol4LIT9jeP-bNn/site/?key=statement                   
{*                                                                       
{*************************************************************************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = INT_MAX * 1e9;
int k, z;
ll d, n;
vector<int> zap;
vector<ll> pref;
vector<int> p;
vector<int> p_i;

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

void find_valid_pos()
{
    vector<bool> p_temp(n + 2);
    p_temp[0] = true;
    for(int x = d; x <= n; x += d) p_temp[x] = true;
    for(int i = 0; i < k; i++) 
    {
        for(int x = zap[i] - d; x <= n; x += d) 
        {
            if(x < 0) continue;
            if(p_temp[x]) break;
            p_temp[x] = true;
        }
    }
    p_i.resize(n + 2);
    int c_i = -1;
    for(int x = 0; x <= n; x++) 
    {
        if(p_temp[x]) { p.push_back(x); c_i++; }
        p_i[x] = c_i;
    }
}

int main()
{
    init();
    find_valid_pos();
    vector<vector<ll>> dp(k + 1, vector<ll>(p.size() + 2));
    int lk = k - 1;
    for(int x = p.size() - 1; x >= 0; x--)
    {
        while(lk >= 0 && p[x] + d < zap[lk]) lk--;
        for(int i = k - 1; i >= 0; i--)
        {
            if(p[x] > n - d) { dp[i][x] = INF; continue; }
            int j = min(i + z - 1, lk);
            ll cost = (j - i + 1) * (p[x] + d) - (pref[j + 1] - pref[i]);
            dp[i][x] = min(dp[i][x + 1], (lk == -1) ? INF : dp[j + 1][p_i[p[x] + d]] + cost);
        }
    }
    cout << dp[0][0];
}