#include <iostream>
#define ll long long
using namespace std;

string convertToRomanNumber(ll number) 
{
    string result = "";

    ll values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string letterValues[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for(ll i = 0; i < 13; i++)
    {
        while(number - values[i] >= 0)
        {
            number -= values[i];
            result += letterValues[i];
        }
    }

    return result;
}



int main()
{
    ll input;
    cin >> input;
    cout << convertToRomanNumber(input);
    return 0;    
}