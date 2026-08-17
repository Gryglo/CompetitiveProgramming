#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m; cin >> n >> m;
    vector<bool> avail(30, false);
    for(int i = 0; i < n; i++) { string x; cin >> x; avail[x[0] - 'a'] = true; }
    vector<string> input(m);
    for(int i = 0; i < m; i++) cin >> input[i];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < input[i].size(); j++)
            if(!avail[input[i][j] - 'A'])
            { cout << "NO\n"; return; }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}