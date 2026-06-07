#include <iostream>
#include <vector>

#define ll long long
using namespace std;

struct Sektor
{
    ll sektorNumber;
    ll nextFree;
    bool free;
    Sektor()
    {
        free = true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll input; 
    cin >> input;

    vector<Sektor> wolneSektory(input);
    for(ll i = 0; i < input; i++)
    {
        Sektor sektor = wolneSektory[i];
        sektor.nextFree = i + 1;
        sektor.sektorNumber = i + 1;
        wolneSektory[i] = sektor;
    }

    for(ll i = 0; i < input; i++)
    {
        ll index;
        cin >> index;

        Sektor sektor = wolneSektory[index - 1];
        sektor.free = false;
        wolneSektory[index - 1] = sektor;
        
        if(sektor.nextFree >= input) 
        {
            cout << "NIE" << '\n';
            continue;
        }

        vector<ll> sprawdzoneIndexy;
        
        Sektor nextSektor = wolneSektory[sektor.nextFree];
        bool finden = true;

        sprawdzoneIndexy.push_back(nextSektor.sektorNumber - 1);
        while(!nextSektor.free)
        {
            if(nextSektor.nextFree >= input)
            {
                finden = false;
                break;
            }
            nextSektor = wolneSektory[nextSektor.nextFree];
            sprawdzoneIndexy.push_back(nextSektor.sektorNumber - 1);
        }

        for(ll numer : sprawdzoneIndexy)
        {
            Sektor reloadSektor = wolneSektory[numer];
            if(reloadSektor.sektorNumber == nextSektor.sektorNumber) continue;
            reloadSektor.nextFree = nextSektor.sektorNumber - 1;
            wolneSektory[numer] = reloadSektor;
        }

        if(!finden)
        {
            cout << "NIE" << '\n';
            continue; 
        }

        cout << nextSektor.sektorNumber << '\n';
    }
    return 0;
}
