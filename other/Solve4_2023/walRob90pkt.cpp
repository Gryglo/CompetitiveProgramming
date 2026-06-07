#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int main()
{
    cin >> n;
    vector<int> robots(n + 1);
    bool remainRobotsNums[n + 1];

    for(int i = 0; i < n; i++)
    {
        remainRobotsNums[i + 1] = true;
        int a, b;
        cin >> a >> b;
        if(a == n && b == n)
        {
            cout << "NIE";
            return 0;
        }
        if((a == n - 1 && b == n) || (a == n && b == n - 1))
        {
            cout << "TAK";
            return 0;
        }
        robots[a] = b;
    }
    int tiesCount = 1;
    int tiesLooseCount = 0;
    priority_queue<int, vector<int>, greater<int> > looserRobots;
    int maxSpeed = robots[n];
    int minSpeed = robots[n];

    for(int i = n - 1; i >= 1; i--)
    {
        while(!looserRobots.empty() && robots[i] > looserRobots.top())
        {
            tiesLooseCount++;
            looserRobots.pop();
        }
    
        if(robots[i] > minSpeed)
        {
            if(robots[i] < maxSpeed)
                tiesLooseCount++;
            else
            {
                maxSpeed = robots[i];
                tiesCount++;
            }
        }
        else
        {
            minSpeed = robots[i];
            looserRobots.push(robots[i]);
        }
    }

    if((tiesCount + tiesLooseCount) % 2 == 0)
        cout << "TAK";
    else
    {
        if(tiesLooseCount > 0)
            cout << "TAK";
        else
            cout << "NIE";
    }

    return 0;
}