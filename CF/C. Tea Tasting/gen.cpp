#include <bits/stdc++.h>
using namespace std;

const int MAXX = 10;

int main()
{
    srand(getpid());
    cout << "1\n";
    int n = 1 + rand() % 5;
    cout << n << '\n';
    for(int i = 0; i < n; i++) cout << (1 + rand() % MAXX) << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) cout << (1 + rand() % MAXX) << ' ';
    return 0;
}