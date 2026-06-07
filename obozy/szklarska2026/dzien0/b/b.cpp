#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const ll INF = INT_MAX;

int n;
string input;
vector<string> wzorce;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> input;
    wzorce.resize(n);
    for(int i = 0; i < n; i++)
        cin >> wzorce[i];
    if(n == 1)
    {
        ll ans = 0;
        for(int i = 0; i < input.size(); i++)
            if(input[i] != wzorce[0][i % wzorce[0].size()])
                ans++;
        cout << ans;
        return 0;
    }
    //0 1 2 3 4+
    vector<vector<ll>> dp(input.size() + 1, vector<ll>(5, INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    dp[0][4] = 0;
    for(int i = 1; i <= input.size(); i++)
    {   
        for(int x = 0; x < n; x++)
        {
            if(wzorce[x].size() > i) continue;
            ll mistakes = 0;
            ll curri = i - wzorce[x].size();
            ll cnt = 10;
            ll first = -1;
            ll last = -1;
            bool valid = true;
            for(int y = 0; y < wzorce[x].size(); y++)
            {
                cnt++;
                if(input[curri + y] != wzorce[x][y])
                {
                    if(cnt <= 4)
                    {
                        valid = false;
                        break;
                    }
                    if(first == -1)
                        first = y;
                    mistakes++;
                    last = y;
                    cnt = 0;
                }
            }

            if(!valid)
                continue;
            /* 
            jezeli valid to

            first = 4 wszystkie
            0 1 2 3 4
            = 3
            1 2 3 4
            = 2
            2 3 4
            = 1
            3 4
            = 0
            4

            */
            ll minBack = INF;
            //to sa wszystkie mozliwe cofniecia
            for(ll d = max(4 - first, 0LL); d <= 4; d++)
                minBack = min(minBack, dp[i - wzorce[x].size()][d]);
            ll endDist = min(4ULL, wzorce[x].size() - (last + 1));
            for(int d = 0; d <= endDist; d++)
                dp[i][d] = min(dp[i][d], mistakes + minBack);
        }
    }

    ll minAns = INF;
    for(int i = 0; i <= 4; i++)
    {
        minAns = min(minAns, dp[input.size()][i]);
    }
    cout << minAns;
    return 0;
}