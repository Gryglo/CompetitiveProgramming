#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n;
string x;
vector<int> x_sign; 
bool BFS(int a, int b)
{
    queue<pii> q;
    map<pii, bool> vis;
    q.push({0, 0});
    vis[{0, 0}] = true;
    while (!q.empty())
    {
        pii curr = q.front();
        q.pop();
        if(curr.s == n)
        {
            if(curr.f == 0) return true;
            else continue;
        }
        int next1 = curr.f + (a * x_sign[curr.s]);
        int next2 = curr.f + (b * x_sign[curr.s]);
        int next_idx = curr.s + 1;
        if(!vis[{next1, next_idx}])
        {
            vis[{next1, next_idx}] = true;
            q.push({next1, next_idx});
        }
        if(!vis[{next2, next_idx}])
        {
            vis[{next2, next_idx}] = true;
            q.push({next2, next_idx});
        }
    }
    return false;
}

void solve()
{
    int a, b; cin >> a >> b;
    bool res = BFS(a, b);
    cout << (res ? "YES\n" : "NO\n");
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    x_sign.resize(n);
    for(int i = 0; i < n; i++)
    {
        if(x[i] == '+') x_sign[i] = 1;
        else x_sign[i] = -1;
    }
    int q; cin >> q;
    while(q--) solve();
    return 0;
}