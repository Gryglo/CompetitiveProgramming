#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll n, h;
vector<pii> getFreeSegments(ll a, ll b)
{
    vector<pii> res;
    if(a != 0) res.push_back({0, a});
    if(b != h) res.push_back({b, h});
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    vector<pii> freeSeg;
    ll ans = 2;
    for(int i = 0; i < n; i++)
    {
        ll a, b; cin >> a >> b;
        vector<pii> currSeg = getFreeSegments(a, b);
        if(i == 0)
        {
            for(pii& seg : currSeg)
                freeSeg.push_back(seg);
        }
        else
        {
            vector<pii> temp;
            vector<pii> temp2;
            for(pii& seg : currSeg)
            {
                if(seg.f == 0) //poczatek
                {
                    for(int x = 0; x < freeSeg.size(); x++)
                    {
                        if(seg.s <= freeSeg[x].f)
                            break;
                        //pokrywa sie cos
                        if(seg.s < freeSeg[x].s)
                            temp.push_back({freeSeg[x].f, seg.s});
                        else
                            temp.push_back(freeSeg[x]);
                    }
                }
                else //koniec
                {
                    for(int x = freeSeg.size() - 1; x >= 0; x--)
                    {
                        if(seg.f >= freeSeg[x].s)
                            break;
                        //pokrywa sie cos
                        if(seg.f > freeSeg[x].f)
                            temp2.push_back({seg.f, freeSeg[x].s});
                        else
                            temp2.push_back(freeSeg[x]);
                    }
                }
            }
            for(int x = temp2.size() - 1; x >= 0; x--)
                temp.push_back(temp2[x]);
            freeSeg = temp;
            if(freeSeg.size() == 0) //dodajemy 2 do wyniku
            {
                ans += 2;
                //nowy freeSeg
                for(pii& seg : currSeg)
                    freeSeg.push_back(seg);
            }
        }
    }
    cout << ans;
    return 0;
}