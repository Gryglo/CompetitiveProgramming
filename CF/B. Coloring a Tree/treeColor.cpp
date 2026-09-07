#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> colors;
int ans = 0;
void DFS(int v, int curr_c)
{
    if(curr_c != colors[v]){
        ans++;
        curr_c = colors[v];
    }
    for(int u : adj[v]) DFS(u, curr_c);
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    for(int i = 1; i < n; i++)
    {
        int p; cin >> p; p--;
        adj[p].push_back(i);
    }
    colors.resize(n);
    for(int i = 0; i < n; i++) cin >> colors[i];
}

int main()
{
    init();
    DFS(0, -1);
    cout << ans;
}