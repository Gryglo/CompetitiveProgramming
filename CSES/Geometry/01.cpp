#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int INF = 4e9;
void rotate_45(pii& x) { x = { x.f - x.s, x.f + x.s }; }
int32_t main()
{

    multiset<int> a;
    auto it = a.find(45);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pii> p; p.resize(n);
    pii max_x = {-INF, -INF}, min_x = {INF, INF};
    pii max_y = {-INF, -INF}, min_y = {INF, INF};
    for(int i = 0; i < n; i++)
    {
        cin >> p[i].f >> p[i].s;
        rotate_45(p[i]);
        max_x = max(max_x, { p[i].f, -i });
        min_x = min(min_x, { p[i].f, i });
        max_y = max(max_y, { p[i].s, -i });
        min_y = min(min_y, { p[i].s, i });
    }
    for(int i = 0; i < n; i++)
    {
        int d1 = max_x.f - p[i].f, 
        d2 = p[i].f - min_x.f, 
        d3 = max_y.f - p[i].s, 
        d4 = p[i].s - min_y.f;
        int d = max(d1, max(d2, max(d3, d4)));
        if(d == d1) cout << -max_x.s + 1 << '\n';
        else if(d == d2) cout << min_x.s + 1 << '\n';
        else if(d == d3) cout << -max_y.s + 1 << '\n';
        else if(d == d4) cout << min_y.s + 1<< '\n';
    }
    return 0;
}