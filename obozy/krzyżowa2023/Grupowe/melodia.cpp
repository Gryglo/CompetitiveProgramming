#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool is_possible = false;
    for (int i = 0; i <= 6; i++) {
        bool is_valid = true;
        for (int j = 0; j < n; j++) {
            if ((a[j] + i) % 12 == 0 || (a[j] + i) % 12 == 2 || (a[j] + i) % 12 == 4 || (a[j] + i) % 12 == 5 || (a[j] + i) % 12 == 7 || (a[j] + i) % 12 == 9 || (a[j] + i) % 12 == 11) {
                continue;
            } else {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            is_possible = true;
            cout << "TAK" << endl;
            for (int j = 0; j < n; j++) {
                cout << (a[j] + i) << " ";
            }
            cout << endl;
            break;
        }
    }
    if (!is_possible) {
        cout << "NIE" << endl;
    }
    return 0;
}