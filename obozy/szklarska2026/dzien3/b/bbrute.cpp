#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

vector<int> sel;
bool DFS(int v, int parent)
{   
    for(int u : adj[v])
    {
        if(u == parent) continue;
        //para v u
        int cntW = 0;
        if(sel[u] == 0 && sel[v] == 0)
        {
            for(int uu : adj[u])
                cntW += sel[uu];
            for(int uv : adj[v])
                cntW += sel[uv];
            if(cntW < 2) 
                return false;
        }
        //git
        bool res = DFS(u, v);
        if(!res) return false;
    }
    return true;
}


bool select(int last_v, int x)
{
    if(x == 0)
    {
        //sprawd ta kombinacje
        bool res = DFS(0, -1);
        if(res) 
            return true;
    }
    else
    {
        for(int i = last_v + 1; i < n; i++)
        {
            for(int j = 1; j <= x; j++)
            {
                sel[i] = j;
                if(select(i, x - j)) return true;
                sel[i] = 0;
            }
        }
    }
    return false;
}

bool checkCount(int x)
{
    sel.assign(n, 0);
    return select(-1, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a,b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int minAns = n;
    int l = 1, r = n;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(checkCount(m))
        {
            minAns = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << minAns;
    return 0;
}