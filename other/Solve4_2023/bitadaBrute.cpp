#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int n, m, k;
vector<vector<int>> bitada_graph, bajtogrod_graph;
vector<vector<int>> dp;

void rootTree(int node, int parent, vector<vector<int>>& graph, vector<int>& order) {
    order.push_back(node);
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            rootTree(neighbor, node, graph, order);
        }
    }
}

void calculateDP(int bitada_node, int bajtogrod_node) {
    dp[bitada_node][bajtogrod_node] = 1;

    for (int bitada_child : bitada_graph[bitada_node]) {
        int child_ways = 0;
        for (int bajtogrod_child : bajtogrod_graph[bajtogrod_node]) {
            calculateDP(bitada_child, bajtogrod_child);
            child_ways = (child_ways + dp[bitada_child][bajtogrod_child]) % k;
        }
        dp[bitada_node][bajtogrod_node] = (dp[bitada_node][bajtogrod_node] * child_ways) % k;
    }
}

int main() {
    cin >> n >> m >> k;
    bitada_graph.resize(n + 1);
    bajtogrod_graph.resize(m + 1);
    dp.assign(n + 1, vector<int>(m + 1, -1));

    // Wczytujemy graf Bitady
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        bitada_graph[x].push_back(y);
        bitada_graph[y].push_back(x);
    }

    // Wczytujemy graf Bajtogrodu
    for (int i = 0; i < m - 1; i++) {
        int x, y;
        cin >> x >> y;
        bajtogrod_graph[x].push_back(y);
        bajtogrod_graph[y].push_back(x);
    }

    vector<int> bitada_order, bajtogrod_order;
    rootTree(1, -1, bitada_graph, bitada_order);
    rootTree(1, -1, bajtogrod_graph, bajtogrod_order);

    int total_ways = 0;
    for (int root_bajtogrod = 1; root_bajtogrod <= m; root_bajtogrod++) {
        calculateDP(1, root_bajtogrod);
        total_ways = (total_ways + dp[1][root_bajtogrod]) % k;
    }

    cout << total_ways << endl;

    return 0;
}
