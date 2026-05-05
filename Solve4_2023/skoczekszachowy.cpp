#include <iostream>
#include <queue>
using namespace std;

const int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
const int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};

int n, M;
char board[1000][1000];

struct Field 
{
    int x, y, distance;
};

bool isValid(const int& x, const int& y)
{
    return x >= 0 && x < n && y >= 0 && y < M && board[x][y] != '#';
}

int bfs(const int& startX, const int& startY, const int& endX, const int& endY)
{
    queue<Field> pendingMoves;

    pendingMoves.push({startX, startY, 0});
    board[startX][startY] = '#';

    while(!pendingMoves.empty())
    {
        Field currField = pendingMoves.front();
        pendingMoves.pop();

        if(currField.x == endX && currField.y == endY)
            return currField.distance;

        for(int i = 0; i < 8; i++)
        {
            Field nextMove = {currField.x + dx[i], currField.y + dy[i], currField.distance + 1};

            if(isValid(nextMove.x, nextMove.y))
            {
                board[nextMove.x][nextMove.y] = '#';
                pendingMoves.push(nextMove);
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> M;

    int startX = -1, startY = -1, endX = -1, endY = -1;
    
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < M; y++)
        {
            cin >> board[x][y];
            if(board[x][y] == 'S') 
            {
                startX = x;
                startY = y;
            } 
            else if(board[x][y] == 'K') 
            {
                endX = x;
                endY = y;
            }
        }
    }

    int result = bfs(startX, startY, endX, endY);

    if(result != -1)
        cout << result << endl;
    else
        cout << "NIE" << endl;

    return 0;
}
