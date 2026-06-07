#include <iostream>
#include <vector>
using namespace std;

int n;
int main()
{
    cin >> n;
    vector<int> robots(n + 1);

    for(int i = 0; i < n; i++)
    {
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
    
    int maxSpeed = 0;
    int loose = 0;
    for(int i = n; i >= 1; i--)
    {
        if(robots[i] < maxSpeed)
            loose++;
        if(robots[i] > maxSpeed)
            maxSpeed = robots[i];
    }
    if((n - loose) % 2 == 0)
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}