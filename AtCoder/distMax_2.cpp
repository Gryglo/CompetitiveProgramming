#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
void rotate45(pii& p) { p = {p.f - p.s, p.f + p.s}; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
    for(int i = 0; i < n; i++) rotate45(a[i]);
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) { x[i] = a[i].f; y[i] = a[i].s; }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << max(x[n - 1] - x[0], y[n - 1] - y[0]);
    /*
    ∣xi​ − xj​∣ + ∣yi ​− yj​∣ =
    
    (xi + yi​) − (xj​ ​+ yj)​
    (xj​ + yj​) - (xi + yi)​​
    ​(xi​ - yi) − (xj - yj)
    (xj​ - yj) - (xi - yi)​
    */
    return 0;
}