#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
int n, m;
vector<vector<int>> adj;
vector<int> color;
int lastColor = 0;
void DFS(int v, int c)
{
    color[v] = c;
    for(int u : adj[v])
    {
        if(color[u] != 0) continue;
        DFS(u, c);
    }
}
int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //vector<int> ans;
    int ans =n;
    color.resize(n);
    for(int i = 0; i < n; i++)
    {
        if(color[i] == 0)
        {
            lastColor++;
            //ans.push_back(i);
            DFS(i, lastColor);
        }
    }
    //color[i]
    int nonZero = 1;
    vector<int> cntColor(lastColor + 1);
    int l = 0, r = 0;
    cntColor[color[0]]++;
    while(l <= r)
    {
        if(nonZero == lastColor)
        {
            ans = min(ans, r - l + 1);
            cntColor[color[l]]--;
            if(cntColor[color[l]] == 0)
                nonZero--;
            l++;
        }
        else
        {
            if(r == n - 1)
                break;
            r++;
            cntColor[color[r]]++;
            if(cntColor[color[r]] == 1)
                nonZero++;
        }
    }
    cout << ans;
    return 0;
}