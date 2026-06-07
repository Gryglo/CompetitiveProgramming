#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int T, N, M;
const ll INF = LLONG_MAX;

vector<vector<ll>> dp;

ll ask(int x, int y)
{
    if(x < 1 || x > N || y < 1 || y > M)
        return INF;
    if(dp[x][y] != 0) return dp[x][y];
    cout << "? " << x << ' ' << y << endl;
    ll res; cin >> res; 
    dp[x][y] = res;
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
    pii lastMin = {0, 0};
    dp.resize(N + 1, vector<ll>(M + 1));
    
    int l_x = 1, r_x = N;
    int l_y = 1, r_y = M;

    while(l_x <= r_x && l_y <= r_y)
    {
        int m_x = (l_x + r_x) / 2;
        int m_y = (l_y + r_y) / 2;

        ll m_val = ask(m_x, m_y);
        ll l_val = ask(m_x, m_y - 1);
        ll r_val = ask(m_x, m_y + 1);
        ll u_val = ask(m_x - 1, m_y);
        ll d_val = ask(m_x + 1, m_y);
        ll minVal = min(m_val, min(l_val, min(r_val, min(u_val, d_val))));
        if(minVal == m_val)
        {
            print_ans(m_x, m_y);
            return 0;
        }
        if(minVal == l_val)
        {
            lastMin = {m_x, m_y - 1};
            r_y = m_y - 1;
        }
        else if(minVal == r_val)
        {
            lastMin = {m_x, m_y + 1};
            l_y = m_y + 1;
        }
        else if(minVal == u_val)
        {
            lastMin = {m_x - 1, m_y};
            r_x = m_x - 1;
        }
        else if(minVal == d_val)
        {
            lastMin = {m_x + 1, m_y};
            l_x = m_x + 1;
        }
    }
    print_ans(lastMin.f, lastMin.s);
    return 0;
}