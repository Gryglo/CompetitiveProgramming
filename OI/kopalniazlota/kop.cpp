#include <bits/stdc++.h>
using namespace std;
using piii = pair<pair<int, int>, int>;
#define f first
#define s second
const int OFFSET = 30000;
const int MAX_XY = 60010;
int sz, w, n;

vector<int> t;
vector<int> lazy;

void push(int v, int l, int r)
{
    t[v] += lazy[v];
    if(l != r)
    {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}

void update(int v, int l, int r, int tl, int tr, int x)
{
    push(v, l, r);
    if(l > tr || r < tl) return;
    if(tl <= l && r <= tr)
    {
        lazy[v] += x;
        push(v, l, r);
    }
    else
    {
        int m = (l + r) / 2;
        update(2 * v, l, m, tl, tr, x);
        update(2 * v + 1, m + 1, r, tl, tr, x);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

bool sortPoints(piii& a, piii& b)
{
    if(a.f.s == b.f.s) //te same y
    {
        if(a.s == b.s) // jezeli ta sama wysokosc i operacje tego samego typu
            return a.f.f > b.f.f; //najpierw te wieksze od prawej
        return a.s < b.s; //najpierw usuwanie
    }
    return a.f.s < b.f.s; //czyli ten nizej bedzie pierwszy
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> sz >> w >> n;
    vector<piii> points;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        x += OFFSET; y += OFFSET;
        points.push_back({{x, y}, 1});
        points.push_back({{x, y + w + 1}, -1});
    }
    sort(points.begin(), points.end(), sortPoints);

    t.resize(4 * MAX_XY);
    lazy.resize(4 * MAX_XY);
    int ans = 0;
    for(piii& point : points)
    {
        if(point.s == 1) //dodajemy
        {
            //update na przedziale [x, x + sz]
            update(1, 0, MAX_XY, point.f.f, min(point.f.f + sz, MAX_XY), 1);
            //get max
            push(1, 0, MAX_XY);
            ans = max(ans, t[1]);
        }
        else //odejmujemy
            update(1, 0, MAX_XY, point.f.f, min(point.f.f + sz, MAX_XY), -1);
    }
    cout << ans;
    return 0;
}