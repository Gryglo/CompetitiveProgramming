/*
3102. Minimize Manhattan Distances
https://leetcode.com/problems/minimize-manhattan-distances/description/
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void rotate45(vector<int>& a)
{
    int a1 = a[0] + a[1], a2 = a[0] - a[1];
    a[0] = a1;
    a[1] = a2;
}

int minimumDistance(vector<vector<int>>& points) 
{
    int n = points.size();
    multiset<int> x, y;
    for(int i = 0; i < n; i++)
    {
        rotate45(points[i]);
        x.insert(points[i][0]);
        y.insert(points[i][1]);
    }
    int d = 1e9;
    for(int i = 0; i < n; i++)
    {
        x.erase(x.find(points[i][0])); y.erase(y.find(points[i][1]));
        int x_diff = (*x.rbegin()) - (*x.begin());
        int y_diff = (*y.rbegin()) - (*y.begin());
        d = min(d, max(x_diff, y_diff));
        x.insert(points[i][0]);
        y.insert(points[i][1]);
    }
    return d;
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];
    cout << minimumDistance(points);
    return 0;
}

