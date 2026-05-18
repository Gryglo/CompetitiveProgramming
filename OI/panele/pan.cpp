#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ld = long double;
using pii = pair<int, int>;

pii validSeg(int x, int a, int b)
{
    int l = ceil((ld)a/x);
    int r = b/x;
    return {l, r};
}

bool isBetween(int x, int a, int b)
{
    if(a % x == 0) return true;
    if(b % x == 0) return true;
    int da = a / x;
    int db = b / x;
    if(da != db) return true;
    return false;
}

void solve()
{
    int smin, smax, wmin, wmax;
    cin >> smin >> smax >> wmin >> wmax;
    if(smax > wmax){ swap(smin, wmin); swap(smax, wmax); }
    int max_val = max(smax, wmax);
    int res = 1;
    for(int x = 1; x * x <= max_val; x++)
    {
        if(!isBetween(x, smin, smax)) continue;
        if(!isBetween(x, wmin, wmax)) continue;
        res = max(res, x);
    }
    int x = 1, y = 1;
    while(x * x <= max_val && y * y <= max_val)
    {
        if(!isBetween(x, smin, smax)){ x++; continue; }
        if(!isBetween(y, wmin, wmax)){ y++; continue; }
        pii s_seg = validSeg(x, smin, smax);
        pii w_seg = validSeg(y, wmin, wmax);
        if(w_seg.f <= s_seg.s && w_seg.s >= s_seg.f)
        {
            res = max(res, min(s_seg.s, w_seg.s));
            break;
        }
        else if(w_seg.s > s_seg.s)  y++;
        else x++;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
        solve();
    return 0;
}