#include <iostream>
#include <map>
#include <string>
#define ll long long
using namespace std;

int main()
{
    map<int, ll> map;
    int lenght;
    cin >> lenght;

    for(int i = 0; i < lenght; i++)
    {
        char znak;
        cin >> znak;
        ll input;
        cin >> input;
        
        if(znak == 'D')
        {
            int count = 0;
            if(map.find(input) != map.end())
                count = map[input];
            count++;
            map[input] = count;
        }
        else
        {
            map[input]--;
        }
    }

    for(auto const& x : map)
    {
        cout << x.first << " " << x.second << '\n';
    }

    cout << "Hello World";
    return 0;
}