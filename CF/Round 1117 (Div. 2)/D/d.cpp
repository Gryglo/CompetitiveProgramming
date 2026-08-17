#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll INF = 1e13;

int find_schodek_x(vector<ll>& schodki, vector<pii>& areas, ll x)
{
    ll l = 0, r = schodki.size() - 1;
    int s_i = -1;
    while(l <= r)
    {
        ll m = (l + r) / 2;
        if(areas[m].f <= x) { s_i = m; l = m + 1; }
        else r = m - 1;
    }
    return s_i;
}

int find_schodek_y(vector<ll>& schodki, vector<pii>& areas, ll y, int sz)
{
    ll l = 0, r = sz;
    int s_i = -1;
    while(l <= r)
    {
        ll m = (l + r) / 2;
        if(areas[m].s >= y) { s_i = m; l = m + 1; }
        else r = m - 1;
    }
    return s_i;
}

void solve()
{
    ll S; int q;
    cin >> S >> q;
    vector<pii> areas;
    for(ll i = 1; i * i <= S; i++)
    {
        if(S % i == 0)
        {
            ll a = i, b = S / i;
            areas.push_back({a, b});
            if(a == b) continue;
            areas.push_back({b, a});
        }
    }
    sort(areas.begin(), areas.end());
    vector<ll> schodki;
    ll sum_area = areas[0].f * areas[0].s;
    schodki.push_back(sum_area);
    for(int i = 1; i < areas.size(); i++)
    {
        sum_area += ((areas[i].f - areas[i - 1].f) * areas[i].s);
        schodki.push_back(sum_area);
    }
    while(q--)
    {
        ll x, y; cin >> x >> y;
        int s_i_x = find_schodek_x(schodki, areas, x);
        int s_i_y = find_schodek_y(schodki, areas, y, s_i_x);
        ll ans = y * (areas[s_i_y].f) + (schodki[s_i_x] - schodki[s_i_y]);
        if(x > areas[s_i_x].f && s_i_x < schodki.size() - 1) 
            ans += ((x - areas[s_i_x].f) * min(y, areas[s_i_x + 1].s));
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}