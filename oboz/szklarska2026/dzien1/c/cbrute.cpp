#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;

const int MAXN = 5005;
int n, m;
vector<vector<int>> adj;
vector<bool> visited;
int DFS(int v)
{
    visited[v] = true;

}
int main()
{
    /* 
    bitset<MAXN> test;
    cout << sizeof(test); */
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        if(a < b) swap(a, b);
        adj[a].push_back(b);
    }
    vector<pair<int, bitset<MAXN>>> dp(n); //dist visited
    for(int v = 0; v < n; v++)
    {   
        int maxU = -1;
        int maxUDist = -1;
        for(int u : adj[v])
        {
            if(dp[u].f > maxUDist)
        }
    }
    return 0;
}