#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXVAL = 5055;
void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<int> a_cnt(101);
    bool ans = false;
    if(n > 100) ans = true;
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
        a_cnt[a[i]]++;
        if(a_cnt[a[i]] > 1) ans = true;
    }
    if(ans) { cout << "YES\n"; return; }
    bitset<MAXVAL> dp;
    dp[0] = 1;
    for(int i = 1; i <= 100; i++)
    {
        if(a_cnt[i] == 0) continue;
        bitset<MAXVAL> next_dp = dp << i;
        if((dp & next_dp).any()) { ans = true; break; }
        dp |= next_dp;
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}