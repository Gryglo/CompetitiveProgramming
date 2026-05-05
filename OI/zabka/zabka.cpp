#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = INT_MAX;

int n, k;
ll m;
vector<ll> ciag;
vector<int> adj;
vector<vector<int>> adj_rev;
vector<int> visited;
vector<int> depth;
//[jakis root cyclu] = vector caly cykl
vector<vector<int>> cycles;
vector<int> ans;

//zwraca głębkokosc do ktorej mamy dodawac do cyklu 
int mark_cycle(int v, int d)
{
    visited[v] = n + 1;
    depth[v] = d;
    if(visited[adj[v]] == n)
    {
        int cycleD = mark_cycle(adj[v], d + 1);
        if(depth[v] >= cycleD)
        {
            cycles[cycles.size() - 1].push_back(v);
            visited[v] = cycles.size() - 1;
        }
        else //poza cyklem juz
        {
            adj_rev[adj[v]].push_back(v);
            visited[v] = n + 2;
        }
        return cycleD;
    }
    else if(visited[adj[v]] == n + 1)
    {
        //cykl
        cycles.push_back(vector<int>(1, v));
        //cycles[cycles.size() - 1].push_back(v);
        visited[v] = cycles.size() - 1;
        return depth[adj[v]];
    }
    else
    {
        visited[v] = n + 2;
        adj_rev[adj[v]].push_back(v);
        return n + 2; //nie idz dalej to bylo juz sprawdzane
    }
}

int from_cycle(int& cycleIdx, int& idx, ll x)
{
    /* 
       0 1 2 3 4 5
       5 4 3 2 1 0
    */
   int cycleSize = cycles[cycleIdx].size();
   int revIdx = cycleSize - 1 - idx;
   ll nextIdx = (revIdx + x) % cycleSize;
   return cycles[cycleIdx][cycleSize - 1 - nextIdx];
}

vector<int> t;
void DFS(int v, int& cycleIdx, int& idx)
{
    t.push_back(v);
    if(t.size() > m)
        ans[v] = t[t.size() - 1 - m];
    else
    {
        //jestesmy w idx miejscu w cyklu cycleIdx
        //nasze m zmniejszamy o t.size()
        ans[v] = from_cycle(cycleIdx, idx, m - t.size());
    }
    for(int& u : adj_rev[v])
    {
        DFS(u, cycleIdx, idx);
    }
    t.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    ciag.resize(n);
    for(int i = 0; i < n; i++)
        cin >> ciag[i];
    
    adj.resize(n);
    adj_rev.resize(n);
    visited.resize(n, n);
    depth.resize(n, INF);
    ans.resize(n);
    int l = 0;
    for(int i = 0; i < n; i++)
    {
        while (l + k + 1 < n && ciag[l + k + 1] - ciag[i] < ciag[i] - ciag[l])
            l++;
        if(ciag[i] - ciag[l] >= ciag[l + k] - ciag[i])
            adj[i] = l;
        else
            adj[i] = l + k;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] != n) continue;
        mark_cycle(i, 0);
    }
    vector<int>().swap(adj);
    vector<int>().swap(depth);
    vector<int>().swap(visited);
    for(int cycleIdx = 0; cycleIdx < cycles.size(); cycleIdx++)
    {
        for(int i = cycles[cycleIdx].size() - 1; i >= 0; i--)
        {
            ans[cycles[cycleIdx][i]] = from_cycle(cycleIdx, i, m);
            for(int& u : adj_rev[cycles[cycleIdx][i]])
            {
                DFS(u, cycleIdx, i);
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    return 0;
}