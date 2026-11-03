#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int P1 = 31;
const int MOD1 = 1e9 + 7;
const int P2 = 67;
const int MOD2 = 1e9 + 9;
string a, b;
vector<int> p1;
vector<int> h1_1, h2_1;

vector<int> p2;
vector<int> h1_2, h2_2;
int char_code(char x)
{
    if(x == '^') return 1;
    if(x == 'v') return 2;
    if(x == '-') return 3;
    return 4;
}
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
    h1_1.resize(a.size() + 1);
    for(int i = 1; i <= a.size(); i++)
        h1_1[i] = (h1_1[i - 1] * P1 + char_code(a[i - 1])) % MOD1;
    h2_1.resize(b.size() + 1);
    for(int i = 1; i <= b.size(); i++)
        h2_1[i] = (h2_1[i - 1] * P1 + char_code(b[i - 1])) % MOD1;

    h1_2.resize(a.size() + 1);
    for(int i = 1; i <= a.size(); i++)
        h1_2[i] = (h1_2[i - 1] * P2 + char_code(a[i - 1])) % MOD2;
    h2_2.resize(b.size() + 1);
    for(int i = 1; i <= b.size(); i++)
        h2_2[i] = (h2_2[i - 1] * P2 + char_code(b[i - 1])) % MOD2;
}
pii get_hash(int i, int len, vector<int>& h1, vector<int>& h2)
{
    return {(h1[i + len] + MOD1 - (h1[i] * p1[len]) % MOD1) % MOD1, 
            (h2[i + len] + MOD2 - (h2[i] * p2[len]) % MOD2) % MOD2};
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if(a.size() < b.size()) swap(a, b);
    compute_powers();
    compute_hash();
}
int32_t main()
{
    init();
    int ans = 0;
    int l = 1, r = min(40LL, (int)a.size());
    while(l <= r)
    {
        int m = (l + r) / 2;
        vector<pii> h1_arr(a.size() + 1 - m);
        for(int i = 0; i + m - 1 < a.size(); i++)
            h1_arr[i] = get_hash(i, m, h1_1, h1_2);
        sort(h1_arr.begin(), h1_arr.end());
        bool res = false;
        for(int i = 0; i + m - 1 < b.size(); i++)
        {
            if(binary_search(h1_arr.begin(), h1_arr.end(), get_hash(i, m, h2_1, h2_2)))
            {
                res = true;
                break;
            }
        }
        if(res)
        {
            l = m + 1;
            ans = m;
        }
        else r = m - 1;
    }
    cout << ans << '\n';
    return 0;
}