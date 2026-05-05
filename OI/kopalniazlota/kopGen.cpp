#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(getpid());
    int s = 1 + rand() % 10;
    int w = 1 + rand() % 10;
    cout << s << ' ' << w << '\n';
    //10 10
    int n = 1 + rand() % 1000;
    cout << n << '\n';
    for(int i = 0; i < n; i++)
        cout << rand() % 11 << " " << rand() % 11 << '\n';
}