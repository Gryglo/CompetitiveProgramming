#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    for (int x = 0; x < n; ++x) 
    {
        for (int z = x + 1; z < n; ++z) 
        {
            bool sasiedzi = true;
            int dist_xz = dist[x][z];
            for (int y = 0; y < n; ++y) 
            {
                if (y == x || y == z) continue;
                if (dist[x][y] + dist[y][z] == dist_xz) 
                {
                    sasiedzi = false;
                    break;
                }
            }
            if (sasiedzi)
                cout << x + 1 << " " << z + 1 << '\n';
        }
    }

    return 0;
}