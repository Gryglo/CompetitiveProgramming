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

    //Wiemy ze zawsze najlepszy robot musi remisowac i nie moze przegrywac
    int tiesCount = 1;
    int tiesLooseCount = 0;

    //Przyjmujemy ze zwinnosc, czyli druga wartosc, to numer robota xD

    priority_queue<int, vector<int>, greater<int> > looserRobots;
    
    //int looseCount = 0;
    //int maxSpeedForLooserRobot = 0;

    int maxSpeed = robots[n];
    int minSpeed = robots[n];

    for(int i = n - 1; i >= 1; i--)
    {
        /*
        if(i == 1)
        {
            //tu jezeli jego zwinnosc jest mniejsza od minimalnej zwinnosci, wtedy znaczy ze on tylko przegrywa wiec go wgl nie liczymy
        }
        */
        /*

        1 1
        2 2 
        3 5
        4 4
        5 3
        */

        while(!looserRobots.empty() && robots[i] > looserRobots.top())
        {
            //moze byc jeszcze pomiedzy wiec kolejka priority bedzie lepsza
            tiesLooseCount++;
            looserRobots.pop();
        }
        /*
        if(robots[i] > maxSpeedForLooserRobot && looseCount > 0)
        {
            tiesLooseCount += looseCount;
            looseCount = 0;
            maxSpeedForLooserRobot = 0;
        }
        */
    
        if(robots[i] > minSpeed)
        {
            if(robots[i] < maxSpeed)
            {
                tiesLooseCount++;
            }
            else
            {
                maxSpeed = robots[i];
                tiesCount++;
            }

            //tutaj max
        }
        else
        {

            //musi byc max bo nie wiemy kiedy serio przegrywamy
            minSpeed = robots[i];
            looserRobots.push(robots[i]);

            /*
            if(robots[i] > maxSpeedForLooserRobot)
            {
                maxSpeedForLooserRobot = robots[i];
            }
            */
            //tiesLooseCount++; //nie zawsze
        }

        //cout << "\n" << i << " " << robots[i];
        //cout << '\n' << tiesCount << " " << tiesLooseCount << '\n';
    }

    //cout << '\n' << tiesCount << " " << tiesLooseCount;


    if((tiesCount + tiesLooseCount) % 2 == 0)
    {
        //POMYSL ZE SCIANA PRZEGRYWAJACYCH ROBOTOW DO KONCA
        //ROBOTY KTORE ZOSTANA W KOLEJCE TO ROBOTY KTORE PRZEGRYWAJA TOTALNIE 
        //WIEC MOZNA SPRAWDZIC WTEDY CZY 
        //ROBOT REMISUJE, REMISUJE I PRZEGRYWA I TYLKO PRZEGRYWA NA PODSTAWIE TEJ TABLICY
        //ALE MOZNA TEZ POPROSTU ZAPISYWAC

        //ZAPISUJ NAJWIEKSZA ZWINNOSC DLA REMISUJACO PRZEGRYWAJACYCH I NAJMNIEJSZA DLA REMISUJACYCH
        //JEZELI ZWINNOSC REMISUJACO PRZEGRYWAJACYCH BEDZIE WIEKSZA NIZ NAJMNIEJSZA ZWINNOSC REMISUJACYH
        //TO ISTNIEJE POLACZENIE
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