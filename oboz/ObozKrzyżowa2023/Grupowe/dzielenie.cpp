#include <iostream>
#define ll long long
using namespace std;
int main() 
{
    ll input;
    cin >> input;

    if(input > 3)
    {
        if(input % 2 == 0)
        {
            cout << "3";
            return 0;
        }
        else
        {
            cout << "4";
            return 0;
        }
    }
    else if(input == 3)
        cout << "3";
    else if(input == 2)
        cout << "2";
    else if(input == 1)
        cout << "1";

    return 0;
}
