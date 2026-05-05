#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define st first
#define nd second

using ll = long long;
using ld = long double;

int main() {
    for(int i = 1; i <= 2; i++) {
        cout << "? 1 " << i << endl; 
        int x;
        cin >> x;
        if(x == 0) {
            cout << "! " << i << endl;
            return 0;
        } 
    }
    cout << "! " << 69 << endl; 

    return 0;
}