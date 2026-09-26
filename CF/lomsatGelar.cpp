#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n;
vector<vector<int>> adj;
vector<int> ans;
struct Subtree
{
    int max_sum = 0;
    int max_cnt = 0;
    map<int, int> colors;
    Subtree() {}
    Subtree(int color)
    {
        colors[color]++;
        max_cnt = 1;
        max_sum = color;
    }
    void add_color(int color, int color_cnt)
    {
        colors[color] += color_cnt;
        int curr_cnt = colors[color];
        if(curr_cnt > max_cnt)
        {   
            max_cnt = curr_cnt;
            max_sum = color;
        }
        else if(curr_cnt == max_cnt) max_sum += color;
    }
};
vector<Subtree> v_colors;

void merge(int v, int u)
{
    if(v_colors[v].colors.size() < v_colors[u].colors.size()) swap(v_colors[v], v_colors[u]);
    for(auto curr : v_colors[u].colors) v_colors[v].add_color(curr.first, curr.second);
    v_colors[u].colors.clear();
}

void DFS(int v, int p)
{
    for(int u : adj[v])
    {
        if(u == p) continue;
        DFS(u, v);
        merge(v, u);
    }
    ans[v] = v_colors[v].max_sum;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.resize(n);
    ans.resize(n);
    v_colors.resize(n);
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        v_colors[i] = Subtree(x);
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int32_t main()
{
    init();
    DFS(0, -1);
    for(int x : ans)
    {
        cout << x << ' ';
    }
    return 0;
}