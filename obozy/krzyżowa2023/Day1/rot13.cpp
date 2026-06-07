#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int lenght = input.size();

    string result;
    for(int i = 0; i < lenght; i++)
    {
        char character = input[i];
        int characterCode = (int) character;
    
        if(characterCode >= 65) //LITERA
        {
            if(characterCode <= 90) //DUZA litera
            {
                if(characterCode < 78)
                {
                    characterCode = characterCode + 13;
                }
                else
                {
                    characterCode = characterCode - 13;
                }
            }
            else if(characterCode >= 97 && characterCode <= 122) //Mała litera
            {
                if(characterCode < 110)
                {
                    characterCode = characterCode + 13;
                }
                else
                {
                    characterCode = characterCode - 13;
                }
            }

            character = (char) characterCode;
        }
        cout << character;

    }
    return 0;
}
