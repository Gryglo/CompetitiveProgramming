#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<vector<bool>> mapa;

pii currpos = {0, 0};

bool checkOutside(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return true;
    return false;
}

int isTail(int x, int y)
{
    if(checkOutside(x, y)) return 0;
    return mapa[x][y];
}

int oi = 0;
vector<pii> orient = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int cntW = 0;
void rotate()
{
    oi = (oi + 1) % orient.size();
    cntW++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(n == 0 || m == 0)
        return 0;
    mapa.resize(n, vector<bool>(m));
    mapa[0][0] = 1;
    while(cntW < 2)
    {
        pii next = {currpos.f + orient[oi].f, currpos.s + orient[oi].s};
        if(checkOutside(next.f, next.s))
        {
            rotate();
            continue;
        }
        else
        {
            if(isTail(next.f, next.s) == 1)
            {
                rotate();
                continue;
            }
            else
            {
                int cntTail = 0;
                cntTail += isTail(next.f - 1, next.s);
                cntTail += isTail(next.f + 1, next.s);
                cntTail += isTail(next.f, next.s + 1);
                cntTail += isTail(next.f, next.s - 1);
                if(cntTail >= 2)
                {
                    rotate();
                    continue;
                }
            }
        }
        //nextSafe
        currpos = next;
        mapa[currpos.f][currpos.s] = 1;
        cntW = 0;
    }
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < m; y++)
        {
            if(mapa[x][y])
                cout << '#';
            else    
                cout << '.';
        }
        cout << '\n';
    }
    return 0;
}