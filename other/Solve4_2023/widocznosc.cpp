#include <iostream>
#include <unordered_map>
#include <queue>

#define ll long long
using namespace std;

int main()
{
    int N; 
    cin >> N;

    unordered_map<int, int> rowCounter, colCounter;

    for (int i = 0; i < N; ++i) 
    {
        int x, y;
        cin >> x >> y;
        rowCounter[x]++;
        colCounter[y]++;
    }

    ll result = 0;

    for (const auto& row : rowCounter) 
    {
        int count = row.second;
        if (count > 1) 
            result += (ll) count * ((ll)count - 1) / (ll)2;
    }

    for (const auto& col : colCounter) 
    {
        int count = col.second;
        if (count > 1) 
            result += (ll) count * ((ll)count - 1) / (ll)2;
    }

    cout << result;
    return 0;
}
