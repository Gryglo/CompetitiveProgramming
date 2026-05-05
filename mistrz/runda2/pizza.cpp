#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
const ll INF = 1e13;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    ll ans = -INF;
    ll sum = 0;
    vector<ll> minSums(n + 1);
    minSums[0] = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        minSums[i + 1] = min(minSums[i], sum);
        if(i + 1 >= k)
            ans = max(ans, sum - minSums[i + 1 - k]);
    }
    cout << ans;
    return 0;
}