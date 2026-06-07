#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj;
vector<bool> visited;
vector<int> cyclesSize;
int addCycle(int v, int depth)
{
    visited[v] = true;
    if(!visited[adj[v]])
        return addCycle(adj[v], depth + 1);
    else
        return depth;
}   
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    adj.resize(n);
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x; x--;
        adj[i] = x;
    }
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            int cycleLen = addCycle(i, 1);
            cyclesSize.push_back(cycleLen);
        }
    }
    sort(cyclesSize.begin(), cyclesSize.end());
    int sum = 0;
    for(int i = cyclesSize.size() - 1; i >= max(0, ((int)cyclesSize.size()) - 1 - k); i--)
        sum += cyclesSize[i];
    cout << sum;
}