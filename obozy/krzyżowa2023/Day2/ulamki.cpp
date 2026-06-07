#include <iostream>

#define ll long long

ll NWD(ll a, ll b)
{
    while(b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll NWW(ll a, ll b)
{
    return a / NWD(a, b) * b;
}

using namespace std;
int main()
{
    ll licznik1, licznik2, mianownik1, mianownik2;
    cin >> licznik1 >> mianownik1 >> licznik2 >> mianownik2;
    ll mianownik = NWW(mianownik1, mianownik2);
    ll mnoznik_first = mianownik / mianownik1;
    ll mnoznik_second = mianownik / mianownik2;
    licznik1 *= mnoznik_first;
    licznik2 *= mnoznik_second;
    ll licznik = licznik1 + licznik2;
    ll wspolnyDzielnik = NWD(licznik, mianownik);
    licznik /= wspolnyDzielnik;
    mianownik /= wspolnyDzielnik;
    cout << licznik << " " << mianownik;
    return 0;    
}