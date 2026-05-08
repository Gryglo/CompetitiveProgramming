#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(getpid());
    int n = 1 + rand() % 6;
    cout << n << '\n';
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = i + 1;
    random_shuffle(a.begin(), a.end());
    for(int x : a)
        cout << x << ' ';
    return 0;
}