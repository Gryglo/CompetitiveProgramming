#include <iostream>

using namespace std;
int main()
{
    char type;
    cin >> type;

    double temperature;
    cin >> temperature;

    double result;

    if(type == 'C')
    {
        cout << "F\n";
        result = (temperature * 1.8) + 32;
    }
    else
    {
        cout << "C\n";
        result = (temperature - 32) / 1.8;
    }

    printf("%.9f", result);

    return 0;
}