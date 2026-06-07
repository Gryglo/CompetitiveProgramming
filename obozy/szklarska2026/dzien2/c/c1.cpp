#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int T, N, M;
const ll INF = LLONG_MAX;

vector<int> dp;

ll ask(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M)
        return INF;
    if(dp[y] != 0) return dp[y];
    cout << "? " << x << ' ' << y << endl;
    ll res; cin >> res; 
    dp[y] = res;
    return res;
}

void print_ans(int x, int y)
{
    cout << "! " << x << ' ' << y << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> N >> M; //dlugosc m
    int lastMin = 2;
    dp.resize(M + 1);
    if(N == 1)
    {
        int l = 1, r = M;
        while(l <= r)
        {
            int m = (l + r) / 2;
            ll m_val = ask(1, m);
            ll l_val = ask(1, m - 1);
            ll r_val = ask(1, m + 1);
            if(m_val < r_val && m_val < l_val)
            {
                print_ans(1, m);
                return 0;
            }
            if(r_val < m_val)
            {
                lastMin = m + 1;
                l = m + 1;
            }
            else
            {
                lastMin = m - 1;
                r = m - 1;
            }
        }
    }
    print_ans(1, lastMin);
    return 0;
}