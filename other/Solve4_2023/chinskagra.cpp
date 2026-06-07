#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<char, int> powerMap;
    powerMap['W'] = 0;
    powerMap['O'] = 1;
    powerMap['P'] = 2;
    powerMap['Z'] = 3;

    int karolPower;
    cin >> karolPower;
    char karolElement;
    cin >> karolElement;
    
    int karolElementIndex = powerMap[karolElement];
    for(int i = 0; i < 4; i++)
    {
        int value;
        cin >> value;
        if(i == karolElementIndex)
            karolPower += value;
    }

    int quangaPower;
    cin >> quangaPower;
    char quangaElement;
    cin >> quangaElement;
    
    int quangaElementIndex = powerMap[quangaElement];
    for(int i = 0; i < 4; i++)
    {
        int value;
        cin >> value;
        if(i == quangaElementIndex)
            quangaPower += value;
    }

    if((karolElementIndex + 1) % 4 == quangaElementIndex)
        karolPower *= 2;
    else if((quangaElementIndex + 1) % 4 == karolElementIndex)
        quangaPower *= 2;
    
    if(karolPower > quangaPower)
        cout << "WYGRANA";
    else if(quangaPower > karolPower)
        cout << "PRZEGRANA";
    else if(quangaPower == karolPower)
        cout << "REMIS";
    
    return 0;
}