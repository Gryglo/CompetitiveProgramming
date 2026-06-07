#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll input; 
    cin >> input;

    vector<bool> sektory(input, false);
    for(ll i = 0; i < input; i++)
    {
        ll index;
        cin >> index;

        sektory[index - 1] = true;

        bool finden = false;
        for(ll x = index; x < input; x++)
        {
            if(sektory[x] == false)
            {
                cout << x + 1 << '\n';
                finden = true;
                break;
            }
        }
        if(!finden)
        {
            cout << "NIE" << '\n';
        }
    }
    return 0;
}