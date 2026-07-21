
/*************************************************************************}
{*                                                                       
{*   Zadanie: Magazynier (mag)                                           
{*   Score:   100                                                        
{*   Link:    https://szkopul.edu.pl/problemset/problem/i7RSA7WlQYQzXFjBLHIW5J3_/site/?key=statement                   
{*                                                                       
{*************************************************************************/
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

const int INF = SHRT_MAX;
const int MASK = 16383;
const int MASK_LEN = 14;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m;
int board_size;
int timer = 0;
pii p_pos, k_pos, m_pos;
vector<vector<bool>> board;
vector<bool> vis_dfs;
vector<int> depth, min_d, tin, tout;
vector<vector<int>> t;
unordered_map<int, int> vis;

int pos_to_id(pii pos) { return (pos.f * m + pos.s); }
pii id_to_pos(int id) { return { id / m, id % m }; }
int state_to_mask(pii _m_pos, pii _p_pos)
{ return (pos_to_id(_m_pos) | (pos_to_id(_p_pos) << MASK_LEN)); }
pair<pii, pii> mask_to_state(int mask)
{ return {id_to_pos(mask & MASK), id_to_pos(mask >> MASK_LEN)}; }

bool pos_valid(pii pos)
{ 
    return (pos.f >= 0 && pos.f < n && pos.s >= 0 && pos.s < m 
    && !board[pos.f][pos.s]); 
}

void DFS(int v, int d)
{
    vis_dfs[v] = true;
    tin[v]     = ++timer;
    depth[v]   = d + 1;
    min_d[v]   = min(min_d[v], d + 1);
    pii pos    = id_to_pos(v);
    for(int i = 0; i < 4; i++)
    {
        pii next = {pos.f + dx[i], pos.s + dy[i]};
        if(!pos_valid(next)) continue;
        int u = pos_to_id(next);
        if(vis_dfs[u])
        { min_d[v] = min(min_d[v], depth[u]); continue; }
        DFS(u, depth[v]);
        t[v].push_back(u);
        min_d[v] = min(min_d[v], min_d[u]);
    }
    tout[v] = ++timer;
}

void compute_tree()
{
    vis_dfs.resize(board_size + 1);
    depth.resize(board_size + 1, INF);
    min_d.resize(board_size + 1, INF);
    tin.resize(board_size + 1);
    tout.resize(board_size + 1);
    t.resize(board_size + 1);
    DFS(pos_to_id(m_pos), 0);
}

bool can_achieve(pii from, pii to, pii blocked)
{
    int blocked_id = pos_to_id(blocked);
    int from_id    = pos_to_id(from);
    int to_id      = pos_to_id(to);
    for(int u : t[blocked_id])
    {
        if(min_d[u] < depth[blocked_id]) continue;
        bool is_from = (tin[from_id] >= tin[u] && tout[from_id] <= tout[u]);
        bool is_to   = (tin[to_id] >= tin[u] && tout[to_id] <= tout[u]);
        if((is_from && !is_to) || (!is_from && is_to)) return false;
        if(is_to && is_from) return true;
    }
    return true;
}

int BFS()
{
    queue<int> q;
    int start_mask = state_to_mask(m_pos, p_pos); 
    q.push(start_mask);
    vis[start_mask] = 0;
    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        int d = vis[curr];
        pii _m_pos = mask_to_state(curr).f;
        pii _p_pos = mask_to_state(curr).s;
        if(_p_pos == k_pos) return vis[curr];
        for(int i = 0; i < 4; i++)
        {
            pii next_p = {_p_pos.f + dx[i], _p_pos.s + dy[i]};
            pii t_m    = {_p_pos.f - dx[i], _p_pos.s - dy[i]};
            if(!pos_valid(next_p) || !pos_valid(t_m)) continue;
            if(!can_achieve(_m_pos, t_m, _p_pos)) continue;
            int next_mask = state_to_mask(_p_pos, next_p);
            if(vis[next_mask]) continue;
            vis[next_mask] = d + 1;
            q.push(next_mask);
        }
    }
    return -1;
}


void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    board.resize(n, vector<bool>(m));
    board_size = n * m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char x; cin >> x;
            if(x == 'S') board[i][j] = true;
            else if(x == 'P') p_pos = {i, j};
            else if(x == 'M') m_pos = {i, j};
            else if(x == 'K') k_pos = {i, j};
        }
    }
}

int main()
{
    init();
    compute_tree();
    if(!vis_dfs[pos_to_id(p_pos)] || !vis_dfs[pos_to_id(k_pos)])
    { cout << "NIE"; return 0; }
    int ans = BFS();
    if(ans == -1) cout << "NIE";
    else cout << ans;
    return 0;
}