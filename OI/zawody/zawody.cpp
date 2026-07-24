#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using piii = pair<pair<int, int>, int>;
#define f first
#define s second

const int INF = INT_MAX;

int n, m;
//    {u, w}
vector<vector<pii>> adj;
vector<vector<pii>> adj2;

vector<int> dist_in;
vector<int> dist_out;
vector<int> node_num;
vector<int> p_in;
vector<int> p_out;

int result = INF;

void BFS(int v)
{
    queue<int> q;
    vector<bool> visited(n);
    q.push(v);
    visited[v] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(pii u : adj[curr])
        {
            //porownanie
            if(curr != 0 && u.f != 0)
            {
                if(node_num[curr] != node_num[u.f])
                    result = min(result, dist_in[curr] + dist_out[u.f] + u.s);
            }
            if(!visited[u.f])
            {
                visited[u.f] = true;
                q.push(u.f);
            }
        }
    }
}

void dijkstra_out(int v)
{
    //          -dist v
    priority_queue<pii> q;
    q.push({ 0, v });
    dist_out[0] = 0;
    while (!q.empty())
    {
        pii curr = q.top();
        q.pop();

        if(dist_out[curr.s] < -curr.f)
            continue;

        for(int i = 0; i < adj2[curr.s].size(); i++)
        {
            pii u = adj2[curr.s][i];
            if((node_num[u.f] != node_num[curr.s]) && (curr.s != 0))
                continue;
            if(dist_out[u.f] > dist_out[curr.s] + u.s)
            {
                dist_out[u.f] = dist_out[curr.s] + u.s;
                if((curr.s != 0) && p_out[u.f] != -1) //cykl
                    result = min(result, dist_out[u.f] + p_out[u.f]);
                q.push({ -dist_out[u.f], u.f });
            }
        }
    }
}

void dijkstra_in(int v)
{
    //          -dist v
    priority_queue<piii> q;
    q.push({{ 0, v }, -1});
    dist_in[0] = 0;

    while (!q.empty())
    {
        piii currQ = q.top();
        pii curr = currQ.first;
        q.pop();

        if(dist_in[curr.s] < -curr.f)
            continue;

        node_num[curr.s] = currQ.s;

        for(int i = 0; i < adj[curr.s].size(); i++)
        {
            pii u = adj[curr.s][i];
            if(dist_in[u.f] > dist_in[curr.s] + u.s)
            {
                dist_in[u.f] = dist_in[curr.s] + u.s;
                if(curr.s == 0)
                    q.push({{ -dist_in[u.f], u.f }, i});
                else
                {
                    if(p_in[u.f] != -1) //cykl
                        result = min(result, dist_in[u.f] + p_in[u.f]);
                    q.push({{ -dist_in[u.f], u.f }, node_num[curr.s]});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin  >> n >> m;
    adj.resize(n);
    adj2.resize(n);
    dist_in.resize(n, INF);
    dist_out.resize(n, INF);
    node_num.resize(n, -1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int wab, wba;
        cin >> wab >> wba;
        adj[a].push_back({ b, wab });
        adj[b].push_back({ a, wba });

        adj2[a].push_back({ b, wba });
        adj2[b].push_back({ a, wab });
    }
    p_in.resize(n, -1);
    p_out.resize(n, -1);
    for(int i = 0; i < adj2[0].size(); i++)
    {
        pii u = adj2[0][i];
        p_in[u.f] = u.s;
    }
    for(int i = 0; i < adj[0].size(); i++)
    {
        pii u = adj[0][i];
        p_out[u.f] = u.s;
    }

    dijkstra_in(0);
    dijkstra_out(0);
    BFS(0);

    cout << result;

    return 0;
}