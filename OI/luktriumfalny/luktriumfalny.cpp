#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

int check(int v, int parent, int value)
{
    int sum = 0;

    for(int u : adj[v])
    {
        if(u == parent)
            continue;
        sum += check(u, v, value) + 1;
    }
    return max(0, sum - value);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; 
    adj.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int l = 0, r = n;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(0, -1, mid) == 0)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;

    return 0;
}