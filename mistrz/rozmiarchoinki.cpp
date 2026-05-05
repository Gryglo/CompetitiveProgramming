#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int ask(ll x)
{
    cout << "? " << x << endl;
    char ans; cin >> ans;
    if(ans == '<') return 0;
    if(ans == '>') return 1;
    return 2;
}

int main()
{
    ll n; cin >> n;
    ll l = 1, r = n;
    while (l <= r) 
    {
        ll m = (l + r) / 2;
        int ans = ask(m);
        if (ans == 2) return 0;
        if (ans == 0) r = m - 1;
        else l = m + 1;
    }
    return 0;
}