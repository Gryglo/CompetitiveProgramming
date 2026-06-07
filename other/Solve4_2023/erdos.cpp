#include <iostream>
#include <vector>
#include <queue>

#define ll long long
using namespace std;

vector<ll> bfsDistances(int start, vector<vector<ll>>& graf) 
{
    ll n = graf.size();
    vector<ll> distance(n, 999999999);
    queue<ll> q;
    
    distance[start] = 0;
    q.push(start);

    while (!q.empty()) 
    {
        ll node = q.front();
        q.pop();

        for (ll neighbor : graf[node]) 
        {
            if (distance[neighbor] == 999999999) 
            { 
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}

int main() 
{
    ll points, connections, erdos;
    cin >> points >> connections >> erdos;

    vector<vector<ll>> graf(points + 1);

    for(int i = 0; i < connections; i++)
    {
        ll a, b;
        cin >> a >> b;

        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    vector<ll> distances = bfsDistances(erdos, graf);

    for (int i = 1; i < distances.size(); i++) 
    {
        ll result = distances[i];
        if(distances[i] >= 999999999)
            cout << "-1\n";
        else
            cout << distances[i] << '\n';
    }

    return 0;
}
