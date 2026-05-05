#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const ll INF = ULLONG_MAX;
const ll MOD = 1001;
ll n;
ll d, a, b;
unordered_map<ll, ll> mem;

ll solve(ll x)
{
    if(x == 1)
        return 0;
    if(x == 2)
        return (a + b) % MOD;
    if(mem.find(x) != mem.end())
        return mem[x];
    //x dlugosc
    //wszystkie dlugosci od x/2 do 1
    ll ans = INF;
    for(ll i = x/2; i > 0 && (x - 2*i) <= d; i--) //max roznica
    {
        //i jest mniejsze, a < b
        ll val = (((x - i) % MOD) * a + (i % MOD) * b) % MOD;
        ll add = solve(x - i) + solve(i);
        ans = min(ans, val + add);
        val = ((i % MOD) * a + ((x - i) % MOD) * b) % MOD;
        ans = min(ans, val + add);
    }
    mem[x] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> a >> b;
    cout << solve(n);
    return 0;
}