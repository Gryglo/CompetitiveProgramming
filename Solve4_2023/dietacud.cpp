#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct State {
    int x, y, balance;
    string path;
};

string find_diet_path(int N, int M, vector<string>& grid) {
    const int MAX_BALANCE = N + M;
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2 * MAX_BALANCE + 1, false)));

    queue<State> q;
    int initial_balance = (grid[0][0] == 'P') ? -1 : 1;
    q.push({0, 0, initial_balance, ""});
    visited[0][0][initial_balance + MAX_BALANCE] = true; 

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}};
    string moves = "PD";

    while (!q.empty()) {
        auto [x, y, balance, path] = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1 && balance == 0) {
            return "TAK\n" + path;
        }

        for (int i = 0; i < 2; ++i) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (nx < N && ny < M) {
                int new_balance = balance + (grid[nx][ny] == 'P' ? -1 : 1);

                if (new_balance >= -MAX_BALANCE && new_balance <= MAX_BALANCE &&
                    !visited[nx][ny][new_balance + MAX_BALANCE]) {
                    
                    visited[nx][ny][new_balance + MAX_BALANCE] = true;
                    q.push({nx, ny, new_balance, path + moves[i]});
                }
            }
        }
    }

    return "NIE";
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    cout << find_diet_path(N, M, grid) << endl;

    return 0;
}
