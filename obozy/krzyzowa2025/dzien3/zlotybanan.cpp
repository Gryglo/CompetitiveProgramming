#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const ll MOD = 1e9 + 9;

void modulo_multiply(ll& v, ll u)
{
    v = ((v % MOD) * (u % MOD)) % MOD;
}

ll silnia(int v)
{
    ll s = 1;
    for(int i = 1; i <= v; i++)
        modulo_multiply(s, i);
    return s;
}

int main()
{
    fastio;
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    vector<int> maxJump(n);
    maxJump[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--)
    {
        //curr = a[i]
        ll x = a[i] + d;
        int l = i, r = n - 1;
        while(l < r)
        {
            int m = (l + r) / 2;
            if(l + 1 == r)
            {
                if(a[r] <= x)
                    l = r;
                break;
            }
            if(a[m] <= x)
                l = m;
            else
                r = m - 1;
        }
        //l to nasz skok
        maxJump[i] = l;
    }
    ll ans = 1;
    for(int i = 0; i < n; i++)
    {
        modulo_multiply(ans, maxJump[i] - i + 1);
    }
    cout << ans;
    return 0;
}