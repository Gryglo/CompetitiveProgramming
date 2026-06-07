#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll getImpossibleValue(vector<ll> coins)
{
    sort(coins.begin(), coins.end());

    ll impossibleValue = 1;

    for(ll value : coins)
    {
        if(value <= impossibleValue)
            impossibleValue += value;
        else
            break;
    }

    return impossibleValue;
}

int main() 
{
    int N;
    cin >> N;
    vector<ll> coins(N);
    for(int i = 0; i < N; i++)
    {
        ll value;
        cin >> value;
        coins[i] = value;
    }

    cout << getImpossibleValue(coins);

    return 0;
}
