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

    bool end = false;
    vector<Wojewodztwo> wojewodztwa;
    wojewodztwa.reserve(N + 1);
    int size = N + 1;
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
    answers.push_back(wojewodztwa[0].numer);

    ll previousSum = wojewodztwa[N].liczbaMieszkancow;

    // Pętla po województwach
    for(int x = N - 1; x >= 1; x--)
    {
        if(end)//Oszczędź czas i nie iteruj dalej
            break;
        
        previousSum += wojewodztwa[x].liczbaMieszkancow;
        ll suma = previousSum;
        int index = x - 1;

        // Sprawdź, czy można dodać dane województwo do rozwiązania
        while(index >= 0)
        {
            if(suma >= wojewodztwa[index].liczbaMieszkancow) //JEŻELI SUMA POPRZEDNICH JEST WIĘKSZA OD NASTĘPNEGO
            {
                if(suma < 100000000000000)
                {
                    suma += wojewodztwa[index].liczbaMieszkancow;//NOWA SUMA
                    if(index == 0)//JEŻELI TO JUŻ DOSZŁO DO KOŃCA OZNACZA TO SUKCES
                    {
                        answers.push_back(wojewodztwa[x].numer);
                        for(int i = x - 1; i >= 1; i--) //DODAJEMY RÓWNIEŻ WSZYSTKIE WYZSZE WARTOSCI
                        {
                            answers.push_back(wojewodztwa[i].numer);
                            end = true;
                        }
                        break;
                    }
                }
                else
                {
                    answers.push_back(wojewodztwa[x].numer);
                    for(int i = x - 1; i >= 1; i--) //DODAJEMY RÓWNIEŻ WSZYSTKIE WYZSZE WARTOSCI
                    {
                        answers.push_back(wojewodztwa[i].numer);
                        end = true;
                    }
                    break;
                }
            }
            else
            {
                break;
            }
            index--;
        }
    }

    // Posortuj wyniki rosnąco według numeru województwa
    sort(answers.begin(), answers.end());

    // Wypisz wyniki
    for(const int& value : answers)
    {
        cout << value << " ";
    }

    return 0;
}
