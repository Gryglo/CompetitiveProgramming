#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int mask1 = 1; mask1 < (1 << n); mask1++)
    {
        vector<int> curr;
        for(int i = 0; i < n; i++)
            if(mask1 & (1 << i)) curr.push_back(a[i]);
        for(int mask2 = 1; mask2 < (1 << curr.size()); mask2++)
        {
            int left = 0, right = 0;
            for(int i = 0; i < curr.size(); i++)
            {
                if(mask2 & (1 << i)) right += curr[i];
                else left += curr[i];
            }
            if(left == right)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}