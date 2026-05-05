#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool canCutIntoPieces(const vector<int>& lengths, int K, double maxLength) 
{
    int count = 0;
    for (int length : lengths) {
        count += length / maxLength;
        if (count >= K) {
            return true;
        }
    }
    return false;
}

double findMaxPieceLength(const vector<int>& lengths, int K) {
    double lower = 0.0;
    double upper = *max_element(lengths.begin(), lengths.end());

    while (upper - lower > 1e-6) {
        double mid = (lower + upper) / 2.0;
        if (canCutIntoPieces(lengths, K, mid)) {
            lower = mid;
        } else {
            upper = mid;
        }
    }

    return lower;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> lengths(N);
    for (int i = 0; i < N; i++) {
        cin >> lengths[i];
    }

    double maxPieceLength = findMaxPieceLength(lengths, K);
    //maxPieceLength -= 0.0000001;
    //cout.precision(10);
    //cout << maxPieceLength << endl;

    cout << setprecision(7) << fixed << maxPieceLength << endl;
    return 0;
}