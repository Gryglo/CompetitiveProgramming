#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int INF = 4e9;
struct Tower
{
	pii pos; int cost, i;
	Tower(){}
};
int n;
vector<Tower> towers;
vector<vector<pii>> adj;

int new_node()
{
	adj.push_back(vector<pii>(0));
	return adj.size() - 1;
}

void add_edge(int a, int b, int c)
{
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
}

void connect_tower(Tower& curr_tower, int& k, int& curr_i, vector<Tower>& new_order)
{
    new_order[curr_i++] = curr_tower;
    int curr_node = new_node();
    if(curr_i > 1) add_edge(curr_node, curr_node - 1, abs(curr_tower.pos.s - new_order[curr_i - 2].pos.s));
    int d = abs(curr_tower.pos.f - k);
    add_edge(curr_tower.i, curr_node, d);
}

void merge(int l, int r)
{
	if(l == r) return;
	int m = (l + r) / 2;
	int k = towers[m].pos.f;
	merge(l, m);
	merge(m + 1, r);
    int l_i = l, r_i = m + 1;
    vector<Tower> new_order(r - l + 1);
    int curr_i = 0;
    while(l_i <= m && r_i <= r)
    {
        Tower curr_tower;
        if(towers[l_i].pos.s <= towers[r_i].pos.s) { curr_tower = towers[l_i]; l_i++; }
        else { curr_tower = towers[r_i]; r_i++; }
        connect_tower(curr_tower, k, curr_i, new_order);
    }
    
    while(l_i <= m)
    { connect_tower(towers[l_i], k, curr_i, new_order); l_i++; }

    while(r_i <= r)
    { connect_tower(towers[r_i], k, curr_i, new_order); r_i++; }

    for(int i = l; i <= r; i++) towers[i] = new_order[i - l];
}

vector<int> dist;
void dijkstra()
{
    priority_queue<pii> pq; //dist, v
    dist.resize(adj.size(), INF);
    for(int i = 0; i < n; i++)
    {
        pq.push({-towers[i].cost, towers[i].i});
        dist[towers[i].i] = towers[i].cost;
    }

    while(!pq.empty())
    {
        pii curr = pq.top();
        pq.pop();
        if(-curr.f > dist[curr.s]) continue;
        for(pii u : adj[curr.s])
        {
            if(dist[curr.s] + u.s < dist[u.f])
            {
                dist[u.f] = dist[curr.s] + u.s;
                pq.push({-dist[u.f], u.f});
            }
        }
    }
}

bool sort_x(const Tower& a, const Tower& b)
{
	if(a.pos.f <= b.pos.f) return true;
	return false;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	towers.resize(n);
	for(int i = 0; i < n; i++)
    {
        cin >> towers[i].pos.f >> towers[i].pos.s >> towers[i].cost;
        towers[i].i = i;
    } 
	sort(towers.begin(), towers.end(), sort_x);
	adj.resize(n);
}

signed main()
{
	init();
    merge(0, n - 1);
    dijkstra();
    vector<int> ans(n);
    for(int i = 0; i < n; i++) cout << dist[i] << '\n';
	return 0;
}