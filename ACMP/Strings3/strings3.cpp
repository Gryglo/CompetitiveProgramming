#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P = 67;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
int n, m;
string str1, str2;
vector<int> h1, h2;
vector<int> h12, h22;
vector<int> powers, powers2;
set<int> hash_set1;
set<int> hash_set2;

int char_code(char x)
{
    if('0' <= x && x <= '9') return 1 + x - '0';
    if('a' <= x && x <= 'z') return 11 + x - 'a';
    if('A' <= x && x <= 'Z') return 37 + x - 'A';
    return 63;
}

void compute_powers()
{
    powers.resize(2 * n + 1);
    powers[0] = 1;
    for(int i = 1; i <= 2 * n; i++) 
        powers[i] = (powers[i - 1] * P) % MOD1;

    powers2.resize(2 * n + 1);
    powers2[0] = 1;
    for(int i = 1; i <= 2 * n; i++) 
        powers2[i] = (powers2[i - 1] * P) % MOD2;
}

void compute_hash(string& x, vector<int>& h)
{
    h.resize(x.size() + 1);
    for(int i = 1; i <= x.size(); i++) 
        h[i] = (h[i - 1] + char_code(x[i - 1]) * powers[i - 1]) % MOD1;
}
void compute_hash2(string& x, vector<int>& h)
{
    h.resize(x.size() + 1);
    for(int i = 1; i <= x.size(); i++) 
        h[i] = (h[i - 1] + char_code(x[i - 1]) * powers2[i - 1]) % MOD2;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str1 >> str2;
    n = str1.size(), m = str2.size();
    str2 += str2;
    compute_powers();
    compute_hash(str1, h1);
    compute_hash(str2, h2);
    compute_hash2(str1, h12);
    compute_hash2(str2, h22);
    for(int i = 1; i <= m; i++)
    {
        int curr1 = (h2[i + (m - 1)] + MOD1 - h2[i - 1]) % MOD1;
        curr1 = (curr1 * powers[n - (i - 1)]) % MOD1;
        hash_set1.insert(curr1);

        int curr2 = (h22[i + (m - 1)] + MOD2 - h22[i - 1]) % MOD2;
        curr2 = (curr2 * powers2[n - (i - 1)]) % MOD2;
        hash_set2.insert(curr2);
    }
}

int32_t main()
{
    init();
    int ans = 0;
    for(int i = 1; i + (m - 1) <= n; i++)
    {
        int curr1 = (h1[i + (m - 1)] + MOD1 - h1[i - 1]) % MOD1;
        curr1 = (curr1 * powers[n - (i - 1)]) % MOD1;
    
        int curr2 = (h12[i + (m - 1)] + MOD2 - h12[i - 1]) % MOD2;
        curr2 = (curr2 * powers2[n - (i - 1)]) % MOD2;

        if((hash_set1.find(curr1) != hash_set1.end()) && 
(hash_set2.find(curr2) != hash_set2.end())) ans++;
    }
    cout << ans << '\n';
    return 0;
}