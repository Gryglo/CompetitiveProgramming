#include <iostream>
#include <queue>

#define ll long long
using namespace std;
int main()
{
    ll containersCount, targetMoney; 
    cin >> containersCount >> targetMoney;

    ll currentCounter = 0; 
    ll firstIndex = 0;
    ll tempFirstIndex = 0;
    ll smallestBreaks = 9999999999;
    queue<ll> skarbonki;
    for(int i = 0; i < containersCount; i++)
    {
        ll value;
        cin >> value;

        currentCounter += value;
        skarbonki.push(value);
        while(currentCounter >= targetMoney)
        {
            if(skarbonki.size() < smallestBreaks)
            {
                smallestBreaks = skarbonki.size();
                firstIndex = tempFirstIndex;
            }
            
            currentCounter -= skarbonki.front();
            skarbonki.pop();
            tempFirstIndex++;
        }
    }

    cout << smallestBreaks << " " << firstIndex + 1;

    return 0;
}
