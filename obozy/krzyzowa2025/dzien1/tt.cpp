#include <bits/stdc++.h>
using namespace std;

int p, t;
bool ask(vector<int>& subset)
{
    cout << "? ";
    for(int v : subset)
        cout << v + 1 << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    return (ans == 1);
}
vector<vector<int>> adj;
vector<int> parent;
vector<int> dp;
vector<bool> blacklist;
void DFS(int v, int p)
{
    parent[v] = p;
    int sum = 1;
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS(u, v);
        sum += dp[u];
    }
    dp[v] = sum;
}

void getSubset(int v, int p, vector<int>& curr)
{
    curr.push_back(v);
    for(int u : adj[v])
    {
        if(u == p) continue;
        if(blacklist[u]) continue;
        getSubset(u, v, curr);
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n, vector<int>(0));
    parent.resize(n, -1);
    dp.resize(n, 0);
    blacklist.resize(n, false);
    vector<int> subset(n);
    for(int i = 0; i < n; i++)
        subset[i] = i;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(0, -1);

    //BFS bo latwo mozna break zrobic
    /* 
    
    znajdujemy centroid czyli ten wierzcholek
    iterujemy sie po podzbiorze wierzcholkow O(n)
    na poczatku zbior wierzcholkow to wszystkie

    jak zdobyc podzbior? a walnimy DFS po prostu
    czyli funckja ktora zwraca vector podzbior
    pytamy o kazdy podzbior
    jezeli malpka w danym podzbiorze to zastepujemy podzbior
    jezeli w zadnym podzbiorze to odpowiedz mamy
    
    */
    while(true)
    {
        
        int c = subset[0];
        for(int i = 0; i < subset.size(); i++)
        {
            int v = subset[i];
            bool validChilds = true;
            int subTreesSum = 0;
            for(int u : adj[v])
            {
                if(u == parent[v]) continue;
                if(dp[u] > subset.size() / 2)
                {
                    validChilds = false;
                    break;
                }
                subTreesSum += dp[u];
            }
            if(!validChilds) continue;
            if(parent[v] != -1)
                if((subset.size() - subTreesSum - 1) > subset.size() / 2)
                    continue;
            c = v;
            break;
        }

        bool found = false;
        //CENTROID TO c
        //centroid na blackliste
        blacklist[c] = true;
        for(int u : adj[c])
        {
            vector<int> curr;
            getSubset(u, c, curr);
            if(ask(curr))
            {
                //to ten subset wiec
                subset = curr;
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "! " << c + 1 << endl;
            return;
        }
    }
}

int main()
{
    cin >> p >> t;

    while(t--)
        solve();
    return 0;
}