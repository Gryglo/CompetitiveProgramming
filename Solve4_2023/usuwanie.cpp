#include <iostream>
using namespace std;

#define ll unsigned long long
int main()
{
    ll a, b;
    cin >> a >> b;
    
    ll parzyste = (b / 2) - ((a - 1) / 2);
    ll nieparzyste = (b - a + 1) - parzyste;
    cout << ((parzyste / 2) * 2 + (nieparzyste / 2) * 2);

    return 0;
}
