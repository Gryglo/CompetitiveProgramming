#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve()
{
    int n; cin >> n;

    int c1 = 0, c2 = 0, c3 = 0;

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(x % 2 != 0) c1++;
        else if(x % 4 == 0) c2++;
        else c3++;
    }
    cout << max(c1, max(c2, c3)) << '\n';
}


int main()
{
    int q; cin >> q;
    while(q--) solve();
    return 0;
}