//ITERACYJNIE
#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

const int INF = 2e9;

int n, q;
vector<string> input;
vector<vector<int>> dist;
int dx[4] = {1, -1, 0, 0}; //wiersz
int dy[4] = {0, 0, 1, -1}; //kolumna
int maxDist = 0;
vector<int> cnt;
vector<int> costs;

//    val cnt
vector<pii> t;

void compute_max(int v)
{
    // te po prawej sa wieksze wiec sa wysylane przed tym po lewej
    int cntR = t[v << 1 | 1].s;
    int cntSum = cntR + t[v << 1].s;

    int valL = t[v << 1].f;
    int valR = t[v << 1 | 1].f;
    int val = max(valR, valL + cntR);
    if(valR == -INF && valL == -INF)
        val = -INF;
    t[v] = {val, cntSum};
} 

void build_tree(int v, int l, int r)
{
    if(l == r)
    {
        if(cnt[l] > 0)
            t[v] = {l + cnt[l] - 1, cnt[l]};
        else
            t[v] = {-INF, 0};
    }
    else
    {
        int m = (l + r) >> 1;
        build_tree(v << 1, l, m);
        build_tree(v << 1 | 1, m + 1, r);
        compute_max(v);
    }
}

void update(int v, int l, int r, int idx)
{
    if(l == r)
    {
        if(cnt[l] > 0)
            t[v] = {l + cnt[l] - 1, cnt[l]};
        else
            t[v] = {-INF, 0};
    }
    else
    {
        int m = (l + r) >> 1;
        if(idx <= m)
            update(v << 1, l, m, idx);
        else
            update(v << 1 | 1, m + 1, r, idx);
        compute_max(v);
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
                q.push({nX, nY});
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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

    t.resize(4 * (maxDist + 1));
    build_tree(1, 0, maxDist);
    cout << (t[1].s > 0 ? t[1].f : 0) << '\n';

    while(q--)
    {
        int x, y;
        cin >> x >> y; x--; y--;

        int currDist = dist[x][y];
        if(input[x][y] == 'F')
        {
            //usuwamy fort
            cnt[currDist]--;
            input[x][y] = '.';
            update(1, 0, maxDist, currDist);
        }
        else
        {
            //dodajemy fort
            cnt[currDist]++;
            input[x][y] = 'F';
            update(1, 0, maxDist, currDist);
        }
        cout << (t[1].s > 0 ? t[1].f : 0) << '\n';
    }
    return 0;
}