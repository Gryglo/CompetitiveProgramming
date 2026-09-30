#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
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
int mod_div(int a, int b)
{
    a %= MOD; b %= MOD;
    int inv_b = fast_pow(b, MOD - 2); //małe twierdzenie fermata
    return mod_multi(a, inv_b);
}
int32_t main()
{
    cout << fast_pow(2, 6) << '\n';
    cout << fast_pow(3, 2) << '\n';
    cout << fast_pow(3, 3) << '\n';
    cout << fast_pow(5, 2) << '\n';
    cout << fast_pow(5, 7) << '\n';
    return 0;
}