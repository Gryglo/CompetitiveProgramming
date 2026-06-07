#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 50010;
const int MAXK = 25;

int n, k;
int ciag[MAXN];
int dp[MAXK][MAXN];
int fenwickTree[MAXK][MAXN];

void update(int currK, int idx, int val) 
{
    while (idx < MAXN) 
    {
        fenwickTree[currK][idx] = (fenwickTree[currK][idx] + val) % MOD;
        idx += idx & -idx;
    }
}

int query(int idx, int currK) 
{
    int result = 0;
    while (idx > 0) 
    {
        result = (result + fenwickTree[currK][idx]) % MOD;
        idx -= idx & -idx;
    }
    return result;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) 
        cin >> ciag[i];

    int result = 0;

    for (int i = n; i >= 1; --i) 
    {
        int Ai = ciag[i];
        dp[1][i] = 1;
        update(1, Ai, dp[1][i]);

        for (int currK = 2; currK <= k; ++currK)
        {
            dp[currK][i] = query(Ai - 1, currK - 1);
            update(currK, Ai, dp[currK][i]);
        }
    }
    for (int i = 1; i <= n; ++i) 
        result = (result + dp[k][i]) % MOD;
    cout << result;

    return 0;
}
