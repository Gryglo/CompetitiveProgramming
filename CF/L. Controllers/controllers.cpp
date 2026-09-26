#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n;
string st;
int x = 0, y = 0;

bool check_ans(int a, int b)
{
    int d = a - b;
    int c = b * (y - x);
    if(d == 0 && c == 0) return true;
    if(d == 0 && c != 0) return false;
    if(c % d != 0) return false;
    int m = abs(c / d);
    if(d >= 0 && c >= 0) if(x >= m) return true;
    if(d >= 0 && c <= 0) if(y >= m) return true;
    if(d <= 0 && c >= 0) if(y >= m) return true;
    if(d <= 0 && c <= 0) if(x >= m) return true;
    return false;
}

void solve()
{
    int a, b; cin >> a >> b;
    bool ans = false;
    ans = check_ans(a, b);
    cout << (ans ? "YES\n" : "NO\n");
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> st;
    for(int i = 0; i < n; i++)
    {
        if(st[i] == '+') x++;
        else y++;
    }
    int q; cin >> q;
    while(q--) solve();
    return 0;
}