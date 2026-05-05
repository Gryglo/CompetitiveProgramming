#include <iostream>
#include <set>

#define ll long long
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<ll> restNumbers;

    for(ll i = 0; i <= 1'000'000; i++)
    {
        restNumbers.insert(i);
    }

    multiset<ll> addedNumbers;
    ll N; 
    cin >> N;

    for(ll i = 0; i < N; i++)
    {
        char action;
        ll number;
        cin >> action;

        if(action == '+')
        {
            cin >> number;
            addedNumbers.insert(number);
            restNumbers.erase(number);
        }
        else if(action == '-')
        {
            cin >> number;
            addedNumbers.erase(addedNumbers.find(number));
            if(addedNumbers.find(number) == addedNumbers.end())
            {
                restNumbers.insert(number);
            }
        }
        else if(action == '?')
        {
            cout << *restNumbers.begin() << '\n';
        }
    }


    return 0;
}
