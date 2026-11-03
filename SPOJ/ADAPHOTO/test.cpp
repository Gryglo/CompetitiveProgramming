#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n = 1e6;
    int x = n;
    int ans = 0;
    while(x > 0)
    {
        ans += n - x + 1;
        x/=2;
    }
    cout << ans;
    return 0;
}