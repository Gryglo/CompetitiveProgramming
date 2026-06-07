#include <iostream>
#include <vector>
#include <conio.h>
#include <cmath> 

using namespace std;


enum Ranga
{
    KAPRAL = 1,
    STARSZY_KAPRAL = 2,
    PLUTONOWY = 3
};

struct Uczen
{
    string Imie;
    string Nazwisko;
    int numerDziennik;
    bool czyBylPytany = false;
    int ileRazyByl = 0;

    Uczen()
    {
        cout << "NOWY UCZEŃ ZOSTAŁ STWORZONY!\n";
    }
    Uczen(string imie, string nazwisko, int numer, bool pytany)
    {
        cout << "Konstruktro 1";
        Imie = imie;
        Nazwisko = nazwisko;
        numerDziennik = numer;
        czyBylPytany = pytany;
    }
    Uczen(string imie, string nazwisko)
    {
        cout << "Konstruktro 2";
        Imie = imie;
        Nazwisko = nazwisko;
    }

};

struct Rodzic
{
    string imie;
    string nazwisko;
    int wiek;
    int iloscDzieci;
    vector<string> imionaDzieci;
};

struct Zolniez
{
    int wiek;
    string przydomek;
    Ranga ranga;
    

    Zolniez(int wiek, string przydomek, Ranga ranga)
    {
        this->wiek = wiek;
        this->przydomek = przydomek;
        this->ranga = ranga;
    }
};

int main()
{
    int N = 5;
    vector<string> imiona(N);
    vector<string> wiek(N);
    vector<string> przydomki(N);
    vector<string> nazwiska(N);


    vector<Uczen> uczniowie(5);

    Zolniez nowyZolniez(57, "Zadrożny", PLUTONOWY);

    cout << "Poziom rangi kapral to " << KAPRAL << endl;

    if(nowyZolniez.ranga == KAPRAL)
    {
        cout << "To jest KAPRAL!";
    }
    else if(nowyZolniez.ranga == STARSZY_KAPRAL)
    {
        cout << "To jest STARSZY_KAPRAL";
    }
    else if(nowyZolniez.ranga == PLUTONOWY)
    {
        cout << "To jest PLUTONOWY";
    }
    getch(); //czekanie na wejscie uzytkownika(nie wazne)
    return 0;
}