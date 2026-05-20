#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(getpid());
    int n = 1 + rand() % 100;
    cout << n << '\n';
    for(int i = 0; i < n; i++)
        cout << 1 + rand() % n << ' ';
    return 0;
}