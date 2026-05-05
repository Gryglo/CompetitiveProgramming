#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;
const ll MOD = 1001;
ll n;
ll d, a, b;
ll minSum;
/* 
1 6
12
1 + 6 = 7

12
1 6
12 - 7 = 5
ceil(5/2) 5/2

11
1 6
11 - 7  = 4
2 2
3 8
*/
ll solve(ll x)
{
    if(x == 1)
        return 0;
    if(x == 2)
        return (a + b) % MOD;
    if(x <= minSum)
        return ((a + (x - 1) * b) % MOD) + solve(x - 1);
    //1 (1 + d)
    ll diff = x - minSum;
    ll first = 1 + (diff / 2);
    ll second = 1 + d + (diff / 2);
    if(diff % 2 != 0)
        first++;
    return ((first * a + second * b) % MOD) + solve(first) + solve(second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> a >> b;
    if(a > b) swap(a, b);
    minSum = 2 + d;
    cout << solve(n);
    return 0;
}