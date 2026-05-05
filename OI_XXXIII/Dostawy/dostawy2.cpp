#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

const int INF = 1e9;

int n, q;
vector<string> input;
vector<vector<int>> dist;
int dx[4] = {1, -1, 0, 0}; //wiersz
int dy[4] = {0, 0, 1, -1}; //kolumna
int maxDist = 0;
int currMaxDist = 0;
vector<int> cnt;
vector<int> costs;

vector<int> t;
vector<int> lazy;

void build_tree(int v, int l, int r)
{
    if(l == r)
        t[v] = costs[l];
    else
    {
        int m = (l + r) / 2;
        build_tree(2 * v, l, m);
        build_tree(2 * v + 1, m + 1, r);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

void BFS()
{
    queue<pii> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while(!q.empty())
    {
        pii curr = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nX = curr.first + dx[i];
            int nY = curr.second + dy[i];
            if(nX < 0 || nX >= n || nY < 0 || nY >= n)
                continue;
            if(input[nX][nY] == '#')
                continue;
            if(dist[nX][nY] == -INF)
            {
                dist[nX][nY] = dist[curr.first][curr.second] + 1;
                maxDist = max(maxDist, dist[nX][nY]);
                if(input[nX][nY] == 'F')
                    currMaxDist = max(currMaxDist, dist[nX][nY]);
                q.push({nX, nY});
            }
        }
    }
}

int main()
{
    /* ios_base::sync_with_stdio(0);
    cin.tie(0); */
    cin >> n >> q;
    input.resize(n);
    for(int i = 0; i < n; i++)
        cin >> input[i];
    dist.resize(n, vector<int>(n, -INF));
    BFS();
    cnt.resize(maxDist + 1);
    costs.resize(maxDist + 1);
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            if(input[x][y] == 'F')
                cnt[dist[x][y]]++;
    int pref = 0;
    for(int x = maxDist; x >= 0; x--)
    {
        pref += cnt[x];
        costs[x] = x + pref - 1;
    }

    t.resize(4*costs.size());
    lazy.resize(4*costs.size());
    build_tree(1, 0, maxDist);
    return 0;
}