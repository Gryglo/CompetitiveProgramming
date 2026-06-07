#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long totalA = 0, totalB = 0;

    pair<int, int>* weights = new pair<int, int>[n];
    int* results = new int[n]();

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i].first;
        weights[i].second = i;
    }

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
    }

    sort(weights, weights + n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (totalA > totalB)
        {
            totalB += weights[i].first;
            results[weights[i].second] = 1;
        }
        else
            totalA += weights[i].first;
    }

    for (int i = 0; i < n; i++)
        cout << results[i] << ' ';

    return 0;
}
