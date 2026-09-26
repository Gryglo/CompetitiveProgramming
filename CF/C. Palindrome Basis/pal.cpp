#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 50000;
const int MOD = 1e9 + 7;
vector<int> moves;
void compute_numbers()
{
    for(int i = 1; i <= 9; i++) moves.push_back(i);
    for(int i = 1; i <= 9; i++) moves.push_back(10 * i + i);
    for(int i = 1; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
            moves.push_back(100 * i + 10 * j + i);
    for(int i = 1; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
            moves.push_back(1000 * i + 100 * j + 10 * j + i);
    for(int i = 1; i <= 5; i++)
        for(int j = 0; j <= 9; j++)
            for(int k = 0; k <= 9; k++)
                moves.push_back(10000 * i + 1000 * j + 100 * k + 10 * j + i);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    compute_numbers();
    vector<int> dp(MAXN + 1);
    dp[0] = 1;
    for(int move : moves)
        for(int i = 0; i <= MAXN - move; i++) 
            dp[i + move] = (dp[i + move] + dp[i]) % MOD;
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}