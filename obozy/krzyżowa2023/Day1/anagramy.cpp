#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool czyAnagram(const string& string1, const string& string2)
{
    if (string1.length() != string2.length())
        return false;

    vector<int> numberOfLetters(26, 0);

    for(char letter : string1)
    {
        ++numberOfLetters[letter - 'a'];
    }

    for(char letter : string2)
    {
        if(--numberOfLetters[letter - 'a'] < 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;
  
    int it;
    cin >> it;

    for(int i = 0; i < it; i++)
    {
        string value;
        cin >> value;

        if(czyAnagram(input, value))
        {
            cout << "TAK" << "\n";
        }
        else
        {
            cout << "NIE" << '\n';
        }
    }

    return 0;
}
