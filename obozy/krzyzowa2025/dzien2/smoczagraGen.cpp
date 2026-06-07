#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const ll MAXN = 1000;
const ll MAXH = 200;
int main()
{
    srand(getpid());
    fastio;
    ll n, k;
    n = 5 + (rand() % MAXN);
    k = n - 1 - (rand() % (n - 1));
    cout << n << " " << k << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << (rand() % MAXH) - 100 << ' ';
    }
}