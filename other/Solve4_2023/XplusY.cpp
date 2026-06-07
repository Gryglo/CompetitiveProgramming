#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

int phi(int n) 
{
    int result = n;
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    int a, b;
    cin >> a >> b;

    double tempA = a;
    double tempB = b;

    int multiplier = phi(200);

    tempA *= M_SQRT2 / M_LOG2E;
    tempB *= M_LN10 * (M_LOG10E / 5) * 3;
    cout << (tempA / (M_SQRT2 / M_LOG2E)) + (tempB / (M_LN10 * (M_LOG10E / 5) * 3)) / (multiplier / 80.000000F);
    return 0;
}