#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int findSet(int element) {
        if (parent[element] != element) {
            parent[element] = findSet(parent[element]);
        }
        return parent[element];
    }

    void unionSets(int element1, int element2) {
        int root1 = findSet(element1);
        int root2 = findSet(element2);
        if (root1 != root2) {
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            }
            else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            }
            else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

bool isPathPossible(int minAge, vector<vector<int>> forest, int size, int d, DisjointSet& ds) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (forest[i][j] <= minAge) {
                if (i > 0 && forest[i - 1][j] <= minAge) {
                    ds.unionSets(i * size + j, (i - 1) * size + j);
                }
                if (j > 0 && forest[i][j - 1] <= minAge) {
                    ds.unionSets(i * size + j, i * size + j - 1);
                }
            }
        }
    }

    vector<int> treeCount(size * size, 0);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (forest[i][j] <= minAge) {
                int root = ds.findSet(i * size + j);
                treeCount[root]++;
            }
        }
    }

    int maxArea = 0;
    for (int i = 0; i < size * size; i++) {
        maxArea = max(maxArea, treeCount[i]);
    }

    return maxArea >= d;
}

int main()
{
    int size, d;
    cin >> size >> d;
    vector<vector<int>> forest(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> forest[i][j];
        }
    }

    int left = 1, right = 1e9, result = -1; 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        DisjointSet ds(size * size);
        if (isPathPossible(mid, forest, size, d, ds)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result << endl; 
    return 0;
}
