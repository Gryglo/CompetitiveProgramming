#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> hotels, queries;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    hotels.resize(n); queries.resize(q);
    for(int i = 0; i < n; i++) cin >> hotels[i];
    for(int i = 0; i < q; i++) cin >> queries[i];
}

int main()
{   
    init();
    for(int& x : queries)
        for(int i = 0; i <= n; i++)
        {
            if(i == n) { cout << 0 << ' '; break; }
            if(hotels[i] >= x) { hotels[i] -= x; cout << i + 1 << ' '; break; }
        }
    return 0;
}