#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second
#define int long long


void solve()
{
    int n; 
    cin >> n;
    int sumA = 0, sumB = 0;
    vector<pii> profit(n);
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].f;
        sumA += a[i].f;
        profit[i].f = a[i].f;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].s;
        sumB += a[i].s;
        profit[i].f += a[i].s;
        profit[i].s = i;
    }
    sort(profit.begin(), profit.end());

    bool alice = true;
    for(int i = n - 1; i >= 0; i--)
    {
        if(alice)
        {
            sumB -= a[profit[i].s].s;
            sumA--;
            alice = false;
        }
        else
        {
            sumA -= a[profit[i].s].f;
            sumB--;
            alice = true;
        }
    }
    cout << sumA - sumB << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
        solve();
    return 0;
}