#include <iostream>
#include <vector>
#include <algorithm>
#define ll unsigned long long

using namespace std;

// Struktura reprezentująca województwo
struct Wojewodztwo
{
    int numer;               // Numer województwa
    ll liczbaMieszkancow;    // Liczba mieszkańców

    // Konstruktor inicjujący dane województwo
    Wojewodztwo(int numer, ll liczbaMieszkancow)
    {
        this->numer = numer;
        this->liczbaMieszkancow = liczbaMieszkancow;
    }
};

// Funkcja porównująca województwa po liczbie mieszkańców (malejąco)
bool sortWojewodztwa(Wojewodztwo a, Wojewodztwo b)
{
    return a.liczbaMieszkancow > b.liczbaMieszkancow;
}

// Funkcja porównująca województwa po numerze (rosnąco)
bool sortWojewodztwaByNumer(Wojewodztwo a, Wojewodztwo b)
{
    return a.numer < b.numer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Wojewodztwo> wojewodztwa;
    wojewodztwa.reserve(N + 1);
    wojewodztwa.emplace_back(0, 0);

    // Wczytaj dane dotyczące liczby mieszkańców województw
    for(int i = 0; i < N; i++)
    {
        ll value;
        cin >> value;
        wojewodztwa.emplace_back(i + 1, value);
    }

    // Posortuj województwa malejąco według liczby mieszkańców
    sort(wojewodztwa.begin(), wojewodztwa.end(), sortWojewodztwa);

    vector<int> answers;
    answers.reserve(N);

    // Pętla po województwach
    for(int x = N; x >= 1; x--)
    {
        ll suma = 0;

        // Sprawdź, czy można dodać dane województwo do rozwiązania
        for (int i = x; i >= 1; i--)
        {
            suma += wojewodztwa[i].liczbaMieszkancow;
            answers.push_back(wojewodztwa[i].numer);
        }

        // Sprawdź, czy można dodać dane województwo do rozwiązania
        if (suma >= wojewodztwa[0].liczbaMieszkancow)
        {
            sort(answers.begin(), answers.end());
            for (const int& value : answers)
            {
                cout << value << " ";
            }
            return 0;
        }

        answers.clear();
    }

    return 0;
}
