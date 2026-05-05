#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(getpid());
    int n = 2 + (rand() % 7);
    int m = 1 + (rand() % 10);
    n = 20; 
    m = 100;
    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));
    vector<pair<int, int>> c;
    int cntWrong = 0;
    bool end = false;
    //cout << n << ' ' << m << "\n\n";
    for(int i = 0; i < m; i++)
    {
        int v = 1 + (rand() % n);
        int u = 1 + (rand() % n);
        while(adj[v][u] || adj[u][v] || v == u)   
        {
            cntWrong++;
            if(cntWrong == 1000)
            {
                end = true;
                break;
            }
            v = 1 + (rand() % n);
            u = 1 + (rand() % n);
        }
        if(end)
            break;
        adj[v][u] = true;
        c.push_back({v, u});
    }
    cout << n << ' ' << c.size() << '\n';
    for(pair<int, int> p : c)
        cout << p.first << ' ' << p.second << '\n';
}