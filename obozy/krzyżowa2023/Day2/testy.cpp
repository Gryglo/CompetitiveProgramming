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

    ll allSeconds = 0;

    // Dodaj sekundy z pierwszej daty
    allSeconds += firstDate.seconds + firstDate.minute * 60 + firstDate.hour * 3600;

    for (int i = 1900; i < firstDate.year; i++)
    {
        allSeconds += calculateDaysInYear(i) * SECONDS_IN_DAY;
    }

    for (int i = 1; i < firstDate.month; i++)
    {
        if (i == 2)
        {
            allSeconds += (czyPrzestepny(firstDate.year) ? 29 : 28) * SECONDS_IN_DAY;
        }
        else
        {
            allSeconds += ((i > 7 && i % 2 == 1) || (i <= 7 && i % 2 == 0)) ? 30 * SECONDS_IN_DAY : 31 * SECONDS_IN_DAY;
        }
    }

    allSeconds += (firstDate.day - 1) * SECONDS_IN_DAY;

    // Dodaj różnicę między pierwszą a drugą datą w obrębie tego samego dnia
    allSeconds += secondDate.seconds + secondDate.minute * 60 + secondDate.hour * 3600;

    for (int i = firstDate.year; i < secondDate.year; i++)
    {
        allSeconds += calculateDaysInYear(i) * SECONDS_IN_DAY;
    }

    for (int i = 1; i < secondDate.month; i++)
    {
        if (i == 2)
        {
            allSeconds += (czyPrzestepny(secondDate.year) ? 29 : 28) * SECONDS_IN_DAY;
        }
        else
        {
            allSeconds += ((i > 7 && i % 2 == 1) || (i <= 7 && i % 2 == 0)) ? 30 * SECONDS_IN_DAY : 31 * SECONDS_IN_DAY;
        }
    }

    allSeconds += (secondDate.day - 1) * SECONDS_IN_DAY;

    ll days = allSeconds / SECONDS_IN_DAY;
    allSeconds %= SECONDS_IN_DAY;
    ll hours = allSeconds / 3600;
    allSeconds %= 3600;
    ll minutes = allSeconds / 60;
    ll seconds = allSeconds % 60;

    cout << days <<" "<<  hours<<" " << minutes<<" " << seconds;

    return 0;
}
