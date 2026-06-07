#include <iostream>
#include <vector>
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

    //Wiemy ze zawsze najlepszy robot musi remisowac i nie moze przegrywac
    int tiesCount = 1;
    int tiesLooseCount = 0;

    //Przyjmujemy ze zwinnosc, czyli druga wartosc, to numer robota xD

    priority_queue<int, vector<int>, greater<int> > looserRobots;
    
    //int looseCount = 0;
    //int maxSpeedForLooserRobot = 0;

    int maxSpeed = robots[n];
    int minSpeed = robots[n];
    
    int maxSpeedForTieLoose = 0;
    int minSpeedForTie = robots[n];

    bool breakedPassen = false;
    int loosePassenCount = 0;

    for(int i = n - 1; i >= 1; i--)
    {
        while(!looserRobots.empty() && robots[i] > looserRobots.top())
        {
            tiesLooseCount++;
            if(looserRobots.top() > maxSpeedForTieLoose)
                maxSpeedForTieLoose = looserRobots.top();
            looserRobots.pop();
        }

        if(robots[i] > minSpeed)
        {
            if(robots[i] < maxSpeed)
            {
                tiesLooseCount++;
                loosePassenCount++;
                if(robots[i] > maxSpeedForTieLoose)
                    maxSpeedForTieLoose = robots[i];
            }
            else
            {
                maxSpeed = robots[i];
                tiesCount++;
                if(robots[i] < minSpeedForTie)
                    minSpeedForTie = robots[i];
                if(loosePassenCount != 0)
                    breakedPassen = true;
            }
        }
        else
        {
            minSpeed = robots[i];
            looserRobots.push(robots[i]);
            loosePassenCount++;
        }
    }
    

    if(loosePassenCount > 0 && !breakedPassen)
    {
        if(tiesCount % 2 == 0)
            cout << "TAK";
        else if(tiesLooseCount > 0)
        {
            if(maxSpeedForTieLoose > minSpeedForTie)
                cout << "TAK";
            else
                cout << "NIE";
        }
        else
            cout << "NIE";
    }
    else if((tiesCount + tiesLooseCount) % 2 == 0)
        cout << "TAK";
    else if(tiesLooseCount > 0)
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}