#include <iostream>
#include <set>
#include <vector>

#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    ll queryCount;
    cin >> queryCount;
    
    vector<ll> values(queryCount);
    for(ll i = 0; i < queryCount; i++)
        cin >> values[i];
        
    multiset<ll> currentNumbers;
    ll a = 0, b = 0;
    currentNumbers.insert(values[0]);

    for(ll i = 0; i < queryCount; i++)
    {
        ll targetA, targetB;
        cin >> targetA >> targetB;
        targetA--; 
        targetB--;
        
        while(targetA > a)
        {
            currentNumbers.erase(currentNumbers.find(values[a]));
            a++;
        }
        while(targetB > b)
        {
            b++;
            currentNumbers.insert(values[b]);
        }
        
        cout << *currentNumbers.rbegin() << '\n';
    }
    
    return 0;
}
