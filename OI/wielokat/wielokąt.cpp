#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> triangle_tree;
struct hashPair
{
    size_t operator()(const pair<int, int>& para) const
    {
        return ((long long) para.first) ^ (((long long) para.second) << 32);
    }
};
unordered_map<pair<int, int>, int, hashPair> edgeTriangles;

vector<vector<int>> dp;
int result = 0;
void DFS(int v, int parent)
{
    dp[v][0] = 1;
    for(int i = 0; i < triangle_tree[v].size(); i++)
    {
        int u = triangle_tree[v][i];
        if(u == parent)
            continue;
        DFS(u, v);
        dp[v][0] = max(dp[v][0], dp[u][0] + 1);
        dp[v][1] = max(dp[v][1], dp[u][1] + 1);
        for(int j = 0; j < i; j++)
        {
            int u2 = triangle_tree[v][j];
            if(u2 == parent)
                continue;
            dp[v][1] = max(dp[v][1], dp[u][0] + dp[u2][0] + 1);
            if(dp[u2][1] != 0)
                dp[v][2] = max(dp[v][2], dp[u][0] + dp[u2][1] + 1);
            if(dp[u][1] != 0)
                dp[v][2] = max(dp[v][2], dp[u][1] + dp[u2][0] + 1); 
        }
    }
    if(triangle_tree[v].size() >= 3)
    {
        vector<int> childs;
        for(int i = 0; i < triangle_tree[v].size(); i++)
        {
            int u = triangle_tree[v][i];
            if(u == parent)
                continue;
            childs.push_back(u);
        }
        if(childs.size() == 3)
            dp[v][2] = max(dp[v][2], dp[childs[0]][0] + dp[childs[1]][0] + dp[childs[2]][0] + 1);
    }
    for(int i = 0; i < 3; i++)
        result = max(result, dp[v][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    triangle_tree.resize(n - 2);
    for(int i = 0; i < n - 2; i++)
    {
        vector<int> triangle(3);
        for(int j = 0; j < 3; j++)
            cin >> triangle[j];
        sort(triangle.begin(), triangle.end());
        for(int j = 0; j < 3; j++)
        {
            int a = j, b = j + 1;
            if(b == 3){
                a = 0;
                b = 2;
            }

            if(edgeTriangles.find({triangle[a], triangle[b]}) == edgeTriangles.end())
                edgeTriangles[{triangle[a], triangle[b]}] = i;
            else
            {
                int connected_triangle = edgeTriangles[{triangle[a], triangle[b]}];
                triangle_tree[i].push_back(connected_triangle);
                triangle_tree[connected_triangle].push_back(i);
            }
        }
    }

    if(n == 1){ cout << '1'; return 0; }
    bool hasMultipleWays = false;
    for(int i = 0; i < n - 2; i++)
    {
        if(triangle_tree[i].size() >= 3)
        {
            hasMultipleWays = true;
            break;
        }
    }
    if(!hasMultipleWays){ cout << (n - 2); return 0; }
    dp.resize(n - 2, vector<int>(3));
    DFS(0, -1);
    cout << result;
    return 0;
}