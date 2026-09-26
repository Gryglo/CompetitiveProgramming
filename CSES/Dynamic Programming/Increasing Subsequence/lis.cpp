#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> a;
int lis()
{
    vector<int> dp;
    for(int x : a)
    {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}
int32_t main()
{
    init();
    cout << lis();
    return 0;
}