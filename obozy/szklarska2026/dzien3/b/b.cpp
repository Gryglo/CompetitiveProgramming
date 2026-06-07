#include <bits/stdc++.h>
#define int long long
using namespace std;
using walonyDP = array<array<array<int, 3>,3>,3>;
const int INF = INT_MAX;
const int MAXN = 200005;

int n;
vector<vector<int>> adj;

walonyDP mergeDP(const walonyDP& a, const walonyDP& b)
{
    walonyDP res;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                res[i][j][k] = INF;
    for(int i1 = 0; i1 < 3; i1++)
    {
        for(int j1 = 0; j1 < 3; j1++)
        {
            for(int k1 = 0; k1 < 3; k1++)
            {
                for(int i2 = 0; i2 < 3; i2++)
                {
                    for(int j2 = 0; j2 < 3; j2++)
                    {
                        for(int k2 = 0; k2 < 3; k2++)
                        {
                            if(a[i1][j1][k1] == INF) continue;
                            if(b[i2][j2][k2] == INF) continue;
                            int newInMe = min(2LL, i1 + i2);
                            int newInPar = max(j1, j2);
                            int newLater = max(0LL, max(k1 - i2, k2 - i1));
                            res[newInMe][newInPar][newLater] = 
                            min(res[newInMe][newInPar][newLater],
                            a[i1][j1][k1] + b[i2][j2][k2]);
                        }
                    }
                }
            }
        }
    }
    return res;
}

walonyDP createParent(const walonyDP& a)
{
    walonyDP res;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                res[i][j][k] = INF;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
            {
                if(a[i][j][k] == INF) continue;
                for(int newInMe = j; newInMe < 3; newInMe++)
                {
                    int newInPar;
                    int newLater;
                    if(newInMe == 0)
                    {
                        newInPar = k;
                        newLater = 2 - i;
                    }
                    else
                    {
                        newInPar = 0;
                        newLater = 0;
                    }
                    //newLater = min(newLater, 2LL);

                    res[newInMe][newInPar][newLater] = 
                    min(
                        res[newInMe][newInPar][newLater],
                    a[i][j][k] + newInMe);
                }
            }
    return res;
}

walonyDP DFS(int v, int p)
{
    bool isLeaf = true;
    walonyDP res;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                res[i][j][k] = INF;
    res[0][0][0] = 0;
    for(int u : adj[v])
    {
        if(u == p) continue;
        isLeaf = false;
        walonyDP childDP = DFS(u, v); 
        res = mergeDP(res, childDP);
    }
    return createParent(res);
}

void setup()
{
    adj.resize(n);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    setup();
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = INF;
    walonyDP rootDp = DFS(0, -1);
    for(int inMe = 0; inMe < 3; inMe++)
    {
        for(int k = 0; k < 3; k++)
        {
            ans = min(ans, rootDp[inMe][0][k]);
        }   
    }
    cout << ans << '\n';
    return 0;
}