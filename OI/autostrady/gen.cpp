#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;
const int MAXK = 5;

int main()
{
    srand(getpid());
    int n = 2 + (rand() % MAXN);
    int k = 1 + (rand() % MAXK);
    cout << n << ' ' << k << '\n';
    for(int i = 0; i < k; i++)
    {
        int a = 1 + (rand() % (n - 1));
        int b = a + 1 + (rand() % (n - a));
        cout << a << ' ' << b << '\n';
    }
}