#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string a;
int c_to_i(char x)
{
    return (x - 'a');
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    n = a.size();
}
int32_t main()
{
    init();
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(26, vector<vector<int>>(26, vector<int>(27))));
    set<string> ans;
    dp[n] = vector<vector<vector<int>>>(26, vector<vector<int>>(26, vector<int>(27, true)));
    if(n - 2 >= 5)
    {
        dp[n - 2] = vector<vector<vector<int>>>(26, vector<vector<int>>(26, vector<int>(27, true)));
        dp[n - 2][c_to_i(a[n - 2])][c_to_i(a[n - 1])][26] = false;
        string new_s = string(1, a[n - 2]);
        new_s += a[n - 1];
        ans.insert(new_s);    
    }
    for(int i = n - 3; i >= 5; i--)
    {
        for(int x = 0; x < 26; x++)
        {
            for(int y = 0; y < 26; y++)
            {
                for(int z = 0; z < 26; z++)
                {
                    if(!(c_to_i(a[i]) == x && c_to_i(a[i + 1]) == y && c_to_i(a[i + 2]) == z))
                        dp[i][x][y][z] = max(dp[i + 3][x][y][z], dp[i + 2][x][y][z]);
                    else
                    {
                        string new_s = string(1, a[i]);
                        new_s += a[i + 1];
                        new_s += a[i + 2];
                        if(dp[i + 3][x][y][z]) ans.insert(new_s);
                        dp[i][x][y][z] = dp[i + 2][x][y][z]; 
                    }
                }
                if(!(c_to_i(a[i]) == x && c_to_i(a[i + 1]) == y))
                    dp[i][x][y][26] = max(dp[i + 3][x][y][26], dp[i + 2][x][y][26]);
                else
                {
                    string new_s = string(1, a[i]);
                    new_s += a[i + 1];
                    if(dp[i + 2][x][y][26]) ans.insert(new_s);
                    dp[i][x][y][26] = dp[i + 3][x][y][26];
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(string x : ans)
        cout << x << '\n';
    return 0;
}