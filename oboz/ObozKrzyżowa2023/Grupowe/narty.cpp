#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    double D, K, N[5], W;
    int BS, BK;
    cin >> D >> K;
    for(int i = 0; i < 5; i++) {
        cin >> N[i];
    }
    cin >> BS >> BK >> W;
    sort(N, N+5);
    double points = 60 + (D - K) * 1.8 + (N[1] + N[2] + N[3]) + (BK - BS) * 3.2 + W;
    cout << fixed << setprecision(1) << points;
    return 0;
}
