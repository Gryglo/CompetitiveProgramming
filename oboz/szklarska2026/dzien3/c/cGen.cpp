#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(getpid());
    int n = 1 + rand() % 6;
    int a = 1 + rand() % 100;
    int b = 1 + rand() % 100;
    if(a == b) b++;
    if(a > b) swap(a, b);
    cout << n << ' ' << a << ' ' << b << '\n';
    vector<vector<bool>> matrix(n, vector<bool>(n));
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < )   
        {

        }
    }
    return 0;
}