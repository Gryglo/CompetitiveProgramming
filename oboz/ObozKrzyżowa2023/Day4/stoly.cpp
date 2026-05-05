#include <iostream>
#include <vector>

#define ll long long
using namespace std;

vector<bool> obszczany(1'000'001);
vector<int> dzieci(1'000'001);
int stoly = 0;

void obszczajDzieci(int dzieckoDoObszczania)
{
    if(obszczany[dzieckoDoObszczania] == true)
    {
        stoly++;
    }
    else
    {
        obszczany[dzieckoDoObszczania] = true;
        obszczajDzieci(dzieci[dzieckoDoObszczania]);
    }
}

int main() 
{
    int N;
    cin >> N;
    vector<bool> czyBylo(N + 1);

    for(int i = 1; i <= N; i++)
    {
        int value;
        cin >> value;
        dzieci[i] = value;
        if(czyBylo[value] == true)
        {
            cout << "NIE";
            return 0;
        }
        czyBylo[value] = true;
    }

    for(int i = 1; i <= N; i++)
    {
        int dzieckoDoObszczania = dzieci[i];
        if(obszczany[i] == false)
        {
            obszczany[i] = true;
            obszczajDzieci(dzieckoDoObszczania);
        }
    }
    cout << stoly;
    

    return 0;
} 