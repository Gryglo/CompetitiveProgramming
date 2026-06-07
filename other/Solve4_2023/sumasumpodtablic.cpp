#include <iostream>
#define ll unsigned long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll wynik = 0;
    for(ll i = 0; i < n; i++)
    {
        ll value;
        cin >> value;
        wynik += ((n-i)*(i+1) * value);
    }
    cout << wynik;
    return 0;
}