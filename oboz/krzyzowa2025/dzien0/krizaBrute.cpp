#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const int MAXN = 100'005;

int n;
ll k;
vector<int> ciag;
int main()
{
    fastio;
    cin >> n >> k;
    ciag.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> ciag[i];
        ciag[i]--;
    }
    ll ans = 0;
    int x = 0;
    for(ll i = 0; i < k; i++)
    {
        while(ciag[x] != (i % n))
        {
            x++;
            x = x % n;
            ans++;
        }
    }
    cout << ans;
    return 0;
}