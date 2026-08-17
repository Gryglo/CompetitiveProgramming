#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int a_sum = a[n - 1], b_sum = b[m - 1];
    for(int i = 0; i < n - 1; i++) a_sum += a[i] - a[i + 1] + 1;
    for(int i = 0; i < m - 1; i++) b_sum += b[i] - b[i + 1] + 1;
    if(a_sum == b_sum || a_sum > b_sum) cout << 1 << '\n';
    else cout << 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}