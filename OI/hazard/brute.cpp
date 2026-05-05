#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n;
struct Edge { int to; bool used; };
vector<vector<Edge>> adj;
vector<int> path;
int total_edges = 0;
int used_count = 0;

bool is_failure(int v) {
    // Porażka: koniec w Gn i wszystkie krawędzie zużyte
    return (v == n && used_count == total_edges);
}

bool solve(int v) {
    bool has_move = false;
    for (auto &e : adj[v]) {
        if (!e.used) {
            has_move = true;
            e.used = true;
            used_count++;
            path.push_back(e.to);

            if (solve(e.to)) return true;

            // Backtracking
            path.pop_back();
            used_count--;
            e.used = false;
        }
    }

    // Jeśli nie ma ruchów z v, gra się kończy
    if (!has_move) {
        return !is_failure(v);
    }
    
    return false;
}

int main() {
    if (!(cin >> n)) return 0;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        total_edges += k;
        for (int j = 0; j < k; j++) {
            int target; cin >> target;
            adj[i].push_back({target, false});
        }
    }

    if (solve(1)) {
        for (int x : path) cout << x << " ";
        cout << 0 << endl;
    } else {
        cout << "NIE" << endl;
    }
    return 0;
}