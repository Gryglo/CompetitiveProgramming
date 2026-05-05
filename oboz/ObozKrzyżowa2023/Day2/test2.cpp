#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string jednosci[10] = {"", "jeden ", "dwa ", "trzy ", "cztery ", "piec ", "szesc ", "siedem ", "osiem ", "dziewiec "};
string nastki[11] = {"", "dziesiec ", "jedenascie ", "dwanascie ", "trzynascie ", "czternascie ", "pietnascie ", "szesnascie ", "siedemnascie ",
                    "osiemnascie ", "dziewietnascie "};
string dziesiatki[10] = {"", "dziesiec ", "dwadziescia ", "trzydziesci ", "czterdziesci ", "piecdziesiat ", "szescdziesiat ", "siedemndziesiat ",
                        "osiemdziesiat ", "dziewiecdziesiat "};
string setki[10] = {"", "sto ", "dwiescie ", "trzysta ", "czterysta ", "piecset ", "szescset ", "siedemset ", "osiemset ", "dziewiecset "};

int main() 
{
    int j = 0, liczba, koncowka, k = 1, c = 0;
    string i, slownie = "";

    cin >> liczba;

    do
    {
        koncowka = liczba % 10;
        liczba = liczba / 10;

        if (j == 3 || (j == 2 && c != 1))
        {
            slownie = setki[koncowka] + slownie;
        }

        if (j == 1)
        {
            slownie = dziesiatki[koncowka] + slownie;
        }

        if (j == 0 && (liczba % 10 != 1))
        {
            slownie = jednosci[koncowka] + slownie;
        }

        if (j == 0 && (liczba % 10 == 1))
        {
            slownie = nastki[koncowka + 1] + slownie;
            liczba = liczba * 10;
            c = 1;
        }
        j = j + 1;

    } while (liczba > 0);

    cout << slownie << endl
         << "----------------- \n"
         << endl;

    return 0;
}
