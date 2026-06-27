/*************************************************************************}
{*                                                                       
{*   Zadanie: Zapiekanki (zap)                                           
{*   Score:   92
{*   Link:    https://szkopul.edu.pl/problemset/problem/w-dbshXVyRol4LIT9jeP-bNn/site/?key=statement                   
{*                                                                       
{*************************************************************************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, ll>;
#define f first
#define s second

const ll INF = LLONG_MAX;

int k, z;
ll d;
vector<ll> zap;
vector<vector<pli>> dp;
void init()
{
    cin >> k >> z >> d;
    zap.resize(k);
    for(int i = 0; i < k; i++) cin >> zap[i];
    dp.resize(k + 3);
}

pli calc_state(int r, ll curr_c, int i, int x)
{
    return {
        curr_c + max(0LL, (dp[i - x][r].s + d) - zap[i - 1]) * x + dp[i - x][r].f,
        max(zap[i - 1], dp[i - x][r].s + d)
    };
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    dp[0].push_back({0, 0});
    for(int i = 1; i <= k; i++)
    {
        ll curr_c = 0;
        vector<pli> good;
        for(int x = 1; x <= min(z, i); x++)
        {
            curr_c += zap[i - 1] - zap[i - x];
            for(int r = 0; r < dp[i - x].size(); r++) 
                good.push_back(calc_state(r, curr_c, i, x));
        }
        sort(good.begin(), good.end());
        ll min_t = INF;
        for(int y = 0; y < good.size(); y++)
        {
            if(good[y].s < min_t)
            {
                dp[i].push_back(good[y]);
                min_t = good[y].s;
            }
        }
    }
    cout << dp[k][0].f;
}