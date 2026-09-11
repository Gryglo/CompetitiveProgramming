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

void merge(int l, int r)
{
	if(l == r) return;
	int m = (l + r) / 2;
	merge(l, m);
	merge(m + 1, r);
	int k = towers[m].pos.f;
	vector<pii> temp; // y i
	for(int i = l; i <= r; i++)
	{
		int curr = new_node();
		temp.push_back({towers[i].pos.s, curr});
		int d = abs(towers[i].pos.f - k);
		add_edge(i, curr, d);
	}
	sort(temp.begin(), temp.end());
	for(int i = 0; i < temp.size() - 1; i++)
        add_edge(temp[i].s, temp[i + 1].s, abs(temp[i].f - temp[i + 1].f));
}

vector<int> dist;
void dijkstra()
{
    priority_queue<pii> pq; //dist, v
    dist.resize(adj.size(), INF);
    for(int i = 0; i < n; i++)
    {
        pq.push({-towers[i].cost, i});
        dist[i] = towers[i].cost;
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
    for(int i = 0; i < n; i++) ans[towers[i].i] = dist[i];
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
	return 0;
}