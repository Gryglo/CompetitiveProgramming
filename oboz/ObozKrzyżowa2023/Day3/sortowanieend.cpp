#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

bool sortByEnd(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
    if(a.second < b.second)
    {
        return true;
    }
    else if(a.second == b.second)
    {
        if(a.first < b.first)
        {
            return true;
        }
        return false;
    }
    return false;
}

int main() 
{
    int N;
    cin >> N;

    vector<pair<long long int, long long int>> points(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end(), sortByEnd);

    for (const auto& point : points) 
    {
        std::cout << point.first << " " << point.second << "\n";
    }

    return 0;
}
