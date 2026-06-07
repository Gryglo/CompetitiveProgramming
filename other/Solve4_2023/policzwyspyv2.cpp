#include <vector>
#include <iostream>

using namespace std;

void isPathValid(int i, int j, vector<vector<int>>& grid) 
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        return;
    grid[i][j] = 0;
    isPathValid(i+1, j, grid);
    isPathValid(i-1, j, grid);
    isPathValid(i, j+1, grid);
    isPathValid(i, j-1, grid);
}

int countIslands(vector<vector<int>>& grid) 
{
    int count = 0;
    for(int i=0; i<grid.size(); i++) 
    {
        for(int j=0; j<grid[0].size(); j++) 
        {
            if(grid[i][j] == 1) 
            {
                isPathValid(i, j, grid);
                count++;
            }
        }
    }
    return count;
}

int main() 
{
    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> grid[i][j];
    cout << countIslands(grid) << '\n';
    return 0;
}
