#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

void solve()
{
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) 
    {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());

    vector<char> ans(n, 'A');

    int cnt0 = 0;
    while (cnt0 < n && a[cnt0].f == 0) cnt0++;

    if (cnt0 == 1) 
    {
        cout << "NO\n";
        return;
    }

    if (cnt0 == 0) 
    {
        cout << "YES\n";
        for (char c : ans) cout << c;
        cout << '\n';
        return;
    }

    ans[a[0].s] = 'A';
    ans[a[1].s] = 'B';
    for (int i = 2; i < cnt0; i++) ans[a[i].s] = 'A';
    int idx = cnt0;
    int curVal = 1;
    while (idx < n) 
    {
        ans[a[idx].s] = 'C';
        idx++;
    }

    cout << "YES\n";
    for (char c : ans) cout << c;
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while (q--) solve();
    return 0;
}