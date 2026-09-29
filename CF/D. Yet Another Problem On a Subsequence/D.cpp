#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
const int MAXN  = 1005;
int n;
vector<int> a;
vector<int> silnia(MAXN + 1);
int fast_pow(int a, int b) //a^b
{
    int ans = 1;
    while(b > 0)
    {
        if(b % 2 != 0) ans = (ans * a) % MOD;
        a = (a * a) % MOD; b/=2;
    }
    return ans;
}
int mod_multi(int a, int b) 
{ 
    return ((a * b) % MOD); 
}
int mod_add(int a, int b) 
{ 
    return ((a + b) % MOD); 
}
int mod_div(int a, int b)
{
    a %= MOD; b %= MOD;
    int inv_b = fast_pow(b, MOD - 2);
    return mod_multi(a, inv_b);
}

int dwumian(int n, int k)
{
    //n!/(k!* (n - k)!)
    int licznik = silnia[n];
    int mianownik = mod_multi(silnia[k], silnia[n - k]);
    return mod_div(licznik, mianownik);
}

void compute_silnia()
{
    silnia[0] = 1;
    silnia[1] = 1;
    for(int i = 2; i <= MAXN; i++) silnia[i] = mod_multi(silnia[i - 1], i);
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    compute_silnia();
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) a[i] = a[i] % MOD;
}
int32_t main()
{
    init();
    vector<int> dp(n + 1);
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        dp[i] = mod_add(dp[i], dp[i + 1]);
        if(a[i] <= 0) continue;
        for(int j = i + a[i]; j < n; j++)
        {
            // 2 x x x x
            // 4 5 6 7 8 9
            dp[i] = mod_add(dp[i], dwumian(j - i - 1, a[i] - 1) * dp[j + 1]);
        }
    }
    cout << dp[0] - 1;
    return 0;
}