#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(getpid());
    int n = 1 + rand() % 5;
    int k = 1 + rand() % 10;
    cout << n << ' ' << k << '\n';
    for(int i = 0; i < n; i++) cout << (rand() % (k + 1)) << ' ';
    return 0;
}