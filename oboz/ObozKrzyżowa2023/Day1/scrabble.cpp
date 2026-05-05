#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int lenght = input.size();

    map<char, int> licznik;
    map<char, int> parzyste;
    map<char, int> nieParzyste;


    for(int i = 0; i < lenght; i++)
    {
        char znak = input[i];
        licznik[znak]++;

        int value = licznik[znak];
    }

    for (auto const& it : licznik)
    {
        if(it.second % 2  == 0)
            parzyste[it.first] = it.second;
        else
            nieParzyste[it.first] = it.second;
    }


    
    string result = "";

    for(auto const& it : parzyste)
    {
        int value = it.second;
        char character = it.first;
        value /= 2;

        for(int i = 0; i < value; i++)
        {
            result = character + result + character;
        }
    }

    bool isMiddleAdded = false;
    for(auto const& it : nieParzyste)
    {
        int value = it.second;
        char character = it.first;
        if(!isMiddleAdded)
        {
            result = result.substr(0, result.length()/2) + character + result.substr(result.length()/2);
            isMiddleAdded = true;
        }

        if(value > 2)
        {
            value --;
            value /= 2;
            for(int i = 0; i < value; i++)
            {
                result = character + result + character;
            }
        }
    }


    string part1 = result.substr(0, result.length()/2);
    string part2 = result.substr(result.length()/2);

    if(result.size() % 2 != 0)
    {
        char temp = part2[0];
        part2.erase(part2.begin());
        sort(part1.begin(), part1.end());

        string temp2 = part1;
        reverse(temp2.begin(), temp2.end());
        cout << part1 << temp << temp2;
    }
    else
    {
        sort(part1.begin(), part1.end());
        string temp2 = part1;
        reverse(temp2.begin(), temp2.end());
        cout << part1 << temp2;
    }
    return 0;
}
