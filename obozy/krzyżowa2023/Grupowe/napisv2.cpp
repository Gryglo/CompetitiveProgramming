#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<char, int>> zliczanieLiter(string napis) 
{
    char obecnaLitera = napis[0];
    int liczbaLiter = 0;
    vector<pair<char, int>> literki;

    for(int i = 0; i < napis.size(); i++) 
    {
        char aktualnaLitera = napis[i];
        if(aktualnaLitera == obecnaLitera)
            liczbaLiter++;
        else 
        {
            literki.push_back( {obecnaLitera, liczbaLiter} );
            liczbaLiter = 1;
            obecnaLitera = aktualnaLitera;
        }
    }
    if(liczbaLiter > 0)
        literki.push_back( {obecnaLitera, liczbaLiter} );

    return literki;
}

string dobieranieLiter(vector<pair<char, int>> literki) 
{
    bool powtarzanie = false;
    string wynik = "";
    for(int x = 0; x < literki.size(); x++) 
    {
        pair<char, int> para = literki[x];

        for(int z = 0; z < para.second; z++) 
        {
            if(powtarzanie == false) 
            {
                wynik += para.first;
                powtarzanie = true;
            }
            else 
            {
                char nastepnaLitera;
                bool czyZnalezionoNastepnaLitera = false;
                for(int y = x + 1; y < literki.size(); y++) 
                {
                    pair<char, int> nastepnaPara = literki[y];
                    if(nastepnaPara.second > 0) 
                    {
                        nastepnaPara.second--;
                        nastepnaLitera = nastepnaPara.first;
                        literki[y] = nastepnaPara;
                        czyZnalezionoNastepnaLitera = true;
                        break;
                    }
                }
                if(czyZnalezionoNastepnaLitera) 
                {
                    wynik  = wynik + nastepnaLitera + para.first;
                }
                else 
                {
                    return "NIE";
                }
            }
        }
        powtarzanie = false;
    }

    return wynik;
}

int main() {
    string wejscie;
    cin >> wejscie;
    
    sort(wejscie.begin(), wejscie.end());

    vector<pair<char, int>> literki = zliczanieLiter(wejscie);
    string wynik = dobieranieLiter(literki);

    cout << wynik;

    return 0;
}
