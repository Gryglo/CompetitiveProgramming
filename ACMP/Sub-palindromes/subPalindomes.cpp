#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int P = 131;
int n;
string ss;
vector<int> p;
vector<int> h;
vector<int> hrev;
void compute_powers()
{
    p.resize(n + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++) p[i] = (p[i - 1] * P) % MOD;
}
void compute_hash()
{
    h.resize(n + 1);
    for(int i = 1; i <= n; i++) h[i] = (h[i - 1] * P + (ss[i - 1] - 32)) % MOD;

    hrev.resize(n + 1);
    for(int i = 1; i <= n; i++) hrev[i] = (hrev[i - 1] * P + (ss[n - i] - 32)) % MOD;
}
int get_hash(int i, int len, vector<int>& h1)
{
    return (h1[i + len] + MOD - (h1[i] * p[len]) % MOD) % MOD;
}

int max_len(int il, int ir)
{
    if(ss[il] != ss[ir]) return 0;
    int i_rev = n - 1 - il;
    int len = 1;
    int l = 1, r = min(il + 1, n - ir);
    while(l <= r)
    {
        int m = (l + r) / 2;
        int right_h = get_hash(ir, m, h);
        int left_h = get_hash(i_rev, m, hrev);
        if(right_h == left_h)
        {
            len = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return len;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> ss;
    n = ss.size();
    compute_powers();
    compute_hash();
}
int32_t main()
{
    init();
    int ans = 0;
    //nieparzyste
    for(int i = 0; i < n; i++)
    {
        ans += max_len(i, i);
    }
    for(int i = 0; i < n - 1; i++)
    {
        ans += max_len(i, i + 1);
    }
    cout << ans << '\n';
    return 0;
}