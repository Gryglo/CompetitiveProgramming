#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXK = 10'000 + 5;

int n, m, S, T;
vector<pii> matches;
struct Flow_graph
{
    struct Edge { int u, flow, max_flow; size_t rev_i; };
    vector<vector<Edge>> adj;
    vector<int> lvl, ptr;
    int sz;

    Flow_graph(){}
    Flow_graph(int sz)
    {
        this->sz = sz; 
        adj.resize(sz);
    }

    void add_edge(int v, int u, int max_flow)
    {
        adj[v].push_back({u, 0, max_flow, adj[u].size()});
        adj[u].push_back({v, 0, 0, adj[v].size() - 1});
    }

    bool bfs()
    {
        lvl.assign(sz, -1);
        queue<int> q;
        q.push(S); lvl[S] = 0;
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(Edge& edge : adj[v])
            {
                if(lvl[edge.u] != -1) continue;
                if(edge.max_flow == edge.flow) continue;
                lvl[edge.u] = lvl[v] + 1;
                q.push(edge.u);
            }
        }
        return (lvl[T] != -1);
    }

    int DFS(int v, int curr_flow)
    {
        if(v == T || curr_flow == 0) return curr_flow;
        for(; ptr[v] < adj[v].size(); ptr[v]++)
        {
            Edge& edge = adj[v][ptr[v]];
            if(lvl[edge.u] != lvl[v] + 1) continue;
            if(edge.max_flow - edge.flow == 0) continue;
            int end_flow = DFS(edge.u, min(curr_flow, edge.max_flow - edge.flow));
            if(end_flow == 0) continue;
            edge.flow += end_flow;
            adj[edge.u][edge.rev_i].flow -= end_flow;
            return end_flow;
        }
        return 0;
    }

    bool max_flow_dinic()
    {
        int flow = 0;
        while(bfs())
        {
            ptr.assign(sz, 0);
            while (int pushed = DFS(S, MAXK)) 
            { flow += pushed; }
        }
        return flow == m;
    }

    void reset(int k) 
    {
        for (int v = 0; v < sz; v++) 
        {
            for (Edge& edge : adj[v]) 
            {
                edge.flow = 0;
                if (v < n && edge.u == T) edge.max_flow = k;
            }
        }
    }
};

Flow_graph flow_g;
void print_ans(int ans)
{
    flow_g.reset(ans);
    flow_g.max_flow_dinic();
    cout << ans << '\n';
    for(int i = n + 2; i < n + 2 + m; i++)
    {
        if(flow_g.adj[i][1].flow == 1) cout << "1\n";
        else cout << "0\n";
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    matches.resize(m);
    for(int i = 0; i < m; i++) cin >> matches[i].f >> matches[i].s;
    flow_g = Flow_graph(n + m + 2);
    S = n, T = n + 1;
    // n - S, n + 1 - T, n + 2... n + m + 1
    for(int i = n + 2; i < n + 2 + m; i++)
    {
        int idx = i - (n + 2);
        flow_g.add_edge(S, i, 1); //0 1 2
        flow_g.add_edge(i, matches[idx].f - 1, 1);
        flow_g.add_edge(i, matches[idx].s - 1, 1);
    }
    for(int i = 0; i < n; i++) flow_g.add_edge(i, T, MAXK);
}

int32_t main()
{
    init();
    int l = 0, r = MAXK, ans = MAXK;
    while(l <= r)
    {
        int m = (l + r) / 2;
        flow_g.reset(m);
        if(flow_g.max_flow_dinic()) { ans = m; r = m - 1; }
        else l = m + 1;
    }
    print_ans(ans);
    return 0;
}