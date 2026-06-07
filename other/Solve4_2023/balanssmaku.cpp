#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    string recipe;
    cin >> recipe;

    long long sugarSum = 0;
    long long saltSum = 0;

    for (int i = 0; i < N; i++) 
    {
        long long value = 1LL << (i + 1);
        if (recipe[i] == 'C') 
            sugarSum += value;
        else if (recipe[i] == 'S') 
            saltSum += value;
    }

    if (sugarSum > saltSum) 
        cout << "SLODKA" << '\n';
    else if (saltSum > sugarSum)
        cout << "SLONA" << '\n';
    else 
        cout << "BALANS" << '\n';
    

    return 0;
}
