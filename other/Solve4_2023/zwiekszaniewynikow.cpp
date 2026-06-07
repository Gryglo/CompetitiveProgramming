#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Point
{
    int x, y;
};

bool canCoverKPoints(const vector<Point>& points, int N, int K, int side) 
{
    map<int, vector<int>> rows;
    for (const auto& p : points)
        rows[p.y].push_back(p.x);

    vector<int> y_vals;
    for (const auto& row : rows)
        y_vals.push_back(row.first);

    for (int i = 0; i < y_vals.size(); ++i) 
    {
        vector<int> active_points;
        for (int j = i; j < y_vals.size() && y_vals[j] - y_vals[i] <= side; ++j) 
        {
            for (int x : rows[y_vals[j]])
                active_points.push_back(x);
        }

        sort(active_points.begin(), active_points.end());

        for (int l = 0; l + K - 1 < active_points.size(); ++l) 
        {
            if (active_points[l + K - 1] - active_points[l] <= side) 
                return true;
        }
    }

    return false;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i)
        cin >> points[i].x >> points[i].y;

    int left = 0, right = 1e9, result = right;

    while (left <= right) 
    {
        int mid = (left + right) / 2;

        if (canCoverKPoints(points, N, K, mid)) 
        {
            result = mid;
            right = mid - 1;
        } 
        else 
            left = mid + 1;
    }

    cout << result << '\n';

    return 0;
}
