#include <iostream>

using namespace std;
bool czy_pytal[33];
int main()
{
    string klasa[33];
    klasa[0] = '.';
    klasa[1] = "Ambrozik Juliusz";
    klasa[2] = "Baginskyi Yelysei";
    klasa[3] = "Czeczenko Tymoteusz";
    klasa[4] = "Czwordon Bartłomiej";
    klasa[5] = "Diesner Mateusz";
    klasa[6] = "Gordziewicz Bartosz";
    klasa[7] = "Graca Michał";
    klasa[8] = "Grygiel Mateusz";
    klasa[9] = "Gulewicz Jakub";
    klasa[10] = "Hachoł Jan";
    klasa[11] = "Konieczna Hanna";
    klasa[12] = "Kozłowska Emilia";
    klasa[13] = "Lapko Daniil";
    klasa[14] = "Maj Julia";
    klasa[15] = "Martyniszyn Antoni";
    klasa[16] = "Michalec Weronika";
    klasa[17] = "Osiński Marcin";
    klasa[18] = "Piechna Adam";
    klasa[19] = "Pytel Maja";
    klasa[20] = "Ronczewski Leon";
    klasa[21] = "Shvydkyi Nikita";
    klasa[22] = "Soja Milena";
    klasa[23] = "Spychała Tomasz";
    klasa[24] = "Stadnik Bartosz";
    klasa[25] = "Szyndlarewicz Cezary";
    klasa[26] = "Śmieińska Natalia";
    klasa[27] = "Wszędybył Jeremi";
    klasa[28] = "Zagrajek Michał";
    klasa[29] = "Zarzycki Szymon";
    klasa[30] = "Mosakowski Antek";
    klasa[31] = "Dawidowicz Cezary";
    klasa[32] = "Witka Igor";
   for (int i = 1; i <= 32; i++)
   {
    cout << '[' << i << ']' << ' ' << klasa[i] << endl;
   }
    int ile_osob;
    cout << endl << "Ile osób pytał?" << endl;
    cin >> ile_osob;
    
    int max_pytania = 32;
    double procent;
   
    cout << endl << "Kogo pytał?" << endl;
    
    for (int i = 1; i <= ile_osob; i++)
    {
        int numerek;
        cin >> numerek;
        czy_pytal[numerek] = true;
        max_pytania--;
    }
    procent = 100 / (double)max_pytania;
    for (int i = 1; i < 33; i++)
    {
      if (czy_pytal[i] == false)
      {
        cout << procent << "%" << ' ' << klasa[i] << endl;
      }
    }
    return 0;
}