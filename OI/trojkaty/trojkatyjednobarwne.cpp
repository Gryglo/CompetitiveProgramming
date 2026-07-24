#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> edgeCount;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    edgeCount.resize(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edgeCount[a]++;
        edgeCount[b]++;
    }

    int allTriangles = (n * (n - 1) * (n - 2)) / 6;
    int removedTriangles = 0;
    for(int i = 0; i < n; i++)
        removedTriangles += edgeCount[i] * (n - 1 - edgeCount[i]);
    
    removedTriangles /= 2;
    
    cout << allTriangles - removedTriangles;
    return 0;
}