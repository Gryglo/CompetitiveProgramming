#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5;
const int XRANGE = 10;
int main()
{
    srand(getpid());
    int n = 1 + rand() % MAXN;
    cout << n << '\n';
    for(int i = 0; i < n; i++)
        cout << (rand() % XRANGE - XRANGE / 2) << ' ' << (rand() % XRANGE - XRANGE / 2) << '\n';
}