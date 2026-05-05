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
    stany.resize(n, vector<pair<ll, ll>>(n));
    //STANY POCZATKOWE 1, 2, 3
    for(int i = 0; i < n; i++)
        stany[i][i] = { ciag[i], 0 };
    for(int i = 0; i + 1 < n; i++)
        stany[i][i + 1] = { ciag[i] + ciag[i + 1], 0 };
    for(int i = 0; i + 2 < n; i++)
        stany[i][i + 2] = { ciag[i] + ciag[i + 2], ciag[i + 1] };

    for(int s = 4; s <= n; s++)
    {
        for(int i = 0; i + s - 1 < n; i++)
        {   
            int r = i + s - 1;
            //3 ruchy
            ll mojZysk, zyskPrzeciwnika;
            //PRAWA kielbasa
            mojZysk = stany[i][r - 1].s + ciag[r];
            zyskPrzeciwnika = stany[i][r - 1].f;
            ll zysk = mojZysk - zyskPrzeciwnika;
            //LEWA KIELUBASKA
            if(stany[i + 1][r].s + ciag[i] - stany[i + 1][r].f > zysk)
            {
                mojZysk = stany[i + 1][r].s + ciag[i];
                zyskPrzeciwnika = stany[i + 1][r].f;
                zysk = mojZysk - zyskPrzeciwnika;
            }
            if(stany[i + 1][r - 1].s + ciag[i] + ciag[r] - stany[i + 1][r - 1].f > zysk)
            {
                mojZysk = stany[i + 1][r - 1].s + ciag[i] + ciag[r];
                zyskPrzeciwnika = stany[i + 1][r - 1].f;
                zysk = mojZysk - zyskPrzeciwnika;
            }
            stany[i][r] = {mojZysk, zyskPrzeciwnika};
        }
    }
    cout << stany[0][n - 1].f << " " << stany[0][n - 1].s; 
    return 0;
}