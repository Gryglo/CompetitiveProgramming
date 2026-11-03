#include <bits/stdc++.h>
#define int long long
using namespace std;
const int P = 131;
const int MOD = 1e9 + 7;
int n;
string str;
vector<int> h;
vector<int> power;

void compute_power()
{
    power.resize(n + 1, 1);
    for(int i = 1; i <= n; i++) power[i] = (power[i - 1] * P) % MOD;
}

void compute_hash()
{   
    h.resize(n + 1);
    for(int i = 1; i <= n; i++) h[i] = (h[i - 1] + (str[i - 1]) * power[i - 1]) % MOD;
}

int shift_hash(int x, int len)
{
    int ni = x + len;
    if(ni <= n)
    {
        int res = (((h[ni] + MOD - h[x]) % MOD) * power[n - x]) % MOD;
        return res;
    }
    else
    {
        ni = ni % n;
        int res = (((h[n] + MOD - h[x]) % MOD) * power[n - x]) % MOD;
        int second = (((h[ni] * power[n]) % MOD) * power[n - x]) % MOD;
        res = (res + second) % MOD;
        return res;
    }
}

bool min_shift(int a, int b)
{
    int i = 0;
    int l = 1, r = n - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(shift_hash(a, m) == shift_hash(b, m))
        {
            i = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    char first = str[(a + i) % n];
    char second = str[(b + i) % n];
    if(first <= second) return true;
    return false;
}

void merge_sort(int l, int r, vector<int>& arr)
{
    if(l == r) { return; }
    int m = (l + r) / 2;
    merge_sort(l, m, arr);
    merge_sort(m + 1, r, arr);
    vector<int> res;
    int li = l, ri = m + 1;
    while(li <= m && ri <= r)
    {
        if(min_shift(arr[li], arr[ri]))
        {
            res.push_back(arr[li]);
            li++;
        }
        else
        {
            res.push_back(arr[ri]);
            ri++;
        }
    }
    while(li <= m)
    {
        res.push_back(arr[li]);
        li++;
    }
    while(ri <= r)
    {
        res.push_back(arr[ri]);
        ri++;
    }
    for(int i = l; i <= r; i++)
    {
        arr[i] = res[i - l];
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    n = str.size();
    compute_power();
    compute_hash();
}
int32_t main()
{
    init();
    vector<int> shifts(n);
    for(int i = 0; i < n; i++)
    {
        shifts[i] = i;
    }
    merge_sort(0, n - 1, shifts);
    for(int i = 0; i < n; i++)
    {
        if(shifts[i] == 0)
        {
            cout << i + 1 << '\n';
            break;
        } 
    }
    for(int shift : shifts)
    {
        cout << str[(shift + n - 1) % n];
    }
    return 0;
}