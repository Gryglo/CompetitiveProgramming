#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define f first
#define s second

ll n, X, z;

struct Miejsce
{
    long double space;
    ll startValue;
    ll iloscPozycji;
    ll startSpace;
};

class Compare 
{
public:
	bool operator()(Miejsce& a, Miejsce& b) 
    {
        if(a.space == b.space)
        {
            return a.startValue > b.startValue;
        }
        return a.space < b.space;
	}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> X >> z;
    priority_queue<Miejsce, vector<Miejsce>, Compare> pq;
    ll last;
    for(int i = 0; i < n; i++)
    {
        ll curr; cin >> curr;
        if(i > 0)
        {
            Miejsce noweMiejsce = {(long double)curr - last, last, 1, curr - last};
            pq.push(noweMiejsce);
        }
        last = curr;
    }
    ll maxQ = 0;
    vector<pll> zapytania(z);
    for(int i = 0; i < z; i++)
    {
        ll curr; cin >> curr;
        maxQ = max(maxQ, curr);
        zapytania[i] = {curr, i};
    }
    sort(zapytania.begin(), zapytania.end());
    vector<pll> ans(z);
    ll peopleCnt = 0;
    int qi = 0;
    while(qi < z)
    {
        Miejsce wolne = pq.top();
        while(peopleCnt + wolne.iloscPozycji < zapytania[qi].f)
        {
            peopleCnt += wolne.iloscPozycji;
            pq.pop();
            wolne.iloscPozycji *= 2;
            wolne.space /= 2;
            pq.push(wolne);
            wolne = pq.top();
        }
        
        ll mianownik = wolne.iloscPozycji * 2;
        ll licznik = wolne.startSpace;
        while(qi < z && peopleCnt + wolne.iloscPozycji >= zapytania[qi].f)
        {
            ll diff = zapytania[qi].f - peopleCnt;
            ll offset = 1 + 2 * (diff - 1);
            ans[zapytania[qi].s] = {
                licznik * offset + wolne.startValue * mianownik,
                mianownik
            };   
            qi++;
        }
    }

    for(pll& curr : ans)
    {
        while (curr.f % 2 == 0 && curr.s % 2 == 0)
        {
            curr.f /= 2;
            curr.s /= 2;
        }
        cout << curr.f << "/" << curr.s << '\n';
    }
    
    return 0;
}