#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(3, vector<int>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(8, 0));
    dp[0][1] = board[0][0];
    dp[0][2] = board[1][0];
    dp[0][4] = board[2][0];

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < 8; ++i) {
            for (int k = 0; k < 8; ++k) {
                if ((i & k) == 0 && ((i << 1) & k) == 0 && ((i >> 1) & k) == 0) {
                    int sum = 0;
                    if (i & 1) sum += board[0][j];
                    if (i & 2) sum += board[1][j];
                    if (i & 4) sum += board[2][j];
                    dp[j][i] = max(dp[j][i], dp[j - 1][k] + sum);
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 8; ++i) {
        result = max(result, dp[n - 1][i]);
    }
    cout << result << endl;

    return 0;
}
