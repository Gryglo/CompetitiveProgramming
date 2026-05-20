#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 200000;
    long long a = 0;
    for(int i = 1; i <= n; i++)
    {
        cout << n/i << '\n';
        a += n/i;
    }
    cout << a;
    return 0;
}