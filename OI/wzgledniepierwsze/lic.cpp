#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll n, k, c;
int main()
{
    cin >> n;
    vector<ll> div;
    ll temp = n;
    if(n % 2 == 0)
        div.push_back(2);
    while(n % 2 == 0)
        n /= 2;
    for(ll i = 3; i <= n; i+=2)
    {
        if(n % i == 0)
            div.push_back(i);
        while(n % i == 0)
            n /= i;
    }
    cout << div.size() << '\n';
    for(ll curr : div)
        cout << curr << ' ';
    return 0;
}