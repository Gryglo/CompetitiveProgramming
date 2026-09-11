#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(vector<int>& a, vector<int>& b)
{
    int n = a.size();
    /*
    |a[i] - a[j]| + |b[i] - b[j]| + |i - j|
    
    |a[i] - a[j]| = 
    (a[i] - a[j])
    -a[i] + a[j]
    1.
    (a[i] + b[i] + i) - (a[j] + b[j] + j)
    (a[j] + b[j] + j) - (a[i] + b[i] + i)
    2.
    (a[i] - b[i] - i) - (a[j] - b[j] - j)
    -(a[i] - b[i] - i) + (a[j] - b[j] - j)
    3.
    (a[i] - b[i] + i) - (a[j] - b[j] + j)
    -(a[i] - b[i] + i) + (a[j] - b[j] + j)
    4.
    (a[i] + b[i] - i) - (a[j] + b[j] - j)
    -(a[i] + b[i] - i) + (a[j] + b[j] - j)
    */

    vector<ll> v1(n), v2(n), v3(n), v4(n);
    for(int i = 0; i < n; i++)
    {
        v1[i] = (a[i] + b[i] + i);
        v2[i] = (a[i] - b[i] - i);
        v3[i] = (a[i] - b[i] + i);
        v4[i] = (a[i] + b[i] - i);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    ll ans = 0;
    ans = max(ans, v1[n - 1] - v1[0]);
    ans = max(ans, v2[n - 1] - v2[0]);
    ans = max(ans, v3[n - 1] - v3[0]);
    ans = max(ans, v4[n - 1] - v4[0]);
    return ans;
}

int main()
{   
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    cout << solve(a, b);
    return 0;
}