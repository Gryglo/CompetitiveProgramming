#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() 
{
    int N, Q;
    cin >> N;

    vector<ll> schody(N);
    for(int i = 0; i < N; i++)
    {
        cin >> schody[i];
    }

    cin >> Q;

    vector<pair<ll, int>> persons(Q);
    for (int i = 0; i < Q; i++) 
    {
        ll value;
        cin >> value;
        persons[i] = { value, i };
    }
    sort(persons.begin(), persons.end());


    vector<int> answear(Q);
    int a;
    a = 0;
    for(int i = 0; i < Q; i++)
    {
        pair<ll, int> value = persons[i];
        
        for(int x = a; x < N; x++)
        {
            ll schodek = schody[x];
            if(value.first < schodek)
            {
                break;
            }
            a++;
        }
        answear[value.second] = a;
    }

    for(ll value : answear)
    {
        cout << value << "\n";
    }

    return 0;
}