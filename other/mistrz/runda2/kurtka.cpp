#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    cout << ((a <= k && k <= b) ? "Nie dotykaj mojej kurtki!" : "Spokojnie.");
    return 0;
}