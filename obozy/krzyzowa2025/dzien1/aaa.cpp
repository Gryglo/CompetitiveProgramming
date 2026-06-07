#include <bits/stdc++.h>
using namespace std;

int p, t;
bool ask(vector<int>& subset)
{
    cout << "? " << subset.size() << " ";
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
        if(blacklist[u]) continue;
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
    adj.assign(n, vector<int>(0));
    parent.assign(n, -1);
    blacklist.assign(n, false);
    vector<int> subset(n);
    for(int i = 0; i < n; i++)
        subset[i] = i;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

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
        parent.assign(n, -1);
        dp.assign(n, 0);
        DFS(subset[0], -1);
        if(subset.size() == 1)
        {
            cout << "! "<< c + 1 << endl;
            return;
        }
        for(int i = 0; i < subset.size(); i++)
        {
            int v = subset[i];
            bool validChilds = true;
            int subTreesSum = 0;
            for(int u : adj[v])
            {
                if(u == parent[v]) continue;
                if(blacklist[u]) continue;
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
            if(blacklist[u]) continue;
            vector<int> curr;
            getSubset(u, c, curr);
            if(ask(curr))
            {
                //to ten subset wiec
                subset = curr;
                found = true;
                break;
            }
            else
                for(int x : curr)
                    blacklist[x] = true;
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