#include <iostream>
#include <iomanip>

using namespace std;
int main() 
{
    double monety[15] =
    { 0.01, 0.02,
    0.05, 0.1, 0.2, 0.5, 1, 2, 5, 10, 20, 50, 100, 200, 500};
    
    string input;
    cin >> input;
    
    double result = 0.00;
    for(int i = 0; i < 15; i++)
    {
        double multiplier = input[i] - '0';
        result += multiplier * monety[i];
    }

    cout << fixed << setprecision(2) << result << endl;
    return 0;
}