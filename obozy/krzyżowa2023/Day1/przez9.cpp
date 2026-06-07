#include <iostream>

using namespace std;

int main()
{
    unsigned long long suma = 0;
    char character;
    while(cin >> character)
    {
        suma += character - '0';
    }
    if(suma % 9 == 0)
    {
        cout << "TAK";
    }
    else
    {
        cout << "NIE";
    }

    return 0;
}
