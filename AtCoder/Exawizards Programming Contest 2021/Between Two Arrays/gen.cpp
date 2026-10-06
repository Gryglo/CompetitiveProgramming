#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(getpid());
    int n = 1 + rand() % 5;
    cout << n << '\n';
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    { 
        a[i] = rand() % 5;
        cout << a[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << (a[i] + (rand() % 5)) << ' ';
    }
    return 0;
}