#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    ll S;
    cin >> S;
    ll temp = S; 
    vector<ll> div;
    for(ll i = 2; i * i <= S; i++)
    {
        if(S % i == 0)
        {
            div.push_back(i);
            div.push_back(S / i);
        }
    }
    sort(div.begin(), div.end());
    cout << div.size() << '\n'; 
    for(ll d : div) cout << d << ' ';
    return 0;
}