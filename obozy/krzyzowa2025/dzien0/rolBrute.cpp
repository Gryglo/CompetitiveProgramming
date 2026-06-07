#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const ll INF = LLONG_MAX;

ll n, m;
vector<ll> a;

bool checkX(ll x, ll restM, int zero)
{
    ll cnt = 0;
    vector<ll> t(a);
    t[zero] = 0;
    for(int i = 1; i < n; i++)
    {
        if(t[i] - t[i - 1] > x)
        {
            ll dec = t[i] - t[i - 1] - x;
            cnt += dec;
            t[i] = t[i] - dec;
        }
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(t[i] - t[i + 1] > x)
        {
            ll dec = t[i] - t[i + 1] - x;
            cnt += dec;
            t[i] = t[i] - dec;
        }
    }
    if(cnt <= restM)
    {
        for(int i = 1; i < n; i++)
            if(abs(a[i] - a[i - 1]) > x)
                return false;
        return true;
    }
    else
        return false;
}

int main()
{
    fastio;
    cin >> n >> m;
    ll maxH = 0;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxH = max(maxH, a[i]);
    }

    ll ans = INF;
    ll ansX = -1;
    for(int i = 0; i < n; i++)
    {
        //zerujemy i
        //i binserach minimalny wynik dla wyzerowanego tego i
        ll restM = m - a[i];
        if(restM < 0)
            continue;
        ll l = 0, r = maxH;
        while(l < r)
        {
            ll m = (l + r) / 2;
            if(checkX(m, restM, i))
                r = m;
            else
                l = m + 1;
        }
        if(ans > l)
        {
            ans = l;
            ansX = i;
        }
        //l to wynik
    }
    cout << ansX + 1 << ' ' << ans;
    return 0; 
}