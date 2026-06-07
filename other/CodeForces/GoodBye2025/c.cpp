#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = INT_MAX;
void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> pref(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0) pref[0] = a[i];
        else pref[i] = pref[i - 1] + abs(a[i]);
    }
    ll ans = -INF; ll sum = 0;
    for(int i = n - 1; i > 0; i--)
    {
        ans = max(ans, pref[i - 1] + sum);
        sum += -a[i];
    }
    ans = max(ans, sum);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}