#include <iostream>

using namespace std;

int main() 
{
    string input;
    cin >> input;

    int result = 0; 
    int countA = 0;
    int countB = 0;

    for(char x : input)
    {
        if(x == 'A') 
        {
            countA++;
        }
        else if(x == 'B' && countA > 0) 
        {
            countB++;
            countA--;
        }
        else if(x == 'C' && countB > 0) 
        {
            result++;
            countB--; 
        }
    }

    cout << result;
    return 0;
}
