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
    if (a > 0) res.push_back({a, 0});
    if (b < h) res.push_back({h, b});
    return res;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    if(n == 0)
    {
        cout << 0; return 0;
    }

    set<pii> freeSeg;
    ll ans = 2;

    for (int i = 0; i < n; i++) 
    {
        ll a, b;
        cin >> a >> b;
        vector<pii> curr = getFreeSegments(a, b);

        if (i == 0) 
        {
            for (pii& seg : curr) freeSeg.insert(seg);
        } 
        else 
        {
            auto it = freeSeg.lower_bound({a, -2000000000000000000LL});
            
            vector<pii> toRemove;
            vector<pii> toAdd;
            while (it != freeSeg.end()) 
            {
                ll sE = it->f;
                ll sS = it->s;
                if (sS >= b) break; 

                toRemove.push_back(*it);
                
                if (sS < a) toAdd.push_back({a, sS});
                if (sE > b) toAdd.push_back({sE, b});

                it++;
            }

            for (auto& val : toRemove) freeSeg.erase(val);
            for (auto& val : toAdd) freeSeg.insert(val);

            if (freeSeg.empty()) 
            {
                ans += 2;
                for (pii& seg : curr) 
                    freeSeg.insert(seg);
            }
        }
    }
    cout << ans;
    return 0;
}