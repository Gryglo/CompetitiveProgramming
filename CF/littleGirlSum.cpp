#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n, q;
vector<int> a;
vector<int> pref;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    pref.resize(n);
    for(int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r; l--;
        pref[l]++;
        if(r < n) pref[r]--;
    }
}

int32_t main()
{
    init();
    for(int i = 1; i < n; i++) pref[i] = pref[i] + pref[i - 1];
    sort(pref.begin(), pref.end());
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i] * pref[i];
    cout << sum;
    return 0;
}