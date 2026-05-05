#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define st first
#define nd second

using ll = long long;
using ld = long double;

int main() {
    int nr, t;
    cin >> nr >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <pair <int, int> > v = {};
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            v.pb({a, b});
        }
        bool czy = 0; 
        for(int i = 1; i <= n; i += max(n / 4, 1)) {
            cout << "? 1 " << i << endl;
            int k;
            cin >> k;
            if(k == 1) {
                cout << "! " << i << endl; 
                czy = 1; 
                break; 
            } 
        }
        if(!czy) {
            cout << "! " << 1 << endl; 
        }
    }
    return 0;
}