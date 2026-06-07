#include <iostream>
using namespace std;

int main()
{
    double input;
    cin >> input;

    double total_seconds = 3600.0 / input;

    int minutes = total_seconds / 60;
    int seconds = (int) total_seconds % 60;

    if(minutes < 10)
        cout << '0';
    cout << minutes << ':';
    if(seconds < 10)
        cout << '0';
    cout << seconds;
    
    return 0;
}