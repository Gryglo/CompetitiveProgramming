#include <bits/stdc++.h>
using namespace std;

const int MAXX = 20;
const int MAXQ = 10;

int main()
{
    srand(getpid());
    int n = 1 + rand() % 6;
    int m = 1 + rand() % 6;
    n = 4;
    m = 4;
    cout << n << ' ' << m << '\n';
    for(int i = 0; i < m; i++)
    {
        cout << (1 + rand() % n) << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++) cout << (1 + rand() % MAXX) << ' ';
    cout << '\n';

    int q = 3;
    cout << q << '\n';
    for(int i = 0; i < q; i++)
    {
        int l = 1 + rand() % m;
        int r = 1 + rand() % m;
        int x = 1 + rand() % MAXQ;
        cout << l << ' ' << r << ' ' << x << '\n';
    }
}