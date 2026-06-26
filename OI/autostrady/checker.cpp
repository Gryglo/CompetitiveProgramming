#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

int n, k;
vector<pii> road;
vector<vector<int>> adj;

bool valid = true;
vector<char> side;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    road.resize(k);
    adj.resize(k);
    for(int i = 0; i < k; i++) 
        cin >> road[i].f >> road[i].s;
    side.resize(k);
    for(int i = 0; i < k; i++) cin >> side[i];
}

int main()
{
    init();
    for(int i = 0; i < k; i++) for(int j = 0; j < k; j++)
    if(road[i].s > road[j].f && road[i].s < road[j].s && road[i].f < road[j].f)
    { adj[i].push_back(j); adj[j].push_back(i); }
    for(int v = 0; v < k; v++)
    {
        for(int u : adj[v])
        {
            if(side[v] == side[u])
            {
                cout << v << ' ' << u;
                return 0;
            }
        }
    }
    cout << "OK";
    return 0;
}