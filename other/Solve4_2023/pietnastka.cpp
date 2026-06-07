#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int i : v) {
            hash ^= hash * 31 + std::hash<int>()(i);
        }
        return hash;
    }
};

struct State {
    vector<int> board;
    int zero_pos;
    string path;
};

const vector<int> target = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

const vector<pair<int, char>> directions = {{-4, 'G'}, {4, 'D'}, {-1, 'L'}, {1, 'P'}};

bool can_move(int zero_pos, int move) {
    if ((move == -1 && zero_pos % 4 == 0) || (move == 1 && zero_pos % 4 == 3)) return false;
    if (zero_pos + move < 0 || zero_pos + move >= 16) return false;
    return true;
}

int count_inversions(const vector<int>& board) {
    int inv_count = 0;
    for (int i = 0; i < 16; ++i) {
        if (board[i] == 0) continue;
        for (int j = i + 1; j < 16; ++j) {
            if (board[j] != 0 && board[i] > board[j]) ++inv_count;
        }
    }
    return inv_count;
}

bool is_solvable(const vector<int>& board) {
    int inv_count = count_inversions(board);
    int zero_row = 4 - (find(board.begin(), board.end(), 0) - board.begin()) / 4;
    return (inv_count + zero_row) % 2 == 0;
}

unordered_map<vector<int>, string, VectorHash> bfs(const vector<int>& start) {
    unordered_map<vector<int>, string, VectorHash> visited;
    queue<State> q;
    
    int zero_pos = find(start.begin(), start.end(), 0) - start.begin();
    q.push({start, zero_pos, ""});
    visited[start] = "";

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.board == target) {
            return visited;
        }

        for (auto [move, dir] : directions) {
            int new_zero_pos = current.zero_pos + move;
            if (!can_move(current.zero_pos, move)) continue;

            vector<int> new_board = current.board;
            swap(new_board[current.zero_pos], new_board[new_zero_pos]);

            if (visited.find(new_board) == visited.end()) {
                visited[new_board] = current.path + dir;
                q.push({new_board, new_zero_pos, visited[new_board]});
            }
        }
    }
    return visited;
}

int main() {
    vector<int> board(16);
    for (int i = 0; i < 16; ++i) {
        cin >> board[i];
    }

    if (!is_solvable(board)) {
        cout << "NIE" << endl;
        return 0;
    }

    auto forward_search = bfs(board);
    auto backward_search = bfs(target);

    string result = "NIE";
    for (const auto& [state, path] : forward_search) {
        if (backward_search.find(state) != backward_search.end()) {
            string solution = path + backward_search[state];
            if (solution.size() <= 30) {
                result = solution;
                break;
            }
        }
    }

    cout << result << endl;
    return 0;
}
