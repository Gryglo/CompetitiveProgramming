#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int n, m;
vector<ld> a;
vector<ld> x;

void init()
{
    cin >> n >> m;
    a.resize(n);
    x.resize(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> x[i];
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(6);
}

int main()
{
    init();
    for(ld curr : x)
    {
        ld res = 0;
        for(int i = 0; i < n; i++) 
        { res *= curr; res += a[i]; }
        cout << res << '\n';
    }
    return 0;
}