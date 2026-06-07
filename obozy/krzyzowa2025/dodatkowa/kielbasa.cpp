#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int n;
vector<ll> ciag;
vector<vector<pair<ll, ll>>> stany;
int main()
{
    fastio;
    cin >> n;
    ciag.resize(n);
    for(int i = 0; i < n; i++)
        cin >> ciag[i];
    
    vector<ll> pref1(n);
    vector<ll> pref2(n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            pref1[0] = ciag[0];
        else
        {
            pref1[i] = pref1[i - 1];
            if(i % 2 == 0)
                pref1[i] += ciag[i];
        }
    }

    for(int i = 1; i < n; i++)
    {
        if(i == 1)
            pref2[1] = ciag[1];
        else
        {
            pref2[i] = pref2[i - 1];
            if((i + 1) % 2 == 0)
                pref2[i] += ciag[i];
        }
    }
    if(n % 2 != 0)
    {
        cout << pref1[n - 1] << ' ' << pref2[n - 1];
        return 0;
    }

    /* 
        

    4
    7 6 3 9
    0 1 0 1
6
5 3 1 2 4 2
        0 1 0 1 0 1
          3 1 2 4
    */
    vector<pair<ll, ll>> stany(n / 2);
    int l = n / 2 - 1;
    int r = l + 1;
    stany[0] = { ciag[l] + ciag[r], 0 };
    l--;
    r++;
    for(int i = 1; i < n / 2; i++)
    {
        //ZABIERAMY PRAWA KIELBASKE
        ll mojZyskP, zyskPrzeciwnikaP, mojZyskL, zyskPrzeciwnikaL;
        ll zyskP, zyskL;
        bool przypadek = (i % 2 == 0);
        if((n / 2) % 2 == 0) przypadek = !przypadek;
        if(przypadek) //to z parzystych na P i z nieparzystych na L
        {
            mojZyskP = ciag[r] + pref2[r - 1];
            zyskPrzeciwnikaP = pref1[r - 1];
            if(l > 0) {
                mojZyskP -= pref2[l - 1];
                zyskPrzeciwnikaP -= pref1[l - 1];
            }
            zyskP = mojZyskP - zyskPrzeciwnikaP;
            mojZyskL = ciag[l] + pref1[r] - pref1[l];
            zyskPrzeciwnikaL = pref2[r] - pref2[l];
            zyskL = mojZyskL - zyskPrzeciwnikaL;
        }
        else //s nieparzyste, r na parzystym
        {
            mojZyskP = ciag[r] + pref1[r - 1];
            zyskPrzeciwnikaP = pref2[r - 1];
            if(l > 0) {
                mojZyskP -= pref1[l - 1];
                zyskPrzeciwnikaP -= pref2[l - 1];
            }
            zyskP = mojZyskP - zyskPrzeciwnikaP;
            mojZyskL = ciag[l] + pref2[r] - pref2[l];
            zyskPrzeciwnikaL = pref1[r] - pref1[l];
            zyskL = mojZyskL - zyskPrzeciwnikaL;
        }
        ll maxZysk, maxMojZysk, maxZyskPrzeciwnika;
        if(mojZyskP > mojZyskL)
        {
            maxZysk = zyskP;
            maxMojZysk = mojZyskP;
            maxZyskPrzeciwnika = zyskPrzeciwnikaP;
        }
        else
        {
            maxZysk = zyskL;
            maxMojZysk = mojZyskL;
            maxZyskPrzeciwnika = zyskPrzeciwnikaL;
        }

        ll mojZyskParzysty = ciag[l] + ciag[r] + stany[i - 1].s;
        ll zyskPrzeciwnikaParzysty = stany[i - 1].f;
        ll zyskParzysty = mojZyskParzysty - zyskPrzeciwnikaParzysty;

        if(zyskParzysty > maxZysk)
            stany[i] = {mojZyskParzysty, zyskPrzeciwnikaParzysty};
        else
            stany[i] = {maxMojZysk, maxZyskPrzeciwnika};

        l--;
        r++;
    }
    cout << stany[n / 2 - 1].f << ' ' << stany[n / 2 - 1].s;
    return 0;
}