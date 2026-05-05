#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;


bool isPalindrom(int input)
{
    string stringInput = to_string(input);
    string reversedString = stringInput;
    reverse(reversedString.begin(), reversedString.end()); 
    if(reversedString == stringInput)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main() 
{
    int input;
    cin >> input;

    if(isPalindrom(input))
    {
        cout << "TAK";
        return 0;
    }
    input--;
    if(isPalindrom(input))
    {
        cout << "PRAWIE";
        return 0;
    }
    input += 2;
    if(isPalindrom(input))
    {
        cout << "PRAWIE";
        return 0;
    }
    cout << "NIE";
    return 0;
}
