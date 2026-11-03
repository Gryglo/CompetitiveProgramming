#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int P1 = 97;
const int P2 = 101;
string a;
vector<int> p1, p2;
vector<int> h1, h2;
void compute_powers()
{
    p1.resize(a.size() + 1);
    p1[0] = 1;
    for(int i = 1; i <= a.size(); i++) 
        p1[i] = (p1[i - 1] * P1) % MOD1;
    p2.resize(a.size() + 1);
    p2[0] = 1;
    for(int i = 1; i <= a.size(); i++) 
        p2[i] = (p2[i - 1] * P2) % MOD2;
}
void compute_hash()
{
    h1.resize(a.size() + 1);
    for(int i = 1; i <= a.size(); i++)
        h1[i] = (h1[i - 1] * P1 + (a[i - 1] - 32)) % MOD1;
    h2.resize(a.size() + 1);
    for(int i = 1; i <= a.size(); i++)
        h2[i] = (h2[i - 1] * P2 + (a[i - 1] - 32)) % MOD2;
}
pii get_hash(int i, int len)
{
    return {(h1[i + len] + MOD1 - (h1[i] * p1[len]) % MOD1) % MOD1, 
            (h2[i + len] + MOD2 - (h2[i] * p2[len]) % MOD2) % MOD2};
}
pii get_hash_off(int i, int len)
{
    if(i + len - 1 < a.size()) return get_hash(i, len);
    pii l_h = get_hash(i, a.size() - i);
    pii r_h = get_hash(0, len - (a.size() - i));
    l_h.f = (l_h.f * p1[len - (a.size() - i)]) % MOD1;
    l_h.s = (l_h.s * p2[len - (a.size() - i)]) % MOD2;
    return {(r_h.f + l_h.f) % MOD1, (r_h.s + l_h.s) % MOD2};
}
bool sort_shifts(int x, int y)
{
    int len = 0;
    int l = 1, r = a.size();
    while(l <= r)
    {
        int m = (l + r) / 2;
        pii x_h = get_hash_off(x, m);
        pii y_h = get_hash_off(y, m);
        if(x_h.f == y_h.f && x_h.s == y_h.s)
        {
            l = m + 1;
            len = m;
        }
        else r = m - 1;
    }
    if(len == a.size()) return false;
    int x_i = (x + len) % a.size();
    int y_i = (y + len) % a.size();
    return a[x_i] < a[y_i];
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    compute_powers();
    compute_hash();
}
int32_t main()
{
    init();
    vector<int> cyclic_shifts;
    for(int i = 0; i < a.size(); i++) cyclic_shifts.push_back(i);
    sort(cyclic_shifts.begin(), cyclic_shifts.end(), sort_shifts);
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[cyclic_shifts[0]];
        cyclic_shifts[0] = (cyclic_shifts[0] + 1) % a.size();
    }
    return 0;
}
// // 8
// // 5
// // 0 1 2 3 4 5 6 7
// // y y y y y x x x
// int l_h = get_hash(i, a.size() - i);
// int r_h = get_hash(0, i);
// l_h = (l_h * p[i]) % MOD;
// int all_h = (r_h + l_h) % MOD;