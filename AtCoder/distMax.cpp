#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
    vector<ll> v1(n), v2(n);
    for(int i = 0; i < n; i++)
    {
        v1[i] = (a[i].f + a[i].s);
        v2[i] = (a[i].f - a[i].s);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << max(v1[n - 1] - v1[0], v2[n - 1] - v2[0]);
    /*
    ∣xi​ − xj​∣ + ∣yi ​− yj​∣ =
    
    (xi + yi​) − (xj​ ​+ yj)​
    (xj​ + yj​) - (xi + yi)​​
    ​(xi​ - yi) − (xj - yj)
    (xj​ - yj) - (xi - yi)​
    */
    return 0;
}