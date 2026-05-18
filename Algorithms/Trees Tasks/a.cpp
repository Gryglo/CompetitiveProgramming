#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

const int INF = INT_MAX;

int n, q;
vector<int> a;
vector<pii> t;

void build(int v, int l, int r)
{
    if(l == r)
        t[v] = {a[l], l};
    else
    {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        if(t[2 * v] >= t[2 * v + 1])
            t[v] = t[2 * v];
        else
            t[v] = t[2 * v + 1];
    }
}

int update(int v, int l, int r, int x)
{
    if(l == r)
    {
        t[v].f -= x;
        return t[v].s;
    }
    else
    {
        int m = (l + r) / 2;
        int ans = 0;
        if(t[2 * v].f >= x)
            ans = update(2 * v, l, m, x);
        else if(t[2 * v + 1].f >= x)
            ans = update(2 * v + 1, m + 1, r, x);
        else
            ans = INF;
        if(t[2 * v] >= t[2 * v + 1])
            t[v] = t[2 * v];
        else
            t[v] = t[2 * v + 1];
        return ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    t.resize(4 * n);
    build(1, 0, n - 1);
    while(q--)
    {
        int h;
        cin >> h;
        if(t[1].f < h)
        {
            cout << 0 << ' ';
            continue;
        }
        int ans = update(1, 0, n - 1, h);
        if(ans == INF)
            cout << 0 << " ";
        else
            cout << ans + 1 << " ";
    }
    return 0;
}