#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long int previousElement;
    cin >> previousElement;
    long int result = previousElement;

    for (int i = 1; i < n; i++)
    {
        int value;
        cin >> value;

        long int currentElement = max((long int)value, value + previousElement);
        result = max(result, currentElement);
        previousElement = currentElement;
    }

    if (result < 0)
        cout << '0';
    else
        cout << result;

    return 0;
}