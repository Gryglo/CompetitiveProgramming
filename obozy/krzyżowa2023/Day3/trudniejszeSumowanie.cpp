#include <iostream>
#include <vector>
#define ll long long

using namespace std;
int main() 
{
    int N, Q;
    cin >> N;

    vector<ll> zapytania(N + 1);
    zapytania[0] = 0;

    for(int i = 1; i <= N; i++)
    {
        ll value;
        cin >> value;
        zapytania[i] = zapytania[i-1] + value;
    }

    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int first, second;
        cin >> first >> second;
        ll sum = zapytania[second] - zapytania[first - 1];
        cout << sum << "\n";
    }

    return 0;
}
