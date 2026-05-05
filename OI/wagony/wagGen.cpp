#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int MAXX = 1000;

int main()
{
    srand(getpid());
    int n = 1 + (rand() % MAXN);
    int d = 1 + (rand() % MAXN);
    int a = 1 + (rand() % MAXX);
    int b = 1 + (rand() % MAXX);
    cout << n << ' ' << d << ' ' << a << ' ' << b;
    
    return 0;
}