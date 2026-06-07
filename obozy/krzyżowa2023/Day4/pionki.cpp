#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    vector<long long> T(N);
    for (long long i = 0; i < N; i++) {
        cin >> T[i];
        T[i]--;
    }

    vector<long long> positions(N);
    for (long long i = 0; i < N; i++) {
        positions[i] = i;
    }

    while (K > 0) {
        if (K % 2 == 1) {
            vector<long long> newPositions(N);
            for (long long i = 0; i < N; i++) {
                newPositions[i] = positions[T[i]];
            }
            positions = newPositions;
        }

        vector<long long> newT(N);
        for (long long i = 0; i < N; i++) { 
            newT[i] = T[T[i]];
        }
        T = newT;

        K /= 2;
    }

    for (long long i = 0; i < N; i++) {
        cout << positions[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
