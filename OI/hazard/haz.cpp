#include <bits/stdc++.h>
using namespace std;
int n;
int cntEdges = 0;
vector<vector<int>> adj;
vector<int> inDeg;
vector<int> outDeg;
vector<int> ans;
void find_path(int v)
{
    for(int u = 0; u < n; u++)
    {
        if(adj[v][u] == 0) continue; //nie ma krawedzi (v, u)
        adj[v][u]--;
        ans.push_back(u);
        find_path(u);
    }
}

int remove_cycle(int v, vector<int>& state, vector<int>& parent)
{
    state[v] = 1;
    for(int u = 0; u < n; u++)
    {
        if(adj[v][u] == 0) continue; 
        
        if(state[u] == 1) 
        {
            bool has_Gn = false;
            int curr = v;
            while(curr != u)
            {
                if(curr == n - 1) has_Gn = true;
                curr = parent[curr];
            }
            if(u == n - 1) has_Gn = true;

            if(has_Gn) continue; 
            adj[v][u]--;
            if(v == u) return -2;
            return u;
        }
        
        if(state[u] != 0) continue;
        
        parent[u] = v;
        int x = remove_cycle(u, state, parent);
        
        if(x == -2) return -2;
        if(x >= 0)
        {
            adj[v][u]--;
            if(x == v) return -2;
            return x;
        }
    }
    state[v] = 2;
    return -1;
}

void check_cohesion(int v, vector<bool>& vis) 
{
    vis[v] = true;
    for(int u = 0; u < n; u++) 
        if(adj[v][u] > 0 && !vis[u]) 
            check_cohesion(u, vis);
}

void init()
{
    adj.resize(n, vector<int>(n, 0));
    inDeg.resize(n);
    outDeg.resize(n);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n < 2)
    {
        cout << "NIE\n";
        return 0;
    }
    init();
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        for(int j = 0; j < x; j++)
        {
            int a; cin >> a; a--;
            adj[i][a]++;
            cntEdges++;
            outDeg[i]++;
            inDeg[a]++;
        }
    }

    vector<bool> visited(n, false);
    check_cohesion(0, visited);
    long long reachableEdges = 0;
    for(int i = 0; i < n; i++) 
        if(visited[i]) 
            reachableEdges += outDeg[i];
    if(reachableEdges == cntEdges)
    {
        if(outDeg[0] == (inDeg[0] + 1))
        {
            bool equal = true;
            for(int i = 1; i < n - 1; i++)
            {
                if(inDeg[i] != outDeg[i])
                {
                    equal = false;
                    break;
                }
            }
            if(equal && ((outDeg[n - 1] + 1) == inDeg[n - 1]))
            {
                //sciezka z ewentualnymi cyklami
                vector<int> state(n, 0);
                vector<int> parent(n, -1);
                int remCyc = remove_cycle(0, state, parent);
                if(remCyc == -1)
                {
                    cout << "NIE\n";
                    return 0;
                }
            }
        }
    }

    //kazda sciezka wygrywajaca
    int curr = 0;
    while (true)
    {
        int next_u = -1;
        for (int u = 0; u < n; u++)
        {
            if (adj[curr][u] > 0)
            {
                next_u = u;
                break;
            }
        }
        if (next_u == -1) break;
        adj[curr][next_u]--;
        ans.push_back(next_u);
        curr = next_u;
    }
    for(int x : ans)
        cout << x + 1 << ' ';
    cout << 0 << '\n';
    return 0;
}
