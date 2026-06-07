#include <iostream>
#include <numeric>

using namespace std;
int main()
{
    int z;
    cin >> z;
    while( z > 0 )
    {
        int n, d;
        cin >> n >> d;
        cout << n / gcd( n, d ) << '\n';
        --z;
    }
}