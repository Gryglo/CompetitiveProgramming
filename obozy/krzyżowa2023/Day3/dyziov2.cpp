#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

int calculatePrimesInRange(int lower, int upper) 
{
    int count = 0;
    if (lower <= 2) {
        lower = 2;
        if (upper >= 2) {
            count++;
            ++lower;
        }
    }
    
    if (lower % 2 == 0)
        ++lower;

    for (int i = lower; i <= upper; i += 2) {
        if (isPrime(i)) {
            if (i != 1)
                count++;
        }
    }

    return count;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    for(int x = 0; x < Q; x++)
    {
        int lower, upper;
        cin >> lower;
        cin >> upper;
        cout << calculatePrimesInRange(lower, upper) << "\n";
    }
    return 0;
}
