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
vector<int> cnt;
vector<int> costs;

//    max  isEvenPresent
vector<int> t;
vector<int> lazy;

int compute_max(int v, int tl, int m, int tr)
{
    int fMax = (tl == m) ? (cnt[tl] > 0 ? t[2 * v] : -INF) : t[2 * v]; //lisc
    int sMax = (m + 1 == tr) ? (cnt[tr] > 0 ? t[2 * v + 1] : -INF) : t[2 * v + 1]; //lisc
    return max(fMax, sMax);
}

void build_tree(int v, int l, int r)
{
    if(l > r)
        return;
    if(l == r)
    {
        t[v] = costs[l];
    }
    else
    {
        int m = (l + r) / 2;
        build_tree(2 * v, l, m); 
        build_tree(2 * v + 1, m + 1, r);
        t[v] = compute_max(v, l, m, r);
    }
}

/* 
jak mamy na jakims wierzcholku lazy = 5 to znaczy ze wszystkie wierzcholki dzieci byly zwiekszone 
5 razy o 1 wiec tak jakby mozemy dodaj co nich ta wartosc
*/
void push(int v, int tl, int tr)
{
    if(lazy[v] == 0)
        return;
    t[v] += lazy[v];

    if(tl != tr)
    {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    push(v, tl, tr);
    if (tl > tr || tl > r || tr < l)
        return;

    if(l <= tl && tr <= r)
    {
        /* 
        tak jakby jak zwiekszamy wszystkie elementy o jeden to nasz max jest dalej tym samym maxem
        tylko wiekszym o jeden
        */
        t[v] += val;
        if(tl != tr)
        {      
            lazy[2 * v] += val;
            lazy[2 * v + 1] += val;
        }
    }
    else
    {
        if(tl == tr)
            t[v] += val;
        else
        {
            int m = (tl + tr) / 2;
            update(2 * v, tl, m, l, r, val);
            update(2 * v + 1, m + 1, tr, l, r, val);
            t[v] = compute_max(v, tl, m, tr);
        }
    }
}

void refresh_node_state(int v, int tl, int tr, int idx)
{
    push(v, tl, tr);
    if(tl == tr && tl == idx)
    {
        return;
    }

    if(idx < tl || tr < idx)
        return;
    int m = (tl + tr) / 2;
    if(idx <= m)
    {
        refresh_node_state(2 * v, tl, m, idx);
        refresh_node_state(2 * v + 1, m + 1, tr, idx);
        t[v] = compute_max(v, tl, m, tr);
    }
    else
    {
        refresh_node_state(2 * v, tl, m, idx);
        refresh_node_state(2 * v + 1, m + 1, tr, idx);
        t[v] = compute_max(v, tl, m, tr);
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    cout << (t[1] >= 0 ? t[1] : 0) << '\n';

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
            if(cnt[currDist] == 0)
                refresh_node_state(1, 0, maxDist, currDist);
            update(1, 0, maxDist, 0, currDist, -1);
        }
        else
        {
            //dodajemy fort
            cnt[currDist]++;
            input[x][y] = 'F';
            if(cnt[currDist] == 1)
                refresh_node_state(1, 0, maxDist, currDist);
            update(1, 0, maxDist, 0, currDist, 1);
        }
        cout << (t[1] >= 0 ? t[1] : 0) << '\n';
    }
    return 0;
}