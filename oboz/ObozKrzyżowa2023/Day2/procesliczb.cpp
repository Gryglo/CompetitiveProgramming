#include <iostream>
#include <set>
#include <string>

#define ll long long

using namespace std;


int main()
{
    string input;
    cin >> input;

    set<ll> allValues;

    ll value = stoll(input);
    ll minimalValue = value;

    while(allValues.find(value) == allValues.end())
    {
        allValues.insert(value);
        value = 0;
        for(ll i = 0; i < input.length(); i++)//PODZIEL TO NA METODY DZBANIE
        {
            int number = input[i] - '0';
            number *= number;
            value += number;
        }
        if(minimalValue > value)
        {
            minimalValue = value;
        }
        input = to_string(value);
    }

    cout << minimalValue;

    return 0;    
}