#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
ll k;
vector<vector<int>> adj;
vector<bool> visited;

void modulo_multiply(ll& v, ll u)
{
    v = ((v % k) * (u % k)) % k;
}

ll silnia(int v)
{
    ll s = 1;
    for(int i = 1; i <= v; i++)
        modulo_multiply(s, i);
    return s;
}

ll normalNodesCnt = 0;
ll graphCnt = 0;
ll freeNodes = 0;
ll result = 1;
ll currWays = 4;

void BFS(int root)
{
    //          v  parent
    queue<pii> q;
    q.push({root, -1});
    visited[root] = true;
    normalNodesCnt++;
    while(!q.empty())
    {
        pii curr = q.front();
        q.pop();
        int cntLongPaths = 0;
        int cntLeafs = 0;
        for(int u : adj[curr.first])
        {
            if(u == curr.second)
                continue;
            if(visited[u])
            {
                currWays = 0;
                return;
            }
            adj[u].size() == 1 ? cntLeafs++ : cntLongPaths++;

            visited[u] = true;
            normalNodesCnt++;
            q.push({u, curr.first});
        }

        ll leafsWays = silnia(cntLeafs);
        if(curr.second == -1 && cntLongPaths == 0 && currWays != 0)
        {
            //wszystko to liscie i jeden korzen
            currWays = 1;
            modulo_multiply(currWays, leafsWays * 2LL);
            return;
        }
        modulo_multiply(currWays, leafsWays);

        if(cntLongPaths >= 3)
            currWays = 0;
        else if(curr.second != -1)
            if(cntLongPaths == 2)
                if(adj[curr.second].size() > 1)
                    currWays = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    if(m > n)
    {
        cout << 0;
        return 0;
    }
    adj.resize(n);
    for(int i = 0; i < m; i++)
    {   
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.resize(n);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            //3 przypadki
            //1 wierzochlek
            //2 polaczone ze soba
            //wszystko to liscie i jeden korzen
            //no i normalny graf
            if(adj[i].size() == 0)
            {
                freeNodes++;
                continue;
            }
            else if(adj[i].size() == 1)
            {
                if(adj[adj[i][0]].size() == 1)
                {
                    // podwojny
                    modulo_multiply(result, 2);
                    graphCnt++;
                    visited[i] = true;
                    visited[adj[i][0]] = true;
                    normalNodesCnt += 2;
                }
                continue;
            }
            currWays = 4;
            //DFS(i, -1);
            BFS(i);
            modulo_multiply(result, currWays);
            if(result == 0)
            {
                cout << 0;
                return 0;
            }
            graphCnt++;
        }
    }
    modulo_multiply(result, silnia(graphCnt));

    if(freeNodes > 0)
    {
        for(int i = 0; i < freeNodes; i++)
            modulo_multiply(result, normalNodesCnt + 2 + i);
    }
    cout << result;
    return 0;
}