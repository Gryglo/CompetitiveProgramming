#include <bits/stdc++.h>
using namespace std;

const int MAXX = 100;

int main()
{
    srand(getpid());
    int n = 1;
    cout << n << '\n';
    int f = 1 + rand() % MAXX;
    int s = f + rand() % MAXX;
    cout << f << ' ' << s << ' ';
    f = 1 + rand() % MAXX;
    s = f + rand() % MAXX;
    cout << f << ' ' << s << ' ';
    return 0;
}