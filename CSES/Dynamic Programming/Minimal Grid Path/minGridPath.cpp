#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 9;
const int MAXLEN = 6000 + 10;
const ll POW = 31;
vector<ll> P(MAXLEN);

int n;
vector<vector<ll>> dp;
vector<vector<int>> board;
vector<vector<bool>> parent; //true -> left, false-> up
ll mod_multi(ll a, ll b) { return (a * b) % MOD; }
ll mod_add(ll a, ll b) { return (a + b) % MOD; }

void compute_p()
{
    P[0] = 1;
    for(int i = 1; i < MAXLEN; i++) P[i] = mod_multi(P[i - 1], POW);
}

void init()
{
    compute_p();
    cin >> n;
    board.resize(n, vector<int>(n));
    dp.resize(n, vector<ll>(n));
    parent.resize(n, vector<bool>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char x; cin >> x;
            board[i][j] = (x - 'A' + 1);
        }
    }
}

int main()
{
    init();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //i + j + 1 dlugosc sciezki
            ll curr_min = INF;
            if(i > 0) curr_min = dp[i - 1][j];
            if(j > 0 && dp[i][j - 1] < curr_min)
            {
                curr_min = dp[i][j - 1];
                parent[i][j] = true;
            }
            if(i == 0 && j == 0) curr_min = 0;
            int path_len = i + j;
            dp[i][j] = mod_add(curr_min, mod_multi(P[MAXLEN - 1 - path_len], board[i][j]));
        }
    }
    
    vector<char> ans;
    int i = n - 1, j = n - 1;
    while(i != 0 || j != 0)
    {
        ans.push_back(board[i][j] + 'A' - 1);
        if(parent[i][j]) j--;
        else i--;
    }
    ans.push_back(board[i][j] + 'A' - 1);
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    /*
    26*32*32*32*32*32 + 31^6

    26*32^5 + 31^6

    26*(31 + 1)^5

    887503681
    872415232


    31 * 31*31 + 31^3*26*32*32 + 31^6

    
    */
    return 0;
}