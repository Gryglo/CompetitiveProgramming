#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int node, weight;
};

vector<vector<Edge>> tree;
vector<long long> subtree_size;
vector<long long> distancesSum;
int n;

void dfs1(int node, int parent) 
{
    subtree_size[node] = 1;
    for (const auto& edge : tree[node]) 
    {
        int neighbor = edge.node;
        int weight = edge.weight;
        if (neighbor != parent) 
        {
            dfs1(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
            //cout << "\nNode: " << node << " Subtree size: " << subtree_size[node];
            distancesSum[node] += distancesSum[neighbor] + subtree_size[neighbor] * weight;
            //cout << "\nDistance: " << dist_sum[node];
        }
    }
}

void dfs2(int node, int parent)
{
    for (const auto& edge : tree[node]) 
    {
        int neighbor = edge.node;
        int weight = edge.weight;

        if (neighbor != parent) 
        {
            distancesSum[neighbor] = distancesSum[node] + (n - 2 * subtree_size[neighbor]) * weight;
            //cout << "\nNode: " << node << " Subtree size: " << subtree_size[node];
            //cout << "\nSubtree size neighbor: " << subtree_size[neighbor];
            // << "\nDistance node: " << dist_sum[node];
            //cout << "\nDistance neighbor: " << dist_sum[neighbor];

            dfs2(neighbor, node);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    tree.resize(n + 1);
    subtree_size.resize(n + 1);
    distancesSum.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) 
    {
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }
    
    dfs1(1, -1);
    dfs2(1, -1);
    
    long long result = distancesSum[1];
    for (int i = 2; i <= n; ++i) 
        result = min(result, distancesSum[i]);
    
    cout << result << "\n";
    
    return 0;
}
