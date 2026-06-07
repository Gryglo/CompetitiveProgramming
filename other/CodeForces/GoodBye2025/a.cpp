#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string input;
    cin >> input;
    int cntY = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == 'Y')
            cntY++;
        if(cntY >= 2)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}