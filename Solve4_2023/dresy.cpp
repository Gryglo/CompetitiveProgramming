#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isSolved = false;
bool isSolvedAtLeast = false;
vector<vector<bool>> tempVisited;
vector<vector<char>> labirynt;
vector<pair<int, int>> dresy;
vector<vector<int>> distances;

int maxDistance = -1;

int n, M;

bool inside(int x, int y, vector<vector<bool>>& visited) 
{
    return (x >= 0 && x < n && y >= 0 && y < M && labirynt[x][y] != '#' && !visited[x][y]);
}

vector<vector<int>> calculateDistances() 
{
    queue<pair<int, int>> q;
    vector<vector<int>> distance(n, vector<int>(M, -1));
    vector<vector<bool>> visited(n, vector<bool>(M, false));
    for(pair<int, int> dresPos : dresy) 
    {
        distance[dresPos.first][dresPos.second] = 0;
        visited[dresPos.first][dresPos.second] = true;
        q.push(dresPos);
    }

    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
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
                if(distance[updatedX][updatedY] > maxDistance)
                    maxDistance = distance[updatedX][updatedY];
            }
        }
    }
    return distance;
}

void isPathValid(int y, int x, int minimalVal) 
{
    queue<pair<int, int>> q;
    tempVisited[y][x] = true;
    q.push({y, x});

    while (!q.empty()) 
    {
        int currentY = q.front().first;
        int currentX = q.front().second;
        q.pop();

        if(labirynt[currentY][currentX] == 'S')
        {
            isSolved = true;
            isSolvedAtLeast = true;
            return;
        }

        for (int i = 0; i < 4; ++i) 
        {
            int updatedY = currentY + dy[i];
            int updatedX = currentX + dx[i];

            if (inside(updatedY, updatedX, tempVisited) && distances[updatedY][updatedX] >= minimalVal) 
            {
                q.push({updatedY, updatedX});
                tempVisited[updatedY][updatedX] = true;
            }
        }
    }
}

int main() 
{
    cin >> n >> M;
    
    // RESECIK VECTORA
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

    if(maxDistance == -1)
    {
        cout << "OK";
        return 0;
    }

    int l = -1, r = maxDistance;
    int mostOptimalWay = -1;
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        isSolved = false;

        // RESECIK VECTORA
        tempVisited.assign(n, vector<bool>(M, false));

        //cout << "Iteration: " << mid << "\n";
        isPathValid(startXPOS, startYPOS, mid);
        if(isSolved) 
        {
            l = mid;
            if(mid > mostOptimalWay)
                mostOptimalWay = mid;
        }
        else 
            r = mid - 1;

    }

    if(isSolvedAtLeast)
        cout << mostOptimalWay;
    else
        cout << "NIE";

    return 0;
}