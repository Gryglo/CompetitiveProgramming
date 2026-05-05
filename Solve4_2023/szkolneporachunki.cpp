#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<bool>> tempVisited;
vector<vector<char>> labirynt;
vector<pair<int, int>> dresy;
vector<vector<int>> distances;

int maxDistance = -1;

int n, M;
bool isSolved = false;

bool inside(int x, int y, vector<vector<bool>>& visited) 
{
    return (x >= 0 && x < n && y >= 0 && y < M && labirynt[x][y] != '#' && !visited[x][y]);
}

vector<vector<int>> calculateDistances() 
{
    queue<pair<int, int>> q;
    vector<vector<int>> distance(n, vector<int>(M, -1));
    vector<vector<bool>> visited(n, vector<bool>(M, false));

    for (const auto& dresPos : dresy) 
    {
        distance[dresPos.first][dresPos.second] = 0;
        visited[dresPos.first][dresPos.second] = true;
        q.push(dresPos);
    }

    while (!q.empty()) 
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) 
        {
            int updatedX = x + dx[i];
            int updatedY = y + dy[i];

            if (inside(updatedX, updatedY, visited)) 
            {
                q.push({updatedX, updatedY});
                visited[updatedX][updatedY] = true;
                distance[updatedX][updatedY] = distance[x][y] + 1;
            }
        }
    }

    return distance;
}

void isPathValid(int startY, int startX, int minimalVal) 
{
    queue<pair<int, int>> q;
    q.push({startY, startX});
    tempVisited[startY][startX] = true;

    while (!q.empty()) 
    {
        auto [y, x] = q.front();
        q.pop();

        if (labirynt[y][x] == 'S') 
        {
            isSolved = true;
            return;
        }

        for (int i = 0; i < 4; ++i) 
        {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (inside(newY, newX, tempVisited) && distances[newY][newX] >= minimalVal) 
            {
                tempVisited[newY][newX] = true;
                q.push({newY, newX});
            }
        }
    }
}

int main() 
{
    cin >> n >> M;

    labirynt.assign(n, vector<char>(M));
    int startXPOS, startYPOS;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < M; ++j) 
        {
            cin >> labirynt[i][j];
            if (labirynt[i][j] == 'J') 
            {
                startXPOS = i;
                startYPOS = j;
            }
            else if(labirynt[i][j] == 'D')
                dresy.push_back({i, j});
        }
    }

    distances = calculateDistances();

    if (distances[startXPOS][startYPOS] == -1) 
    {
        cout << "NIE";
        return 0;
    }

    int l = 0, r = maxDistance;
    int mostOptimalWay = -1;

    while (l <= r) 
    {
        int mid = (l + r) / 2;
        isSolved = false;

        tempVisited.assign(n, vector<bool>(M, false));

        isPathValid(startXPOS, startYPOS, mid);
        
        if (isSolved) 
        {
            mostOptimalWay = mid;
            l = mid + 1;
        }
        else 
        {
            r = mid - 1;
        }
    }

    if (mostOptimalWay == -1)
        cout << "NIE";
    else
        cout << mostOptimalWay;

    return 0;
}
