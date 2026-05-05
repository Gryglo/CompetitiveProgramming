#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string input;
    cin >> input;

    int lenght = input.size();

    string result;
    for(int x = 0; x < lenght; x++)
    {
        int characterCode = (int) input[x];
        if(characterCode <= 99)
        {
            cout << "2";
        }
        else if(characterCode <= 102)
        {
            cout << "3";
        }
        else if(characterCode <= 105)
        {
            cout << "4";
        }
        else if(characterCode <= 108)
        {
            cout << "5";
        }
        else if(characterCode <= 111)
        {
            cout << "6";
        }
        else if(characterCode <= 115)
        {
            cout << "7";
        }
        else if(characterCode <= 118)
        {
            cout << "8";
        }
        else if(characterCode <= 122)
        {
            cout << "9";
        }

    }
    return 0;
}
