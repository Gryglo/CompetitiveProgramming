#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> t;
vector<int> incnt, low;
stack<int> st;
vector<ll> spojnaCnt;
vector<ll> sz;
int timer = 0;
int vSpojneCnt;
ll ans = 0;
void DFS(int v) 
{
    timer++;
    incnt[v] = timer;
    low[v] = timer;
    st.push(v);
    for (int u : adj[v]) 
    {
        if (incnt[u] == 0) 
        {
            DFS(u);
            low[v] = min(low[v], low[u]);
            if (low[u] >= incnt[v]) 
            {
                vSpojneCnt++;
                int spojna_i = vSpojneCnt;
                spojnaCnt[spojna_i] = 0; 
                int x;
                do 
                {
                    x = st.top();
                    st.pop();
                    t[spojna_i].push_back(x);
                    t[x].push_back(spojna_i);
                    spojnaCnt[spojna_i]++;
                } while (x != u);
                t[spojna_i].push_back(v);
                t[v].push_back(spojna_i);
                spojnaCnt[spojna_i]++;
            }
        } 
        else
            low[v] = min(low[v], incnt[u]);
    }
}

void computeArtykulacji(int v, int p, int vCnt) 
{
    sz[v] = (v <= n ? 1 : 0);
    ll ways = (ll)vCnt * (vCnt - 1);

    for (int u : t[v]) 
    {
        if (u == p) continue;
        computeArtykulacji(u, v, vCnt);
        ways -= sz[u] * (sz[u] - 1);
        sz[v] += sz[u];
    }
    ways -= (ll)(vCnt - sz[v]) * (vCnt - sz[v] - 1);
    ans += ways * spojnaCnt[v];
}

void setup()
{
    adj.resize(n + 5);
    //visited.assign(n,false);
    low.resize(n + 5);
    //subTreeS.resize(n);
    incnt.resize(n + 5);
    //colors.resize(n);
    //parent.resize(n);
    //vColor.resize(n);
    t.resize(2 * n + 1);
    spojnaCnt.assign(2 * n + 1, -1);
    sz.assign(2 * n + 1, 0);
}
int32_t main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    setup();
    vSpojneCnt = n;
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> roots;
    for (int i = 1; i <= n; i++) 
    {
        if (incnt[i] == 0) 
        {
            int prevTimer = timer;
            int startNodeCnt = 0;
            int prev_n = 0;
            stack<int> q;
            q.push(i);
            vector<int> vSpojna;
            vector<bool> visited(n + 1, false);
            visited[i] = true;
            while(!q.empty())
            {
                int curr = q.top(); q.pop();
                vSpojna.push_back(curr);
                for(int u : adj[curr]) 
                {
                    if(!visited[u]) 
                    {
                        visited[u]=true; 
                        q.push(u);
                    }
                }
            }

            DFS(i);
            while(!st.empty()) 
                st.pop();
            computeArtykulacji(i, -1, vSpojna.size());
        }
    }

    cout << ans << '\n';
    return 0;
}