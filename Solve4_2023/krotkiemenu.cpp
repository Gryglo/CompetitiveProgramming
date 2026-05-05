#include <iostream>
using namespace std;

long long sumaCyfr(long long x) {
    long long suma = 0;
    while (x > 0) {
        suma += x % 10;
        x /= 10;
    }
    return suma;
}

int main() {
    long long N;
    cin >> N;

    long long potega10 = 1;
    while (potega10 <= N) {
        potega10 *= 10;
    }


    long long P = potega10 / 10 - 1;
    long long S = N - P;

    long long maxSatysfakcja = sumaCyfr(P) + sumaCyfr(S);

    cout << maxSatysfakcja << endl;

    return 0;
}
