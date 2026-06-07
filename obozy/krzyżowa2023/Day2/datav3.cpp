#include <iostream>
#include <string>

using namespace std;

using ll = long long;
const ll SECONDS_IN_DAY = 86400;

struct DateTime 
{
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int seconds = 0;
};

bool czyPrzestepny(int rok)
{
    return (rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0);
}

int calculateDaysInYear(int rok)
{
    return czyPrzestepny(rok) ? 366 : 365;
}

DateTime readDate(string& date)
{
    DateTime result;
    result.year = stoi(date.substr(0, 4));
    result.month = stoi(date.substr(5, 2));
    result.day = stoi(date.substr(8, 2));
    result.hour = stoi(date.substr(11, 2));
    result.minute = stoi(date.substr(14, 2));
    result.seconds = stoi(date.substr(17, 2));
    return result;
}

int main()
{
    string firstInput, secondInput;
    getline(cin, firstInput);
    getline(cin, secondInput);

    int useLess;
    cin >> useLess;

    DateTime firstDate = readDate(firstInput);
    DateTime secondDate = readDate(secondInput);

    ll allSecondsFirst = firstDate.seconds + firstDate.minute * 60 + firstDate.hour * 3600;
    bool przestepnoscFirst = czyPrzestepny(firstDate.year);

    for (int i = 1900; i < firstDate.year; i++)
    {
        allSecondsFirst += calculateDaysInYear(i) * SECONDS_IN_DAY;
    }

    for (int i = 1; i < firstDate.month; i++)
    {
        if (i == 2)
        {
            allSecondsFirst += (przestepnoscFirst ? 29 : 28) * SECONDS_IN_DAY;
        }
        else
        {
            allSecondsFirst += ((i > 7 && i % 2 == 1) || (i <= 7 && i % 2 == 0)) ? 30 * SECONDS_IN_DAY : 31 * SECONDS_IN_DAY;
        }
    }

    allSecondsFirst += (firstDate.day - 1) * SECONDS_IN_DAY;

    // DRUGA DATA
    ll allSecondsSecond = secondDate.seconds + secondDate.minute * 60 + secondDate.hour * 3600;
    bool przestepnoscSecond = czyPrzestepny(secondDate.year);

    for (int i = 1900; i < secondDate.year; i++)
    {
        allSecondsSecond += calculateDaysInYear(i) * SECONDS_IN_DAY;
    }

    for (int i = 1; i < secondDate.month; i++)
    {
        if (i == 2)
        {
            allSecondsSecond += (przestepnoscSecond ? 29 : 28) * SECONDS_IN_DAY;
        }
        else
        {
            allSecondsSecond += ((i > 7 && i % 2 == 1) || (i <= 7 && i % 2 == 0)) ? 30 * SECONDS_IN_DAY : 31 * SECONDS_IN_DAY;
        }
    }

    allSecondsSecond += (secondDate.day - 1) * SECONDS_IN_DAY;

    ll difference = allSecondsSecond - allSecondsFirst;

    ll days = difference / SECONDS_IN_DAY;
    difference %= SECONDS_IN_DAY;
    ll hours = difference / 3600;
    difference %= 3600;
    ll minutes = difference / 60;
    ll seconds = difference % 60;


    //cout << days <<" "<<  hours<<" " << minutes<<" " << seconds;
    if (days > 0)
    {
        cout << days << " " << ((days == 1) ? "dzien " : "dni ");
    }
    if (hours > 0)
    {
        string stringTemp = to_string(hours);
        int length = stringTemp.size();
        cout << hours << " " << ((hours == 1) ? "godzina " : 
        ((stringTemp[length - 1] - '0') < 5 && stringTemp[length - 2] != '1') ? "godziny " : "godzin ");
    }
    if (minutes > 0)
    {
        string stringTemp = to_string(minutes);
        int length = stringTemp.size();
        cout << minutes << " " << ((minutes == 1) ? "minuta " : 
        ((stringTemp[length - 1] - '0') < 5 && stringTemp[length - 2] != '1') ? "minuty " : "minut ");
    }
    if (seconds > 0)
    {
        string stringTemp = to_string(seconds);
        int length = stringTemp.size();
        cout << seconds << " " << ((seconds == 1) ? "sekunda " : 
        ((stringTemp[length - 1] - '0') < 5 && stringTemp[length - 2] != '1') ? "sekundy " : "sekund ");
    }

    return 0;
}
