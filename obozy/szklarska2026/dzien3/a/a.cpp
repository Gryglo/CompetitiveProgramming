#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, m;

struct Component
{
    vector<int> nodes;
    vector<int> pktArtSubT;
    int componentSize = 0;
    int color = 0;
};

vector<vector<int>> colors;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> incnt, low, subTreeS;
int timer = 0;
int colosSize_i = 0;
vector<int> colorSizes;
vector<int> vColor;

stack<pii> st;
vector<Component> skladowe;
vector<int> parent;
int graphCnt = 0;

int DFS(int v, int p = -1)
{
    visited[v] = true;
    incnt[v] = low[v] = timer++;
    parent[v] = p;
    int childSum = 1;
    vColor[v] = colosSize_i;

    for(int u : adj[v])
    {
        if(u == p) continue;

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
            int sub = DFS(u, v);
            childSum += sub;

            low[v] = min(low[v], low[u]);

            if(low[u] >= incnt[v])
            {
                if(low[u] > incnt[v])
                {
                    st.pop(); 
                }
                else
                {
                    Component component;
                    set<int> verts;
                    while(true)
                    {
                        pii e = st.top();
                        st.pop();
                        verts.insert(e.f);
                        verts.insert(e.s);
                        if(e.f == v && e.s == u)
                            break;
                    }
                    component.nodes.assign(verts.begin(), verts.end());
                    for(int i = 0; i < component.nodes.size(); i++)
                        colors[component.nodes[i]].push_back(skladowe.size());
                    component.componentSize = component.nodes.size();
                    skladowe.push_back(component);
                }
            }
        }
    }

    subTreeS[v] = childSum;
    return childSum;
}

void computeArtykulacji(int root) 
{
    int allVCnt = subTreeS[root];
    for(int v = 0; v < n; v++)
    {
        for(int fColor : colors[v])
        {
            int currsum = 1;
            for(int u : adj[v])
            {
                bool isIn = false;
                for(int sColor : colors[u])
                {
                    if(sColor == fColor) {
                        isIn = true; break;
                    }
                }
                if(!isIn) //odcinamy
                {
                    if(parent[v] == u)
                        currsum += (allVCnt - subTreeS[v]);
                    else
                        currsum += subTreeS[u];
                }
            }
            if(currsum > 1)
                skladowe[fColor].pktArtSubT.push_back(currsum);
        }
    }
}
void setup()
{
    adj.resize(n);
    visited.assign(n,false);
    low.resize(n);
    subTreeS.resize(n);
    incnt.resize(n);
    colors.resize(n);
    parent.resize(n);
    vColor.resize(n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    setup();

    for(int i = 0; i < m; i++)
    {
        int a, b; 
        cin >> a >> b; 
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            DFS(i);
            colorSizes.push_back(subTreeS[i]);
            colosSize_i++;
            computeArtykulacji(i);
        }
    }

    ll ans = n * (n - 1) * (n - 2);
    for(int v = 0; v < n; v++)
    {
        if(colors[v].size() == 0) //case dla pojedynczego wierzcholka
        {
            int allVCnt = colorSizes[vColor[v]];
            for(int u : adj[v])
            {
                if(parent[v] == u)
                    ans -= ((allVCnt - subTreeS[v]) * (allVCnt - subTreeS[v] - 1));
                else
                    ans -= (subTreeS[u] * (subTreeS[u] - 1));
            }
        }
    }
    for(Component& component : skladowe)
    {
        ll sumTrees = 0;
        for(ll curr : component.pktArtSubT)
            sumTrees += (curr * (curr - 1));
        ll Xi = component.pktArtSubT.size();
        ll all = component.componentSize;
        ll Vi = all - Xi;
        ans -= ((Vi + Xi - 1) * (sumTrees));
    }
    cout << ans;
    return 0;
}