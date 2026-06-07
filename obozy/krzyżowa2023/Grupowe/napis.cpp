#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    string input;
    cin >> input;
    
    sort(input.begin(), input.end());//SORTOWANIE LEKSYKALNE

    char calculatingChar = input[0];
    int countOfChar = 0;
    vector<pair<char, int>> literki;

    for(int i = 0; i < input.size(); i++) //LICZENIE LITEREK
    {
        char currentChar = input[i];
        if(currentChar == calculatingChar)
            countOfChar++;
        else
        {
            literki.push_back( {calculatingChar, countOfChar} );
            countOfChar = 1;
            calculatingChar = currentChar;
        }
    }
    if(countOfChar > 0)
        literki.push_back( {calculatingChar, countOfChar} );

    //LITERKI ZLICZONE

    bool repeating = false;
    string result = "";
    for(int x = 0; x < literki.size(); x++)//DOBIERANIE POKOLEI LITEREK Z TABLICY LICZBY
    {
        pair<char, int> para = literki[x];

        for(int z = 0; z < para.second; z++)
        {
            if(repeating == false)
            {
                result += para.first;
                repeating = true;
            }
            else
            {
                char nextChar;
                bool isNextCharFounded = false;
                for(int y = x + 1; y < literki.size(); y++)
                {
                    pair<char, int> nextPair = literki[y];
                    if(nextPair.second > 0)
                    {
                        nextPair.second--;
                        nextChar = nextPair.first;
                        literki[y] = nextPair;
                        isNextCharFounded = true;
                        break;
                    }
                }
                if(isNextCharFounded)
                {
                    result  = result + nextChar + para.first;
                }
                else
                {
                    cout << "NIE";
                    return 0;
                }
            }
        }
        repeating = false;
    }

    cout << result;

    return 0;
}
