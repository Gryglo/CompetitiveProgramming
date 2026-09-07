#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

void rotate_45(pii& x)
{
    x = { x.f - x.s, x.f + x.s };
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    set<int> x_cord, y_cord;
    for(int i = 0; i < n; i++)
    {
        pii x; cin >> x.f >> x.s;
        rotate_45(x);
        x_cord.insert(x.f); y_cord.insert(x.s);
        if(i == 0) 
        {
            cout << 0 << '\n';
            continue;
        }
        int x_diff = (*x_cord.rbegin()) - (*x_cord.begin());
        int y_diff = (*y_cord.rbegin()) - (*y_cord.begin());
        cout << max(x_diff, y_diff) << '\n';
    }
    return 0;
}