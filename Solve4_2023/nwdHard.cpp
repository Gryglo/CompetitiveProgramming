#include <iostream>
#define ll long long

using namespace std;
ll phi(ll n) 
{
    ll result = n;
    for (ll prime = 2; prime * prime <= n; prime++) 
    {
        if (n % prime == 0) 
        {
            while (n % prime == 0) 
                n = n / prime;
            result = result - (result / prime);
        }
    }


    if (n > 1) //Jezeli pierwsza
        result -= result / n;

    return result;
}

ll phiInRange(ll l, ll r, ll b) 
{
    ll result = (r / b) * phi(b) + phi(r % b);
    if (l > 1)
    {
        l--;
        result -= (l / b) * phi(b) + phi(l % b);
    }
    return result;
}

int main()
{
    ll l, r, a, b; 
    cin >> l >> r >> a >> b;

    if(b % a != 0)
    {
        cout << '0';
        return 0;
    }
    b /= a;

    l = (l + a - 1) / a;
    r /= a;

    cout << (r / b) * phi(b) + phi(r % b) - ((l - 1) / b) * phi(b) - phi((l - 1) % b);

    //cout << "L: " << l << " " << "R: " << r << " " << "B: " << b << " " << "A: " << a;


    return 0;
}