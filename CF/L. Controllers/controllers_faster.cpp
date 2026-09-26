#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n;
string s;
int x = 0, y = 0;
void solve()
{
    int a, b; cin >> a >> b;
    for(int i = 0; i <= x; i++)
    {
        for(int k = 0; k <= y; k++)
        {
            //int curr = a * i - a * k + b * (x - i) - b * (y - k);
            //int curr = a * (i - k) + b * x - b * y - b * (i - k);
            int curr = (a - b) * (i - k);
            if(curr == b * (y - x))
            {
                cout << i << ' ' << k << '\n';
                cout << x << ' ' << y << '\n';
                cout << "YES\n"; return; 
            }
            // if(curr == 0) 
            // { 
            //     cout << i << ' ' << k << '\n';
            //     cout << "YES\n"; return; 
            // }
        }
    }
    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '+') x++;
        else y++;
    }
    int q; cin >> q;
    while(q--) solve();
    return 0;
}