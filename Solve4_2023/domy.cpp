#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define ll long long
using namespace std;


void bfs(vector<int>& homes, const int N, vector<vector<ll>>& graf)
{
    vector<int> dist(N + 1, -1);
    vector<int> owner(N + 1, -1);

    queue<int> q;
    for(int home : homes) 
    {
        dist[home] = 0;
        owner[home] = home;
        q.push(home);
    }

    int minDist = INT_MAX;

    while(!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for(int v : graf[u]) 
        {
            if(dist[v] == -1) 
            {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];
                q.push(v);
            } 
            else if(owner[v] != owner[u]) 
            {
                minDist = min(minDist, dist[v] + dist[u] + 1);
            }
        }
    }
    if(minDist == INT_MAX) 
        cout << "NIE\n";
    else 
        cout << minDist << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll Q;
    cin >> Q;
    for(int i = 0 ; i < Q; i++)
    {
        ll N, M;
        cin >> N >> M;

        vector<vector<ll>> graf(N + 1);

        for(int i = 0; i < M; i++)
        {   
            ll a, b;
            cin >> a >> b;

            graf[a].push_back(b);
            graf[b].push_back(a);
        }

        ll D;
        cin >> D;
        vector<int> homes(D);
        for(int i = 0; i < D; i++)
            cin >> homes[i];
        bfs(homes, N, graf);
    }
    return 0;
}
