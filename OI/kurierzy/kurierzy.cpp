#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 500000;

int n, m;
vector<int> firma;
vector<pii> t;

pii merge(pii a, pii b)
{
    //0 oznacza brak firmy dominujacej
    //liczba krotnosc
    if(a.f == b.f)
        return {a.f, a.s + b.s};
    if(a.s == b.s)
        return { 0, 0 };
    if(a.s > b.s)
        return {a.f, a.s - b.s};
    else
        return {b.f, b.s - a.s};
}

void build(int v, int l, int r)
{
    if(l == r)
        t[v] = { firma[l], 1 };
    else
    {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

pii query(int v, int l, int r, int tl, int tr)
{
    if(l > tr || r < tl)
        return {0, 0};
    if(tl <= l && r <= tr)
        return t[v];
    int m = (l + r) / 2;
    return merge(
        query(2 * v, l, m, tl, tr), 
        query(2 * v + 1, m + 1, r, tl, tr));
}
int32_t main()
{
    fastio;
    cin >> n >> m;
    firma.resize(n);
    for(int i = 0; i < n; i++)
        cin >> firma[i];
    t.resize(4 * n);  
    build(1, 0, n - 1);  
    vector<pii> przedzialy(m);
    //  typ ilosc na poczatku i 
    vector<pii> kandydaci(m);
    vector<int> ans(m);
    vector<vector<int>> poczatki(n);
    vector<vector<int>> konce(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        przedzialy[i] = {a, b};
        //kandydat krotnosc
        pii curr = query(1, 0, n - 1, a, b);
        kandydaci[i].f = curr.f;
        poczatki[a].push_back(i);
        konce[b].push_back(i);
    }   

    //poczatki przedzialow i konce przedzialow
    //indexowanie przedzialow
    // -1 0 1 -1 -1 0 -1 -1 1 -1 -1
    /* 
        vector<> poczatki
        vector<> konce
        na kazdym trzymamy indexy poczatkow
    */
    vector<int> cnt(MAXN + 5);
    for(int i = 0; i < n; i++)
    {   
        for(int idxprzedzialu : poczatki[i])
        {
            kandydaci[idxprzedzialu].s = cnt[kandydaci[idxprzedzialu].f];
        }
        cnt[firma[i]]++;
        for(int idxprzedzialu : konce[i])
        {
            int ilosc = cnt[kandydaci[idxprzedzialu].f] - kandydaci[idxprzedzialu].s;

            int dlugoscPrzedzialu = przedzialy[idxprzedzialu].s - przedzialy[idxprzedzialu].f + 1;
            if(ilosc > dlugoscPrzedzialu / 2)
                ans[idxprzedzialu] = kandydaci[idxprzedzialu].f;
            else
                ans[idxprzedzialu] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}