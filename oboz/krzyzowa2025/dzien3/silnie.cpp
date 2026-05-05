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

vector<ll> silnie = {2, 2, 4};

int main()
{
    fastio;
    int n;
    cin >> n;
    cout << "vector<ll> silnie  = { 1, ";
    for(int i = 1; i <= n; i++)
    {
        cout << silnia(i) << ", ";
    }

    return 0;
}