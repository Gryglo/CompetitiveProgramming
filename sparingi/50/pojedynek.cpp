#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second
//MAXLOG = 17 => 2^18 = 262144
int MAXLOG = 0;
int MAXPOW = 1;

const int BUCKETLOG = 10;

int n, q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    while(2 * MAXPOW <= n)
    {
        MAXLOG++;
        MAXPOW *= 2;
    }
    //BUCKETLOG = MAXLOG / 2;
    int dp[n][BUCKETLOG + 1];
    //vector<vector<int>> dp(n, vector<int>(BUCKETLOG + 1));
    for(int i = 0; i < n; i++)
        cin >> dp[i][0];

    for(int x = 1; x <= min(BUCKETLOG, MAXLOG); x++)
    {
        int currSize = 1 << x;
        int prevSize = 1 << (x - 1);
        int r = n - currSize;
        for(int i = 0; i <= r; i++)
            dp[i][x] = abs(dp[i][x - 1] - dp[i + prevSize][x - 1]);
    }

    while(q--)
    {
        int type; cin >> type;
        if(type == 1)
        {
            int i, r; cin >> i >> r;
            i--;
            dp[i][0] = r;
            for(int x = 1; x <= min(BUCKETLOG, MAXLOG); x++)
            {
                int currSize = 1 << x;
                int prevSize = 1 << (x - 1);
                int l = max(i - currSize + 1, 0);
                int r = min(i, n - currSize);
                for(int y = l; y <= r; y++)
                    dp[y][x] = abs(dp[y][x - 1] - dp[y + prevSize][x - 1]);
            }
        }
        else
        {
            int i, k; cin >> i >> k;
            i--;
            if(k <= BUCKETLOG)
                cout << dp[i][k] << '\n';
            else
            {
                int targetSize = 1 << k;
                vector<pii> q;
                int currSize = 1 << BUCKETLOG;
                int segments = targetSize / currSize;
                for(int y = 0; y < segments; y++)
                {
                    int curri = i + y * currSize;
                    int bsize = currSize;
                    int curr = dp[curri][BUCKETLOG];
                    while(!q.empty() && q.back().s == bsize)
                    {
                        curr = abs(curr -  q.back().f);
                        q.pop_back();
                        bsize *= 2;
                    }   
                    q.push_back({curr, bsize});
                }
                cout << q.back().f << '\n';
            }
        }
    }
    return 0;
}