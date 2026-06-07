#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    vector<pair<long long int, long long int>> points(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());

    for (const auto& point : points) 
    {
        std::cout << point.first << " " << point.second << "\n";
    }

    return 0;
}
