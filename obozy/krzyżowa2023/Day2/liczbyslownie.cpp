#include <iostream>
#include <string>

#define ll long long

using namespace std;

string jednosci[10] = {"", "jeden ", "dwa ", "trzy ", "cztery ", "piec ", "szesc ", "siedem ", "osiem ", "dziewiec "};
string nastki[11] = {"", "dziesiec ", "jedenascie ", "dwanascie ", "trzynascie ", "czternascie ", "pietnascie ", "szesnascie ", "siedemnascie ",
                    "osiemnascie ", "dziewietnascie "};
string dziesiatki[10] = {"", "dziesiec ", "dwadziescia ", "trzydziesci ", "czterdziesci ", "piecdziesiat ", "szescdziesiat ", "siedemdziesiat ",
                        "osiemdziesiat ", "dziewiecdziesiat "};
string setki[10] = {"", "sto ", "dwiescie ", "trzysta ", "czterysta ", "piecset ", "szescset ", "siedemset ", "osiemset ", "dziewiecset "};
string tysiace[3] = {"tysiac ", "tysiace ", "tysiecy "};
string miliony[3] = {"milion ", "miliony ", "milionow "};


string convertToString(ll input)
{
    string inputAsString = to_string(input);
    if(input < 10)
    {
        return (jednosci[input]);
    }
    else if(input < 20)
    {
        return (nastki[inputAsString[1] - '0' + 1]);
    }
    else if(input < 100)
    {
        return (dziesiatki[inputAsString[0] - '0'] + convertToString(inputAsString[1] - '0'));
    }
    else if(input < 1000)
    {
        return (setki[inputAsString[0] - '0'] + convertToString
        (
            stoll(inputAsString.substr(inputAsString.length() - 2, 2))
        ));
    }
    else if(input < 1'000'000)
    {
        string result = "";
        if(input >= 2000)
        {
            string tempString = inputAsString.substr(0, inputAsString.length() - 3);
            int temp = stoll(tempString);
            int lastNum = tempString[tempString.length() - 1] - '0';
            string tempResult = convertToString(temp);
            if(lastNum >= 2 && lastNum < 5) 
                result = tempResult + tysiace[1];
            else
                result = tempResult + tysiace[2];
            if(tempString.length() > 1)
            {
                if((tempString[tempString.length() - 2] - '0') == 1)
                {
                    result = tempResult + tysiace[2];
                }
            }

        }
        else
        {
            result = tysiace[0];
        }
        return (result + convertToString(stoll(inputAsString.substr(inputAsString.length() - 3, 3))));
    } 
    else
    {
       string result = "";
        if(input >= 2000000)
        {
            string tempString = inputAsString.substr(0, inputAsString.length() - 6);
            int temp = stoll(tempString);
            int lastNum = tempString[tempString.length() - 1] - '0';
            string tempResult = convertToString(temp);
            if(lastNum >= 2 && lastNum < 5) 
                result = tempResult + miliony[1];
            else
            {
                result = tempResult + miliony[2];
            }
            if(tempString.length() > 1)
            {
                if((tempString[tempString.length() - 2] - '0') == 1)
                {
                    result = tempResult + miliony[2];
                }
            }

        }
        else
        {
            result = miliony[0];
        }
        return (result + convertToString(stoll(inputAsString.substr(inputAsString.length() - 6, 6))));
    } 
}


int main() 
{
    ll input;
    cin >> input;

    if(input == 0)
    {
        cout << "zero";
        return 0;
    }

    cout << convertToString(input);
    return 0;
}