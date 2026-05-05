#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;

vector<int> incnt, low;
vector<bool> visited;
int timer = 0;

stack<pair<int,int>> st;
vector<vector<pair<int,int>>> skladowe;

void dfs(int v, int parent = -1)
{
    visited[v] = true;
    incnt[v] = low[v] = timer++;

    for(int u : adj[v])
    {
        if(u == parent) 
            continue;

        if(visited[u])
        {
            if(incnt[u] < incnt[v])
            {
                st.push({v,u});
                low[v] = min(low[v], incnt[u]);
            }
        }
        else
        {
            st.push({v,u});
            dfs(u, v);

            low[v] = min(low[v], low[u]);

            if(low[u] >= incnt[v])
            {
                vector<pair<int,int>> component;

                while(true)
                {
                    auto e = st.top();
                    st.pop();
                    component.push_back(e);
                    if(e.first == v && e.second == u)
                        break;
                }

                skladowe.push_back(component);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n);
    incnt.resize(n);
    low.resize(n);
    visited.resize(n);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i);

    cout << "Liczba dwuspojnych skladowych: " << skladowe.size() << "\n";

    for(int i = 0; i < skladowe.size(); i++)
    {
        cout << "Skladowa " << i+1 << ":\n";
        for(auto e : skladowe[i])
            cout << e.first+1 << " " << e.second+1 << "\n";
        cout << "\n";
    }
}