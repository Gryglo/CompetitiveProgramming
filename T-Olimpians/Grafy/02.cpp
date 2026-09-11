#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int INF = 4e9;
void rotate_45(pii& x) { x = { x.f - x.s, x.f + x.s }; }
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int max_x = -INF, min_x = INF;
    int max_y = -INF, min_y = INF;
    for(int i = 0; i < n; i++)
    {
        pii curr; cin >> curr.f >> curr.s;
        rotate_45(curr);
        max_x = max(max_x, curr.f);
        min_x = min(min_x, curr.f);
        max_y = max(max_y, curr.s);
        min_y = min(min_y, curr.s);
    }
    cout << max(max_x - min_x, max_y - min_y);
    return 0;
}