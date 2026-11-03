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
void solve(int idx, int curr_res, vector<int>& subsets)
{
    if(idx == n)
    {
        ans = max(ans, curr_res);
        return;
    }
    subsets.push_back(1 << idx);
    solve(idx + 1, curr_res, subsets);
    subsets.pop_back();
    for(int& curr : subsets)
    {
        int add_res = 0;
        for(int j = 0; j < n; j++)
        {
            if((curr & (1 << j)) > 0)
                add_res += a[idx][j];
        }
        curr = curr | (1 << idx);
        curr_res += add_res;
        solve(idx + 1, curr_res, subsets);
        curr = curr ^ (1 << idx);
        curr_res -= add_res;
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
    solve(0, 0, subsets);
    cout << ans;
    return 0;
}