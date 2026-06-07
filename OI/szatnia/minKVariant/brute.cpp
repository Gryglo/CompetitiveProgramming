#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

int n, p;
vector<pii> item_end;
vector<int> item_c;

int main()
{
    cin >> n;
    item_c.resize(n);
    item_end.resize(n);
    for(int i = 0; i < n; i++)
    {
        int c, a, b; cin >> c >> a >> b;
        item_c[i] = c;
        item_end[i] = {a, b};
    }
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        int m, k, s; cin >> m >> k >> s;
        int a = m, b = m + s;
        bool res = false;
        for(int x = 0; x < n; x++)
            if(item_end[x].f <= a && b < item_end[x].s && item_c[x] == k)
            {
                res = true;
                break;
            }
        if(res) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}