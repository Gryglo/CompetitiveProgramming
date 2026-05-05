#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;

void solve()
{
    string a; cin >> a;
    int lastSi = -INF;
    int lastUi = -1;
    int ans = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 'u')
        {
            if(lastUi != -1)
            {
                ans++;
                if(lastUi - lastSi == i - lastUi)
                {
                    lastSi = i;
                    lastUi = -1;
                    continue;
                }
                else
                    lastSi = lastUi;
            }
            lastUi = i;
        }
        if(a[i] == 's') 
        {
            if(lastUi != -1)
            {
                if(lastUi - lastSi != i - lastUi)
                    ans++;
                lastUi = -1;
            }
            lastSi = i;
        }  
    }
    if(lastUi != -1)
        ans++;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}