#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int P = 31;
const int MOD = 1e9 + 7;
int n, k;
int start_v = -1, end_v = -1, last_v = -1;
vector<int> p;
vector<string> input;
unordered_map<int, vector<int>> adj;
unordered_map<int, string> hash_string;
unordered_map<int, int> vis;
unordered_map<int, int> tin;
void compute_powers(int size)
{
    p.resize(size + 1, 1);
    for(int i = 1; i <= size; i++) p[i] = p[i - 1] * P;
}

pii calc_hash(string& x)
{
    int front = 0, back = 0;
    for(int i = 0; i < k - 1; i++) front += (x[i] - 'a' + 1) * p[i];
    for(int i = 1; i < k; i++) back += (x[i] - 'a' + 1) * p[i - 1];
    return {front, back};
}


void euler_path(int v, vector<int>& path)
{
    while(vis[v] < adj[v].size())
    {
        int u = adj[v][vis[v]];
        vis[v]++;
        euler_path(u, path);
    }
    path.push_back(v);
}

bool check_valid()
{
    for(const pair<int, vector<int>>& el : adj)
    {
        int t_out = el.s.size();
        int t_in = tin[el.f];
        if(t_out == t_in + 1 && start_v == -1) start_v = el.f;
        else if(t_out + 1 == t_in && end_v == -1) end_v = el.f;
        else if(t_out == t_in) last_v = el.f;
        else return false;
    }
    return true;
}
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    input.resize(n);
    compute_powers(k);
    for(int i = 0; i < n; i++)
    {
        string x; cin >> x;
        input[i] = x;
        pii hashes = calc_hash(x);
        string x2 = x.substr(1, x.size() - 1);
        x.pop_back();
        hash_string[hashes.f] = x;
        hash_string[hashes.s] = x2;
        adj[hashes.f].push_back(hashes.s);
        tin[hashes.s]++;
    }
}

int32_t main()
{
    //totalnie inny kod v2
    init();
    if(k == 1)
    {
        for(string& x : input) cout << x;
        return 0;
    }
    if(!check_valid()) { cout << -1 << '\n'; return 0; }
    vector<int> path;
    euler_path((start_v != -1 ? start_v : last_v), path);
    if(path.size() != n + 1) { cout << -1 << '\n'; return 0; }
    reverse(path.begin(), path.end());
    string ans = "";
    for(int i = 0; i < path.size(); i++)
    {
        int v = path[i];
        if(i == path.size() - 1) ans += hash_string[v];
        else ans += hash_string[v][0]; 
    }
    cout << ans << '\n';
    return 0;
}