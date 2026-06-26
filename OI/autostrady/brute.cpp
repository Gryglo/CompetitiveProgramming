/* 
    -=-=-=-=-=-=-
    TASK: AUTOSTRADY
    SCORE: 40
    LINK: https://szkopul.edu.pl/problemset/problem/FKqZZxq392rXuZdedx7vm5kh/site/?key=statement
    -=-=-=-=-=-=-
*/
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

int n, k;
vector<pii> road;
vector<vector<int>> adj;

bool valid = true;
vector<short> side;

void DFS(int v, int a)
{
    if(!valid) return;
    side[v] = a;
    for(int u : adj[v])
    {
        if(side[u] != 2)
        {
            if(side[v] == side[u]) 
                valid = false; 
        }
        else DFS(u, (a + 1) % 2);
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    road.resize(k);
    adj.resize(k);
    for(int i = 0; i < k; i++) 
        cin >> road[i].f >> road[i].s;
    side.resize(k, 2);
}

int main()
{
    init();
    for(int i = 0; i < k; i++) for(int j = 0; j < k; j++)
    if(road[i].s > road[j].f && road[i].s < road[j].s && road[i].f < road[j].f)
    { adj[i].push_back(j); adj[j].push_back(i); }

    for(int i = 0; i < k; i++) 
    if(side[i] == 2) DFS(i, 0);
    if(!valid) cout << "NIE";
    else
    {
        for(short& c : side)
        {
            if(c == 0) cout << "N\n";
            else cout << "S\n";
        }
    }
    return 0;
}