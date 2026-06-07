#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Robot {
    int strength, agility;
};

int main() {
    int n;
    cin >> n;
    vector<Robot> robots(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> robots[i].strength >> robots[i].agility;
    }
    
    sort(robots.begin(), robots.end(), [](Robot &a, Robot &b) {
        return a.strength < b.strength; 
    });
    
    int totalRemisCount = 0, oddGroupCount = 0;
    int currentRemisCount = 0;
    int maxAgility = robots[0].agility;
    
    for (int i = 0; i < n; ++i) {
        if (robots[i].agility < maxAgility) {
            currentRemisCount++;
        } else {
            if (currentRemisCount % 2 != 0) {
                oddGroupCount++;
            }
            totalRemisCount += currentRemisCount;
            currentRemisCount = 1; // Nowy przedział zaczynamy od tego robota
            maxAgility = robots[i].agility;
        }
    }
    
    // Obsłużenie ostatniej grupy
    if (currentRemisCount % 2 != 0) {
        oddGroupCount++;
    }
    totalRemisCount += currentRemisCount;

    if ((totalRemisCount % 2 == 0) || (oddGroupCount % 2 == 0)) {
        cout << "TAK";
    } else {
        cout << "NIE";
    }

    return 0;
}
