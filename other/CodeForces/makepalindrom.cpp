#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> aSorted(a);
    sort(aSorted.begin(), aSorted.end());

    int l = 0, r = n - 1;
    while(l < r)
    {
        if(a[l] == a[r])
        {
            l++; r--;
        }
    }
    if(l >= r)
    {
        cout << "YES\n";
        return;
    }

    if(r - l + 1 < k)
    {
        cout << "NO\n";
        return;
    }
    
    
    
}
int main()
{
    int q;
    cin >> q;
    while(q--)
        solve();
    return 0;
}