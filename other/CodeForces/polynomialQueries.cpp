#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q;
vector<int> ciag;
vector<int> t;
vector<int> lazy1;
vector<int> lazy2;

void build(int v, int l, int r)
{
    if(l == r)
        t[v] = ciag[l];
    else
    {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void push(int v, int l, int r)
{
    if(lazy1[v] == 0) return;
    int d = r - l + 1;
    //lazy1 = a1
    t[v] += ((2 * lazy1[v] + (d - 1) * lazy2[v]) / 2)*d;
    if(l != r)
    {
        lazy1[2 * v] += lazy1[v];
        lazy2[2 * v]++;
        int m = (l + r) / 2;
        // m + 1 to poczatek przedzialu drugiego czyli
        int offset = m + 1 - l;
        int a2 = lazy1[v] + offset * lazy2[v];
        lazy1[2 * v + 1] += a2;
        lazy2[2 * v + 1]++;
    }

    lazy1[v] = 0;
    lazy2[v] = 0;
}

int query(int v, int l, int r, int tl, int tr)
{
    push(v, l, r);
    if(l > tr || r < tl)
        return 0;
    if(tl <= l && r <= tr)
    {
        return t[v];
    }
    else
    {
        int m = (l + r) / 2;
        return query(2 * v, l, m, tl, tr) + 
        query(2 * v + 1, m + 1, r, tl, tr);
    }
}

void update(int v, int l, int r, int tl, int tr)
{
    push(v, l, r);
    if(l > tr || r < tl)
        return;
    if(tl <= l && r <= tr)
    {
        //zwieksz
        int a1 = l - tl + 1;
        lazy1[v] += a1;
        lazy2[v]++;
        push(v, l, r);
    }
    else
    {
        int m = (l + r) / 2;
        update(2 * v, l, m, tl, tr);
        update(2 * v + 1, m + 1, r, tl, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ciag.resize(n);
    for(int i = 0; i < n; i++)
        cin >> ciag[i];
    t.resize(4 * n);
    lazy1.resize(4 * n);
    lazy2.resize(4 * n);
    build(1, 0, n - 1);

    while(q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        a--; b--;
        if(type == 2)
        {
            //query 
            cout << query(1, 0, n - 1, a, b) << '\n';
        }
        else
        {
            //update
            update(1, 0, n - 1, a, b);
        }
    }
    return 0;
}