#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int t;
const ll MAXN = 1000007;
const ll MOD = 1e9 + 7;
const ll P = 31;
vector<ll> power(MAXN);
void computePowers()
{
    power[0] = 1;
    for(int i = 1; i < MAXN; i++)
        power[i] = (((power[i - 1] * P) % MOD) + MOD) % MOD;
}

void hashString(const string& a, vector<ll>& aHash)
{
    for(int i = 1; i <= a.size(); i++)
        aHash[i] = (((aHash[i - 1] + (a[i - 1] - 'a' + 1) * power[i - 1]) % MOD) + MOD) % MOD;
}

void solve()
{
    string a;
    cin >> a;
    vector<ll> aHash(a.size() + 1);
    hashString(a, aHash);

    ll ans = 0;
    int l = 0, r = a.size() - 1;
    int suffS = 1;
    while(l + suffS - 1 < r)
    {
        if(a[l] == a[r])
        {
            //porownujemy hashe
            ll firstHash = (((aHash[l + 1 + suffS - 1] - aHash[l + 1 - 1]) % MOD) + MOD) % MOD;
            ll secondHash = (((aHash[r + 1 + suffS - 1] - aHash[r + 1 - 1]) % MOD) + MOD) % MOD;
            firstHash = (((firstHash * power[r - l]) % MOD) + MOD) % MOD;
            if(firstHash == secondHash)
            {
                ans += 2;
                l = l + suffS;
                r--;
                suffS = 1;
            }
            else
            {
                r--;
                suffS++;
            }
        }
        else
        {
            r--;
            suffS++;
        }
    }
    if(l <= r)
        ans++;
    cout << ans << '\n';
}
int main()
{
    fastio;
    computePowers();
    cin >> t;
    while(t--)
        solve();
    return 0;
}