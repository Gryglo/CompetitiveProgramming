#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int n, x;
vector<int> a;
void LIS_pref(vector<int>& prefix)
{
    vector<int> lis;
    for (int i = 0; i < n; i++) 
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        prefix[i] = (it - lis.begin()) + 1;
        if (it == lis.end())
            lis.push_back(a[i]);
        else
            *it = a[i];
    }
}

void LIS_suff(vector<int>& suffix)
{
    vector<int> lis;
    for (int i = n - 1; i >= 0; i--) 
    {
        auto it = lower_bound(lis.begin(), lis.end(), -a[i]);
        suffix[i] =  (it - lis.begin()) + 1;
        it = lower_bound(lis.begin(), lis.end(), -a[i] - x);
        if (it == lis.end())
            lis.push_back(-a[i] - x);
        else
            *it = -a[i] - x;
    }
}


int32_t main()
{
    fastio;
    cin >> n >> x;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> lP(n);
    LIS_pref(lP);
    vector<int> lS(n);
    LIS_suff(lS);    

    /* for(int i = 0; i < n; i++)
        cout << lP[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++)
        cout << lS[i] << ' '; */

    int ans = 1;
    for(int i = 0; i < n; i++)
        ans = max(ans, lP[i] + lS[i] - 1);
    cout << ans;
    return 0;
}