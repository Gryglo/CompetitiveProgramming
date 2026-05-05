#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    int n = rand() % 6 + 2; // n od 2 do 7
    cout << n << endl;

    for (int i = 1; i <= n; i++) {
        int k = rand() % 4; // do 3 krawędzi na generator
        cout << k;
        for (int j = 0; j < k; j++) {
            cout << " " << rand() % n + 1;
        }
        cout << endl;
    }
    return 0;
}