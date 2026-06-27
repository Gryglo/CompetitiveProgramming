/*************************************************************************}
{*                                                                       
{*   Zadanie: Zapiekanki (zap)                                           
{*   Score:   100                                                        
{*   Link:    https://szkopul.edu.pl/problemset/problem/w-dbshXVyRol4LIT9jeP-bNn/site/?key=statement                   
{*                                                                       
{*************************************************************************/
#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;

const int INF = LLONG_MAX;
int k, z, d;
vector<int> zap;
vector<int> dp;
vector<int> pref;

void fill_oven(int& pos, int& li, int& cnt, int& cost)
{
    while(li < k - 1 && pos >= zap[li + 1] && cnt < z)
    { cost += pos - zap[++li]; cnt++; }
}

void handle_oven(int& pos, int& li, int& cnt, int& cost, int ti)
{
    fill_oven(pos, li, cnt, cost);
    while(pos + d <= zap[ti] - d && li < ti - 1 && zap[li + 1] <= zap[ti] - d)
    {
        if(pos < zap[li + 1] && zap[li + 1] <= zap[ti] - d)
        {
            long double diff = zap[li + 1] - pos;
            pos += ceil(diff / d) * d; 
            cnt = 0; 
        }
        else if(cnt == z) pos += d; cnt = 0; 
        fill_oven(pos, li, cnt, cost);
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> z >> d;
    zap.resize(k + 1);
    zap[k] = INF;
    for(int i = 0; i < k; i++) cin >> zap[i];
    pref.resize(k + 1);
    for(int i = 1; i <= k; i++) 
        pref[i] = pref[i - 1] + zap[i - 1];
    dp.resize(k + 2, INF);
}

int32_t main()
{
    init();
    dp[k + 1] = 0;
    for(int i = k - 1; i >= -1; i--)
    {
        int pos, cnt, li;
        if(i == -1) { pos = 0; cnt = z; li = -1; }
        else
        {
            if(zap[i] - d < 0) continue;
            pos = zap[i]; cnt = z; li = i;
        }
        int b_cost = 0;
        for(int j = i + 1; j <= k; j++)
        {
            handle_oven(pos, li, cnt, b_cost, j);
            if(pos > zap[j] - d) continue;
            if(j - li > z) continue;
            int next_b_cost = (j - li - 1) * zap[j] - (pref[j] - pref[li + 1]);
            dp[i + 1] = min(dp[i + 1], b_cost + next_b_cost + dp[j + 1]);
        }
    }
    cout << dp[0];
}

/* 
              x
0 1 2 3 4 5 6 7

(x - ti) + (x - t(i + 1)) + ...     i = (li + 1, j - 1)

x - ti + x - t(i + 1) + ...

|S| * x - ti - t(i + 1) -...        (j - li - 1) = |S|

|S| * x - (ti + t(i + 1) + ...)

sum[j - 1] - sum[li] = pref[j] - pref[li + 1]

*/