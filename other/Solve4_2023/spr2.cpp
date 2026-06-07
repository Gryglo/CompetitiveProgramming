#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
cin.tie(0);
cout.tie(0);
    long long n;
    cin >> n;

    long long totalA = 0, totalB = 0;
    vector<pair<int, int>> weights(n);
    vector<int> results(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i].first;
        weights[i].second = i;
    }

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
    }

    sort(weights.begin(), weights.end());

    for (int i = n - 1; i >= 0; i--)
    {
        if (totalA > totalB)
        {
            results[weights[i].second] = 1;
            totalB += weights[i].first;
        }
        else
            totalA += weights[i].first;
    }

    for (int i = 0; i < n; i++)
        cout << results[i] << ' ';
}
