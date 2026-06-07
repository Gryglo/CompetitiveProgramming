#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> N >> M; //dlugosc m
    dp.resize(N + 5, vector<ll>(M + 5, 0));
    
    int l_x = 1, r_x = N;
    int l_y = 1, r_y = M;
    ll globalMin = INF;
    pii globalMinPos = {0, 0};
    while(l_x <= r_x && l_y <= r_y)
    {
        if((r_x - l_x) > (r_y - l_y)) //row
        {
            int m_x = (l_x + r_x) / 2;
            //[m_x, -]
            ll currMin = INF;
            ll minPos = 0;
            for(int y = l_y; y <= r_y; y++)
            {
                ll curr = ask(m_x, y);
                if(curr < currMin)
                {
                    currMin = curr; minPos = y;
                }
            }
            ll left_val = ask(m_x, minPos - 1);
            ll right_val = ask(m_x, minPos + 1);
            ll up_val = ask(m_x - 1, minPos);
            ll down_val = ask(m_x + 1, minPos);
            if(currMin < up_val && currMin < down_val 
                && currMin < left_val && currMin < right_val)
            {
                print_ans(m_x, minPos);
                return 0;
            }

            if(up_val < down_val)
                r_x = m_x - 1;
            else
                l_x = m_x + 1;
        }
        else
        {
            int m_y = (l_y + r_y) / 2;
            //[m_x, -]
            ll currMin = INF;
            ll minPos = 0;
            for(int x = l_x; x <= r_x; x++)
            {
                ll curr = ask(x, m_y);
                if(curr < currMin)
                {
                    currMin = curr; minPos = x;
                }
            }
            ll left_val = ask(minPos, m_y - 1);
            ll right_val = ask(minPos, m_y + 1);
            ll up_val =  ask(minPos - 1, m_y);
            ll down_val =  ask(minPos + 1, m_y);
            if(currMin < left_val && currMin < right_val 
                && currMin < up_val && currMin < down_val
            )
            {
                print_ans(minPos, m_y);
                return 0;
            }

            if(up_val < down_val)
                r_x = m_x - 1;
            else
                l_x = m_x + 1;  
        }
    }
    print_ans(globalMinPos.f, globalMinPos.s);
    return 0;
}