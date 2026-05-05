#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define int long long
#define f first
#define s second

ll n, m;
vector<ll> t;
vector<ll> lazy1; //a1
vector<ll> lazy2; //b

void push(int v, int l, int r)
{
    if(lazy1[v] == 0 && lazy2[v] == 0) return;
    ll d = r - l + 1;
    t[v] += ((2 * lazy1[v] + (d - 1) * lazy2[v]) * d) / 2;
    if(l != r)
    {
        lazy1[2 * v] += lazy1[v];
        lazy2[2 * v] += lazy2[v];

        ll m = (l + r) / 2;
        lazy1[2 * v + 1] += lazy1[v] + ((m + 1) - l) * lazy2[v];
        lazy2[2 * v + 1] += lazy2[v];
    }
    lazy1[v] = 0; lazy2[v] = 0;
}

void update(int v, int l, int r, int tl, int tr, ll a, ll b) //a + bx
{
    push(v, l, r);
    if(l > tr || r < tl) return;
    if(tl <= l && r <= tr)
    {
        lazy1[v] += a + (l - tl) * b;
        lazy2[v] += b;
        push(v, l, r);
    }
    else
    {
        ll m = (l + r) / 2;
        update(2 * v, l, m, tl, tr, a, b);
        update(2 * v + 1, m + 1, r , tl, tr, a, b);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll query(int v, int l, int r, int tl, int tr)
{
    push(v, l, r);
    if(l > tr || r < tl) return 0;
    if(tl <= l && r <= tr)
        return t[v];
    else
    {
        ll m = (l + r) / 2;
        return query(2 * v, l, m, tl, tr) + query(2 * v + 1, m + 1, r , tl, tr);
    }
}

void dodajPrzekaznik(ll x, ll a, ll b)
{
    ll d = (a - 1) / b;
    update(1, 0, n - 1, x, min(n - 1, x + d), a, -b);
    if(x == 0) return;
    if(d == 0) return;
    ll maxL = max(0LL, x - d);
    ll a1 = a - ((x - maxL) * b);
    update(1, 0, n - 1, maxL, x - 1, a1, b);
}

void usunPrzekaznik(ll x, ll a, ll b)
{
    ll d = (a - 1) / b;
    update(1, 0, n - 1, x, min(n - 1, x + d), -a, b);
    if(x == 0) return;
    if(d == 0) return;
    ll maxL = max(0LL, x - d);
    ll a1 = a - ((x - maxL) * b);
    update(1, 0, n - 1, maxL, x - 1, -a1, -b);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    t.resize(4 * n);
    lazy1.resize(4 * n);
    lazy2.resize(4 * n);
    vector<pll> przekazniki(n);
    while(m--)
    {
        char op; cin >> op;
        if(op == 'P')
        {
            int x; ll s, a;
            cin >> x >> s >> a; x--;
            przekazniki[x] = {s, a};
            dodajPrzekaznik(x, s, a);
        }
        else if(op == 'U')
        {
            int x; cin >> x; x--;
            usunPrzekaznik(x, przekazniki[x].f, przekazniki[x].s);
        }
        else
        {
            int x1, x2;
            cin >> x1 >> x2; x1--; x2--;
            ll ans = query(1, 0, n - 1, x1, x2) / (x2 - x1 + 1);
            cout << ans << '\n';
        }
    }
    return 0;
}