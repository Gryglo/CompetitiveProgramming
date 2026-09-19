#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            ans[j] += min(a[i], b[j]);
            a[i] -= b[j];
            if(a[i] <= 0) break;
        }
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}