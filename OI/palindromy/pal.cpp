#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = INT_MAX;

const ll MOD = 1e9 + 7;
const ll POW = 31;

int n;
string a;
vector<vector<int>> adj;

vector<ll> h;
vector<ll> h_rev;
vector<ll> p;

vector<pii> dp_max;
vector<pii> dp_min;

vector<bool> vis;

void DFS(int v)
{
    vis[v] = true;
    if(adj[v].size() == 0)
    {
        if(v == n) { dp_max[v] = {1, -1}; dp_min[v] = {1, -1}; }
        else { dp_max[v] = {-INF, -1}; dp_min[v] = {INF, -1}; }
        return;
    }
    pii max_v = {-INF, -1};
    pii min_v = {INF, -1};
    for(int u : adj[v])
    {
        if(!vis[u]) DFS(u);
        if(max_v < dp_max[u])
            max_v = { dp_max[u].f, u };
        if(min_v > dp_min[u])
            min_v = { dp_min[u].f, u };
    }
    max_v.f++; min_v.f++;
    dp_max[v] = max_v;
    dp_min[v] = min_v;
}

ll get_hash(int i, int j, vector<ll>& ht)
{
    ll prev = (i > 0) ? ht[i - 1] : 0;
    ll curr_hash = (ht[j] + MOD - prev) % MOD;
    curr_hash = (curr_hash * p[n - 1 - j]) % MOD;
    return curr_hash;
}

void create_graph()
{
    for(int i = 0; i < n; i += 2)
    {
        for(int j = i + 1; j < n; j += 2)
        {
            int j_rev = (n - 1) - i;
            int i_rev = j_rev - (j - i);
            ll curr_h = get_hash(i, j, h);
            ll curr_h_rev = get_hash(i_rev, j_rev, h_rev);
            if(curr_h == curr_h_rev)
                adj[i].push_back(j + 1);
        }
    }
}

void compute_powers()
{
    p.resize(n);
    p[0] = 1;
    for(int i = 1; i < n; i++)
        p[i] = (p[i - 1] * POW) % MOD;
}

void calc_hash(string& x, vector<ll>& ht)
{
    ht.resize(n);
    ht[0] = (x[0] - 'a' + 1);
    for(int i = 1; i < n; i++)
        ht[i] = (ht[i - 1] + (x[i] - 'a' + 1) * p[i]) % MOD;
}

void compute_hashes()
{
    compute_powers();
    calc_hash(a, h);
    string a_rev = a;
    reverse(a_rev.begin(), a_rev.end());
    calc_hash(a_rev, h_rev);
}

void print_ans(vector<pii>& dp)
{
    int v = 0;
    while(v != -1)
    {
        string curr;
        for(int i = v; i < dp[v].s; i++)
            curr += a[i];
        cout << curr << " ";
        v = dp[v].s;
    }
}

void init()
{
    cin >> a;
    n = a.size();
    adj.resize(n + 1);
    compute_hashes();
    dp_max.resize(n + 1);
    dp_min.resize(n + 1);
    vis.resize(n + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    if(n % 2 != 0) { cout << "NIE"; return 0; }
    create_graph();
    DFS(0);
    if(dp_max[0].s == -1)
    {
        cout << "NIE";
        return 0;
    }
    print_ans(dp_min);
    cout << '\n';
    print_ans(dp_max);
    return 0;
}