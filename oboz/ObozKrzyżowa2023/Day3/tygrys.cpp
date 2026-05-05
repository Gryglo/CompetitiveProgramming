#include <iostream>
#include <vector>
#include <algorithm>
#define ll unsigned long long

using namespace std;

int main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> tygrysy(n);

    for(int i = 0; i < n; i++)
    {
        cin >> tygrysy[i]; 
    }

    sort(tygrysy.begin(), tygrysy.end());

    ll lastValue = tygrysy[0];
    ll smallestValueIndex = 0;
    int count = 1;

    for(int i = 1; i < n; i++)
    {
        if((lastValue * 2) > tygrysy[i])
        {
            if((tygrysy[smallestValueIndex] * 2) > tygrysy[i])
                count++;
            else
                smallestValueIndex++;
        }
        else
            smallestValueIndex++;
        lastValue = tygrysy[i];
    }
    cout << count;

    return 0;
}
