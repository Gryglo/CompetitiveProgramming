#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

string input;
vector<vector<char>> zupa(3, vector<char>(3));
vector<vector<bool>> visited(3, vector<bool>(3, false));

bool dfs(int x, int y, int index) 
{
    if (index == input.size()) return true;
    visited[x][y] = true;

    for (int k = 0; k < 4; ++k) 
    {
        int moveX = x + dx[k]; 
        int moveY = y + dy[k];
        if(moveX < 0 || moveX >= 3 || moveY < 0 || moveY >= 3 || visited[moveX][moveY] || zupa[moveX][moveY] != input[index])
            continue;
        
        if(dfs(moveX, moveY, index + 1)) 
            return true;
    }
    visited[x][y] = false;
    return false;
}

int main() 
{
    cin >> input;  

    for (int x = 0; x < 3; ++x) 
        for (int y = 0; y < 3; ++y) 
            cin >> zupa[x][y];

    if (zupa[0][0] != input[0]) 
    {
        cout << "NIE" << '\n'; 
        return 0;
    }

    for (int x = 0; x < 3; ++x)
    {
        for (int y = 0; y < 3; ++y) 
        {
            if (zupa[x][y] == input[0]) 
            {
                if (dfs(x, y, 1)) 
                {
                    cout << "TAK" << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "NIE" << '\n';
    return 0;
}
