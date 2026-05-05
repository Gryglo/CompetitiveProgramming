#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;
const int MAXN = 100005;
const ll MOD = 1001;
ll n;
ll d, a, b;
vector<ll> mem(MAXN);

ll solve(int x)
{   
    if(x == 1)
        return 0;
    if(mem[x] != 0)
        return mem[x];
    ll ans = INF;
    for(int i = 1; i < x; i++)
    {
        ll second = x - i;
        if(abs(second - i) > d) continue;
        ll val = (i * a + second * b) % MOD;
        if(val + solve(i) + solve(second) <= ans)
            ans = val + solve(i) + solve(second);
    }
    mem[x] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> a >> b;
    if(a > b) swap(a, b);
    mem[2] = (a + b) % MOD;
    cout << solve(n);
    /* for(int x = 1; x <= n; x++)
    {
        solve(x);
    }
    for(int x = 1; x <= n; x++)
    {
        cout << "Optimal for x = " << x << '\n';
        for(int i = 1; i < x; i++)
        {
            ll second = x - i;
            if(abs(second - i) > d) continue;
            ll val = (i * a + second * b) % MOD;
            if(val + solve(i) + solve(second) <= mem[x])
            {
                cout << i << ' ' << second << '\n';
            }
        }
    } */
    return 0;
}