#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    vector<int> left(N), right(N);
    left[0] = right[N - 1] = 1;

    for(int i = 1; i < N; i++) {
        left[i] = (H[i] >= H[i - 1]) ? left[i - 1] + 1 : 1;
    }

    for(int i = N - 2; i >= 0; i--) {
        right[i] = (H[i] >= H[i + 1]) ? right[i + 1] + 1 : 1;
    }

    int maxLength = 0;
    for(int i = 0; i < N; i++) {
        int length = min(H[i], max(left[i], right[i]));
        maxLength = max(maxLength, length);
    }

    cout << maxLength << endl;

    return 0;
}
