#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second
int p, t;
bool ask(vector<int>& subset)
{
    cout << "? " << subset.size() << " ";
    for(int v : subset)
        cout << v + 1 << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    return (ans == 1);
}
vector<vector<int>> adj;

void solve()
{
    int n;
    cin >> n;
    adj.assign(n, vector<int>(0));
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> order;
    queue<pii> q;
    q.push({0, -1});
    order.push_back(0);
    while(!q.empty())
    {
        pii v = q.front();
        q.pop();
        for(int u : adj[v.f])
        {
            if(u == v.s) continue;
            q.push({u, v.f});
            order.push_back(u);
        }
    }
    
    int l = 0, r = n - 1;
    while(l < r)
    {
        int m = (l + r) / 2;
        vector<int> curr;
        for(int i = 0; i <= m; i++)
            curr.push_back(order[i]);
        if(ask(curr))
            r = m;
        else
            l = m + 1;
    }
    
    cout << "! " << order[l] + 1 << endl;
}

int main()
{
    cin >> p >> t;

    while(t--)
        solve();
    return 0;
}