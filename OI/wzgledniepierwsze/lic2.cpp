#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll n, k, c;
unordered_map<ll, bool> prime;
int main()
{
    cin >> n;
    ll cntNonPrime = 0;
    for(ll i = 2; i * i <= n; i++)
    {
        if(prime[i]) continue;
        for(ll x = i * i; x <= n; x += i)
        {
            if(prime[x]) continue;
            prime[x] = true;
            cntNonPrime++;
        }
    }
    /* ll cntPrimes = 0;
    for(ll i = 1; i <= n; i++)
        if(!prime[i]) 
        {
            cout << i << ' ';
            cntPrimes++;
        }
    cout << cntPrimes << '\n'; */
    cout << n - cntNonPrime << '\n';
    return 0;
}