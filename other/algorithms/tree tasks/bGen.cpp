#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10, MAXQ = 4, MAXX = 20;
int main()
{
    srand(getpid());
    int n = 4 + (rand() % MAXN);
    int q = 1 + (rand() % MAXQ);
    q = 5;
    cout << n << " " << q << '\n';
    for(int i = 0; i < n; i++)
        cout << 1 + (rand() % MAXX) << " ";
    cout << '\n';
    for(int i = 0; i < q - 1; i++)
    {
        cout << 1 + (rand() % 2) << ' ';
        int a = 1 + (rand() % n);
        int b = a + (rand() % (n - a + 1));
        cout << a << ' ' << b << '\n';
    }
    cout << 2 << ' ' <<  1 << ' ' << n << '\n';
    return 0;
}