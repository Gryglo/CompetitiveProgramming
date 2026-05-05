#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Użycie tablicy statycznej zamiast vector<vector> oszczędza czas i pamięć
const int MAXN = 5005;
int dp[MAXN][MAXN];
vector<int> adj[MAXN];

int main() {
    // Przyspieszenie wejścia/wyjścia
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue; // Ignorujemy pętle własne
        u--; v--; // Mapowanie na 0...n-1
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Usuwamy duplikaty krawędzi dla przyspieszenia pętli
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    // Każdy pojedynczy wierzchołek to ścieżka o długości 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    int ans = 1;

    // Przetwarzamy wierzchołki od najwyższych do najniższych.
    // Dzięki temu, dodając v, mamy pewność, że v jest mniejsze od wszystkich 
    // wierzchołków aktualnie znajdujących się w dp[x][u].
    for (int v = n - 1; v >= 0; v--) {
        for (int u : adj[v]) {
            if (u < v) continue; // Interesują nas tylko sąsiedzi, których już przetworzyliśmy (wyżsi)

            // v staje się nowym końcem ścieżki, która kończyła się w u i x
            for (int x = v; x < n; x++) {
                if (dp[u][x] > 0) {
                    int new_len = dp[u][x] + 1;
                    if (new_len > dp[v][x]) {
                        dp[v][x] = dp[x][v] = new_len;
                        if (new_len > ans) ans = new_len;
                    }
                }
            }
        }
    }

    // Jeśli graf jest pusty i n=0, ans zostanie 1, co jest bezpieczne dla n >= 1.
    cout << ans << endl;

    return 0;
}