#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

ll n, K;
int main()
{
    fastio;
    cin >> n >> K;
    vector<ll> ciag(n);
    vector<ll> pref(n);

    bool increase = true;
    for(int i = 0; i < n; i++)
    {
        cin >> ciag[i];
        if(i == 0)
            pref[0] = ciag[i];
        else
        {
            if(ciag[i - 1] > ciag[i])
                increase = false;
            pref[i] = pref[i - 1] + ciag[i];
        }
    }

    /* for(int i = 0; i < n; i++)
    {
        cout << pref[i] << ' ';
    } */
    
    ll ans = 0;
    if(increase)
    {
        for(int i = n - 1; i >= n - K; i--)
        {
            if(pref[i] > 0)
                ans += pref[i];
            else
                break;
        }
        cout << ans;
        return 0;
    }
    
    sort(pref.begin(), pref.end());
    for(int i = n - 1; i >= n - K; i--)
    {
        if(pref[i] > 0)
            ans += pref[i];
        else
            break;
    }
    
    cout << ans;
}