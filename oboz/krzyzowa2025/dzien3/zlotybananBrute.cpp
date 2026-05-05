#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const ll MOD = 1e9 + 9;

int main()
{
    fastio;
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    vector<int> perm(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        perm[i] = i;
    }
    
    ll ans = 0;
    do
    {
        bool add = true;
        for(int i = 0; i < n - 1; i++)
        {
            if(a[perm[i]] + d < a[perm[i + 1]])
            {
                add = false;
                break;
            }
        }
        if(add)
            ans = (ans + 1) % MOD;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans;
    return 0;
}