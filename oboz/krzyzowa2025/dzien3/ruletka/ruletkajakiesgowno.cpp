#include <bits/stdc++.h>
using namespace std;

int d;
int main()
{
    //cout << 1 << " " << 1 + 64 << " " << 1 + 64 + 64 << " " << 1 + 64 * 3;
    vector<int> v = {1, 65, 129, 193};
    cout << "? 4 1 65 129 193" << endl;
    cin >> d;

    for(int i = 0; i < 3; i++)
    {
        cout << "? 1 " << v[i] << endl;
        int currD; cin >> currD;
        if(currD == d)
        {
            cout << "? 1 " << ((v[i] + d) % 256) << endl;
            int d2; cin >> d2;
            if(d2 == 0)
                cout << "! " << ((v[i] + d) % 256) << endl;
            else
                cout << "! " << ((v[i] - d) % 256) << endl;
            return 0;
        }
    }
    cout << "? 1 " << ((193 + d) % 256) << endl;
    int d2; cin >> d2;
    if(d2 == 0)
        cout << "! " << ((193 + d) % 256) << endl;
    else
        cout << "! " << ((193 - d) % 256) << endl;
    
    return 0;
}