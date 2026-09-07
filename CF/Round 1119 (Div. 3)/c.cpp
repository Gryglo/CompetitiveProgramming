#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> pref(n + 1);
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + (a[i] == 1 || a[i] == -1);

    /*
    0 1 2 3 4 5 6

    0 1 2 3 4 5 6 7
    0 0 1 2 3 4 5 6
    */

    bool one = false;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1) one = true;
        if(a[i] == -1)
        {
            if(!one)
            {
                a[i] = 1;
                one = true;
            }
            else if(pref[n] - pref[i + 1] > 0) a[i] = 0;
            else a[i] = 1;
        }
    }
    for(int x : a) cout << x << ' ';
    cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}