#include <bits/stdc++.h>
using namespace std;

const int N = 10;
const int P = 10;

const int L = 20;
const int C = 1000;

int main()
{
    srand(getpid());
    int n = 1 + rand() % N;
    int p = 1 + rand() % P;
    cout << n << '\n';
    for(int i = 0; i < n; i++)
    {
        int c = 1 + rand() % C;
        int a = 1 + rand() % (L - 1);
        int b = a + 1 + rand() % (L - a);
        cout << c << ' ' << a << ' ' << b << '\n';
    }
    cout << p << '\n';
    for(int i = 0; i < p; i++)
    {
        int m = 1 + rand() % (L);
        int k = 1 + rand() % C;
        int s = rand() % (L - m + 1);
        cout << m << ' ' << k << ' ' << s << '\n';
    }
}