#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAXN = 1000000;

//         liczba count 
vector<pair<char, int>> stackedNumber;
int result = 0;

void roundOnes()
{
    pair<char, int> lastPacket = stackedNumber.back();
    if(lastPacket.first == '9' || lastPacket.first == '0')
        return;
    
    result += 9 - (lastPacket.first - '0');
    lastPacket.second--;
    if(lastPacket.second <= 0)
        stackedNumber.pop_back();
    else
        stackedNumber.back().second--;

    if(stackedNumber.back().first == '9')
        stackedNumber.back().second++;
    else
        stackedNumber.push_back( { '9', 1 } );
    /*
    cout << "Rounding " << lastPacket.first << ". Result: " << result << '\n';
    for(pair<char, int> para : stackedNumber)
    {
        cout << para.first << " " << para.second << ", ";
    }
    cout << '\n';
    */
    
}

void jumpNumber()
{
    pair<char, int> firstPacket = stackedNumber.front();
    
    firstPacket.second--;
    if(firstPacket.second <= 0)
        stackedNumber.erase(stackedNumber.begin());
    else
        stackedNumber.front().second--;
    
    if(stackedNumber.back().first == firstPacket.first)
        stackedNumber.back().second++;
    else
        stackedNumber.push_back( { firstPacket.first, 1 } );
    result++;
    /*
    cout << "Jump. Result: " << result << '\n';
    for(pair<char, int> para : stackedNumber)
    {
        cout << para.first << " " << para.second << ", ";
    }
    cout << '\n';
    */
}

void removeLeadingZeros()
{
    if(stackedNumber[0].first == '0')
        stackedNumber.erase(stackedNumber.begin());
}

void checkIfAddingIsBetter()
{
    int lookForCount = 6;

    int maxDiff = 0;
    int diff = 0;
    int currNum = 0;
    int multiplier = 1;
    int additionalOperations = 1;
    int addedNum = 0;
    for(int i = 1; addedNum < 7; i++)
    {
        if((int) stackedNumber.size() - i < 0)
            break;
        pair<char, int> currPacket = stackedNumber[stackedNumber.size() - i];
        if(i >= 2 && currPacket.first == '9' && currPacket.second + additionalOperations > diff)
        {
            cout << "OPLACA SIĘ! I: " << i << '\n';
            int originalArraySize = stackedNumber.size();
            for(int x = 1; x < i; x++)
            {
                pair<char, int> prevPacket = stackedNumber[originalArraySize - x];
                currPacket.second += prevPacket.second;
                stackedNumber.pop_back();
            }
            stackedNumber[originalArraySize - i] = currPacket;
            cout << "=-------------\n";
            for(pair<char, int> para : stackedNumber)
                cout << para.first << " " << para.second << '\n';
            cout << "=-------------\n";
            result += diff; 
            return;
        }
        if(i == 6)
            return;
        for(int x = 0; x < currPacket.second && addedNum < lookForCount; x++)
        {
            additionalOperations += 9 - (currPacket.first - '0');
            currNum += (currPacket.first - '0') * multiplier;
            multiplier *= 10;
            maxDiff *= 10;
            maxDiff += 9;
            diff = maxDiff - currNum;
            addedNum++;
        }
    }
}

bool targetPacket()
{
    if(stackedNumber.size() == 1 && stackedNumber[0].first == '9')
        return true;
    return false;
}

int countDigit(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) 
    {
        n = n / 10;
        count++;
    }
    return count;
}

int main() 
{
    string input;
    cin >> input;

    if(input == "1")
    {
        cout << "0";
        return 0;
    }
    else if(input == "0")
    {
        cout << "1";
        return 0;
    }
    auto start = high_resolution_clock::now();

    stackedNumber.push_back({ input[0], 1 });
    int lastIndex = 0;
    for(int i = 1; i < input.size(); i++)
    {
        if(input[i - 1] == input[i])
            stackedNumber[lastIndex] = { input[i], stackedNumber[lastIndex].second + 1 };
        else
        {
            lastIndex++;
            stackedNumber.push_back({ input[i], 1 });
        }
    }

    if(stackedNumber.size() == 1 && stackedNumber[0].first == '9')
    {
        cout << "2";
        return 0;
    }
    else if(stackedNumber.size() == 2 && stackedNumber[0].first == '1' && stackedNumber[1].first == '0')
    {
        cout << "1";
        return 0;
    }

    checkIfAddingIsBetter(); 
    
    while(!targetPacket())
    { 
        roundOnes();
        if(targetPacket())
            break;
        jumpNumber();
        removeLeadingZeros();
    }

    cout << result + 2;

    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "\nTime taken by function: " << duration.count() << " ms" << '\n';
    return 0;
}

/*
    cout << "=-------------\n";
    for(pair<char, int> para : stackedNumber)
    {
        cout << para.first << " " << para.second << '\n';
    }
    cout << "=-------------\n";
    */

    /*

    999999999999999999987
    999999999999999999989
    tu lepiej dodac 13 niz zwiekszac do 9 i przenosic

    999999989
    w tym przypadku bardziej sie oplaca robic 8 skokow i dodac

    jak na jednosci mamy juz liczbe inna niz 9 i 0, to ZAWSZE dopełniamy do 9
    jednak gdy mamy 

    GORSZE:
    111189
    10 - 111199
    999999 + 8 * 4 + 4
    46

    LEPSZE:
    111189
    111891 + 8 = 111899
    891111 + 8 * 4 + 4 = 899999
    36
    999999 + 2
    38

    ale co jak
    8888888888889
    24 ruchy
    8888888888889 a tu bedziemy miec 10 odrazu po dodawaniu 8888888888899

    czy to oznacza ze dodawanie sie oplaca tylko gdy sa 9 z przodu?
    rozważmy
    -99999999989
    skokami 11 krokow
    dodajac 10 krokow
    -98999999989
    skokami 12 krokow
    dodajac po 10 jest 98999999999
    potem musimy skoczyc wiec robimy dwa skoki 99999999998 i juz mamy 12
    teraz +1 i jest 13
    - 1234567898765432189
    dodawanie juz mamy 25 gdy 76543219999999999999999
    skokami
                              76543218999999999999999 jest 15 ruchow


    988899999999989
    10 - 988899999999999
    17 - 999999999999999


    te dodawanie zamiast przesuwania stosujemy tylko 
    KIEDY PRZED LICZBĄ JEST OKRESLONA LICZBA 9

    czyli wyjatkowe jest tylko 0 i 9
    zera to w ogóle bym pomijał

    dodajemy wszystkie liczby oraz 9 dopóki nie znajdziemy pakietu 9 który przewyzsza roznicę 

    zapiszmy dla kazdego pakietu ile 9 jest po prawej stronie
    i wtedy dodajemy do pakietu dopóki nie napotkamy takiej liczby dla której liczba 9 po prawej stronie jest wieksza od danej roznicy
    jezeli napotkamy taka sciane 9 która jest wieksza od roznicy, to dodajemy

    by edytować liczbe 9 po prawej stronie dla pakietow, gdy zwiekszamy liczbe jednosci do 9, zwiekszamy ogolny "offset" 
    czyli dla pakietu dodatkowo sie zapisuje liczbe 9 po prawej stronie i offset zwiekszamy tylko gdy na jednosci pojawi sie nowe 9 lub rozpoczniemy etap masowego dodawanie (w przypadku gdy skoki sie nie oplacaja)  
    699999999999999999999999999...999999999999888

    9999999999999999999999997988

    nie decyduj sie na dodawanie dziesiatek, setek itd. dopóki nie sprawdzisz ze rzeczywiscie się to nie opłaca
    

    999999...99999 8999988

    999998
    999998

    */
