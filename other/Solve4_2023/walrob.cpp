#include <iostream>
#include <vector>
#include <algorithm>
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
    int tiesCount = 0;
    //int looseCount = 0;
    int tiesLooseCount = 0;
    //Przyjmujemy ze zwinnosc, czyli druga wartosc, to numer robota xD
    for(int i = 1; i <= n; i++)
    {
        int a = i, b = robots[i];

        int ties = n - i;
        int loose = 0;

        for(int x = n; x > b; x--)
            if(remainRobotsNums[x])
                loose++;
            else
                ties++;
        remainRobotsNums[b] = false;
        ties -= loose;

        if(ties != 0 && loose != 0)
            tiesLooseCount++;
        else if(ties != 0)
            tiesCount++;


        //cout << "\ni: " << i << '\n';
        //cout << ties << " " << loose << '\n';
        //cout << tiesCount << " " << tiesLooseCount << '\n';
    }

    if((tiesCount + tiesLooseCount) % 2 == 0)
    {
        cout << "TAK";
    }
    else
    {
        if(tiesLooseCount > 0)
            cout << "TAK";
        else
            cout << "NIE";
    }


    return 0;
}