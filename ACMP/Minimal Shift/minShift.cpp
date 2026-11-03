#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 9;
const int P = 503;
string a;
vector<int> p;
vector<int> h;
void compute_powers()
{
    p.resize(a.size() + 1);
    p[0] = 1;
    for(int i = 1; i <= a.size(); i++) 
        p[i] = (p[i - 1] * P) % MOD;
}
void compute_hash()
{
    h.resize(a.size() + 1);
    for(int i = 1; i <= a.size(); i++)
        h[i] = (h[i - 1] * P + (a[i - 1] - 32)) % MOD;
}
int get_hash(int i, int len)
{
    return (h[i + len] + MOD - (h[i] * p[len]) % MOD) % MOD;
}
int get_hash_off(int i, int len)
{
    if(i + len - 1 < a.size()) return get_hash(i, len);
    int l_h = get_hash(i, a.size() - i);
    int r_h = get_hash(0, len - (a.size() - i));
    l_h = (l_h * p[len - (a.size() - i)]) % MOD;
    return (r_h + l_h) % MOD;
}
bool sort_shifts(int x, int y)
{
    int len = 0;
    int l = 1, r = a.size();
    while(l <= r)
    {
        int m = (l + r) / 2;
        int x_h = get_hash_off(x, m);
        int y_h = get_hash_off(y, m);
        if(x_h == y_h)
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
    int min_shift = 0;
    for(int i = 1; i < a.size(); i++)
    {
        if(!sort_shifts(min_shift, i))
        {
            min_shift = i;
        }
    }
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[min_shift++];
        min_shift %= a.size();
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