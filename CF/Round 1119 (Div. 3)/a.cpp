#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve()
{
    int n, k; cin >> n >> k;
    string x; cin >> x;
    bool canBuild = false;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && i % k == 0)
        {
            if(!canBuild) ans++;
            canBuild = false;
        }
        if(x[i] == '0') canBuild = true;
    }
    if(!canBuild) ans++;
    cout << ans << '\n';
}


int main()
{
    int q; cin >> q;
    while(q--) solve();
    return 0;
}