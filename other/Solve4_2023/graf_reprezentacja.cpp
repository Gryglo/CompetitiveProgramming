#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main()
{
    ll points, connections;
    cin >> points >> connections;

    vector<vector<bool>> graf(points + 1, vector<bool>(points + 1, false));

    for(int i = 0; i < connections; i++)
    {
        ll a, b;
        cin >> a >> b;

        graf[a][b] = true;
        graf[b][a] = true;
    }

    for(int i = 1; i <= points; i++)
    {
        vector<bool> values = graf[i];
        for(int i = 1; i <= points; i++)
        {
            cout << values[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
