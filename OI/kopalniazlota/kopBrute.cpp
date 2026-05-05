#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second
const int OFFSET = 0;
const int MAX_XY = 100;
int s, w, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> w >> n;
    vector<vector<char>> board(MAX_XY + 5, vector<char>(MAX_XY + 5));
    int maxx = 0, maxy = 0;
    int minx = MAX_XY, miny = MAX_XY;
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        x += OFFSET; y += OFFSET;
        maxx = max(maxx, x);
        maxy = max(maxy, y);
        minx = min(minx, x);
        miny = min(miny, y);
        board[x][y]++;
    }

    int ans = 0;
    for(int x = minx; x <= maxx; x++)
    {
        for(int y = miny; y <= maxy; y++)
        {
            int sum = 0;
            for(int xx = x; xx <= min(maxx, x + s); xx++)
                for(int yy = y; yy <= min(maxy, y + w); yy++)
                    sum += board[xx][yy];
            ans = max(ans, sum);
        }
    }
    cout << ans;
    return 0;
}