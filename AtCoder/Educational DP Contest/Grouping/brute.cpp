#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int>> a;
int calc_mask(int mask)
{
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if((mask & (1 << i)) > 0)
        {
            for(int j = i + 1; j < n; j++)
            {
                if((mask & (1 << j)) > 0)
                {
                    res += a[i][j];
                }
            }
        }
    }
    return res;
}
int ans = 0;
void solve(int mask, vector<int>& subsets)
{
    if(__builtin_popcount(mask) == n)
    {
        int res = 0;
        // cerr << "Rozwiazanie: \n";
        for(int curr : subsets)
        {
            // bitset<3> test = curr;
            // cerr << test << '\n';
            res += calc_mask(curr);
        }
        // cerr << '\n';
        ans = max(ans, res);
    }
    for(int i = 0; i < n; i++)
    {
        if((mask & (1 << i)) == 0)
        {
            subsets.push_back((1 << i));
            solve(mask | (1 << i), subsets);
            subsets.pop_back();
            if(subsets.size() > 0)
            {
                subsets.back() = subsets.back() | (1 << i);
                solve(mask | (1 << i), subsets);
                subsets.back() = subsets.back() ^ (1 << i);
            }
        }
    }
}


void init()
{
    cin >> n;
    a.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

int32_t main()
{
    init();
    vector<int> subsets;
    solve(0, subsets);
    cout << ans;
    return 0;
}