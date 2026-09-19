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
    vector<int> pref(n); pref[0] = b[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + b[i];
    vector<int> ans(n);
    vector<int> diff(n);
    for(int i = 0; i < n; i++)
    {
        //a[i] = curr
        int max_i = -1;
        int l = i, r = n - 1;
        int offset = (i > 0) ? pref[i - 1] : 0;
        while(l <= r)
        {
            int m = (l + r) / 2;
            if(pref[m] - offset <= a[i])
            {
                max_i = m; 
                l = m + 1;
            }
            else r = m - 1;
        }
        if(max_i == -1)
        {
            ans[i] += a[i];
            continue;
        }
        diff[i]++;
        //max_i + 1 juz zeruje
        if(max_i < n - 1) 
        {
            diff[max_i + 1]--;
            int to_rem = (pref[max_i] - offset);
            ans[max_i + 1] += (a[i] - to_rem);
        }
    }
    for(int i = 1; i < n; i++) diff[i] = diff[i - 1] + diff[i];
    for(int i = 0; i < n; i++)
    {
        ans[i] = ans[i] + diff[i] * b[i];
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