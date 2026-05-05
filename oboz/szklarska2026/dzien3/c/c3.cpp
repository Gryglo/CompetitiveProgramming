#include <bits/stdc++.h>    
using namespace std;
#define f first
#define s second
using pii = pair<int, int>;

const int INF = INT_MAX;

int n;
int a = INF, b = 0;
vector<vector<pii>> adj;
/* 
vector<int> parent;
vector<int> rank;
int find(int v)
{
    if(parent[v] == v) return v;
    return find(parent[v]);
}

void merge(int v, int u)
{
    int a = find(v);
    int b = find(u);
    if(a != b)
    {
        if(rank[v] == rank[u])
        {
            rank[a]++;
            parent[b] = a;
        }
        else if(rank[v] > rank[b])
            parent[b] = a;
        else
            parent[a] = b;
    }   
}
 */

void setup()
{
    adj.resize(n);
    /* rank.resize(n);
    parent.resize(n);
    for(int i = 0; i < n; i++)
        parent[i] = i; */
}

int ask(vector<int>& colors)
{
    cout << "?";
    for(int c : colors)
        cout << ' ' << c;
    cout << endl;
    int res; cin >> res; return res;
}

int main()
{
    cin >> n;
    setup();
    if(n <= 60)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                vector<int> colors(n);
                colors[i] = 1; colors[j] = 2;
                int w = ask(colors);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        priority_queue<pair<pii, int>> pq;
        vector<bool> visited(n);
        pq.push({{0, 0}, -1});
        vector<pii> ans;
        while(!pq.empty())
        {
            pair<pii, int> curr = pq.top();
            pq.pop();
            int v = curr.f.s;
            int p = curr.s;
            if(visited[v])
                continue;
            if(p != -1)
                ans.push_back({p, v});
            visited[v] = true;

            for(pii u : adj[v])
            {
                if(!visited[u.f])
                    pq.push({{-u.s, u.f}, v});
            }
        }

        cout << "! " << ans.size() << endl;
        for(pii curr : ans)
        {
            cout << curr.f + 1 << ' ' << curr.s + 1 << endl;
        }
        return 0;
    }

    vector<pii> ans;
    vector<int> possible;
    vector<bool> added(n); 
    int curr = 0;
    vector<int> currList;
    while(curr != -1)
    {
        added[curr] = true;
        currList.push_back(curr);
        possible.clear();
        for(int i = 0; i < n; i++)
        {
            if(!added[i])
                possible.push_back(i);
        }
        if(possible.size() == 0)
        {
            break;
        }
        int l = 0, r = possible.size() - 1;
        while(l < r)
        {
            int m = (l + r) / 2;
            int sz = (r - l + 1);
            if(sz % 2 == 0)
            {
                //[l, m] i [m + 1, r]
                vector<int> left(n);
                left[curr] = 1;
                for(int i = l; i <= m; i++)
                    left[possible[i]] = 2;
                vector<int> right(n);
                right[curr] = 1;
                for(int i = m + 1; i <= r; i++)
                    right[possible[i]] = 2;
                int sumL = ask(left);
                int sumR = ask(right);
                if(sumL < sumR)
                    r = m;
                else
                    l = m + 1;
            }
            else
            {
                //[l, m] i [m, r]
                vector<int> left(n);
                left[curr] = 1;
                for(int i = l; i <= m; i++)
                    left[possible[i]] = 2;
                vector<int> right(n);
                right[curr] = 1;
                for(int i = m; i <= r; i++)
                    right[possible[i]] = 2;
                int sumL = ask(left);
                int sumR = ask(right);
                if(sumL < sumR)
                    r = m;
                else
                    l = m;
            }
        }
        //l to nasza droga

        ans.push_back({curr, possible[l]});
        added[possible[l]] = true;
        curr = -1;
        for(int i = 0; i < n; i++)
        {
            if(!added[i])
            {
                curr = i;
                break;
            }
        }
    }

    for(int i = 1; i < currList.size(); i++)
        ans.push_back({currList[0], currList[i]});
    cout << "! " << ans.size() << endl;
    for(pii curr : ans)
    {
        cout << curr.f + 1 << ' ' << curr.s + 1 << endl;
    }
    return 0;
}