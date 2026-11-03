#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
const int MASK_OFF = 6;
const int N = (1LL << (MASK_OFF * 2));
int n;
string ans;
vector<int> tin, tout;
vector<vector<int>> adj;
vector<int> vis;

char code_char(int code)
{
    if(0 <= code && code <= 25) return code + 'a';
    else if(26 <= code && code <= 51) return code - 26 + 'A';
    else return code - 52 + '0';
}

pair<char, char> code_chars(int code)
{
    int mask = (1 << MASK_OFF) - 1;
    int first_code = code & mask;
    int second_code = code >> MASK_OFF;
    return {code_char(first_code), code_char(second_code)};
}

int char_code(char a)
{
    if('a' <= a && a <= 'z') return a - 'a';
    else if('A' <= a && a <= 'Z') return 26 + a - 'A';
    else return 52 + a - '0';
}

int chars_code(char a, char b)
{
    int first = char_code(a);
    int second = char_code(b);
    int ans = first | (second << MASK_OFF);
    return ans;
}

void DFS(int v, vector<int>& path)
{
    while(vis[v] < adj[v].size()) DFS(adj[v][vis[v]++], path);
    path.push_back(v);
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    tin.resize(N);
    tout.resize(N);
    adj.resize(N);
    vis.resize(N);
    for(int i = 0; i < n; i++)
    {
        string x; cin >> x;
        int v = chars_code(x[0], x[1]);
        int u = chars_code(x[1], x[2]);
        tin[u]++; tout[v]++;
        adj[v].push_back(u);
    }
}

int32_t main()
{
    init();
    int start_v = -1;
    int end_v = -1;
    for(int i = 0; i < N; i++)
    {
        if(tout[i] - tin[i] == 1 && start_v == -1) start_v = i;
        else if(tin[i] - tout[i] == 1 && end_v == -1) end_v = i;
        else if(tin[i] != tout[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    if(start_v == -1)
    {
        for(int i = 0; i < N; i++)
        {
            if(tout[i] > 0)
            {
                start_v = i;
                break;
            }
        }
    }
    if(start_v == -1)
    {
        cout << "NO\n";
        return 0;
    }
    if(start_v == -1) start_v = 0;
    vector<int> path;
    DFS(start_v, path);
    if(path.size() != n + 1)
    {
        cout << "NO\n";
        return 0;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n";
    for(int x : path) ans += code_chars(x).f;
    ans += code_chars(path[path.size() - 1]).s;
    cout << ans << '\n';
    // cout << char_code('9') << '\n';
    // bitset<20> test = chars_code('9', '9');
    // cout << test;
    return 0;
}