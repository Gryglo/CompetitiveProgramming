#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int P = 67;
int n, m;
string a, b;
vector<int> h1;
vector<int> p;
int h2;
int char_code(char x)
{
    if(x <= 90) return x - 'A' + 1;
    return x - 'a' + 27;
}
void compute_powers()
{
    p.resize(n + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++) p[i] = (p[i - 1] * P) % MOD;
}
void compute_hash()
{
    h1.resize(n + 1);
    for(int i = 1; i <= n; i++)
        h1[i] = (h1[i - 1] + char_code(a[i - 1]) * p[i - 1]) % MOD;
    for(int i = 0; i < m; i++)
        h2 = (h2 + char_code(b[i]) * p[i]) % MOD;
}
void init()
{
    cin >> a >> b;
    n = a.size(), m = b.size();
    compute_powers();
    compute_hash();
}

int32_t main()
{
    init();
    vector<int> ans;
    for(int i = b.size(); i <= n; i++)
    {
        int moved_h = (h2 * p[i - b.size()]) % MOD;
        int curr_h = (h1[i] + MOD - h1[i - b.size()]) % MOD;
        if(curr_h == moved_h) ans.push_back(i - b.size());
    }
    for(int x : ans) cout << x << ' ';
    return 0;
}