#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(getpid());
    cout << 1 << '\n';
    int n = 5;
    cout << n << '\n';
    vector<bool> alrd(101);
    for(int i = 0; i < n; i++)
    {
        int curr = 1 + rand() % 100;
        while(alrd[curr]) curr = 1 + rand() % 100;
        alrd[curr] = true;
        cout << curr << ' ';
    }
    return 0;
}