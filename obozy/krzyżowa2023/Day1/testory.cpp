#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() 
{
    string wejscie;
    cin >> wejscie;

    unordered_map<char, int> liczbaZnakow;

    for (char znak : wejscie) 
    {
        liczbaZnakow[znak]++;
    }

    string palindrom;
    string posortowanaPolowa;

    char nieparzystyZnak = '\0';

    for (const auto &element : liczbaZnakow) {
        char znak = element.first;
        int liczba = element.second;

        palindrom += string(liczba / 2, znak);

        if (liczba % 2 == 1) {
            if (nieparzystyZnak == '\0' || znak < nieparzystyZnak) {
                nieparzystyZnak = znak;
            }
        }
    }

    posortowanaPolowa = palindrom;
    sort(posortowanaPolowa.begin(), posortowanaPolowa.end());

    string wynik = posortowanaPolowa + (nieparzystyZnak != '\0' ? string(1, nieparzystyZnak) : "") + string(posortowanaPolowa.rbegin(), posortowanaPolowa.rend());

    cout << wynik;

    return 0;
}
