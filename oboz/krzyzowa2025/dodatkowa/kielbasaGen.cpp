#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXH = 10;
int main()
{
    srand(getpid());
    int n = 10;
    cout << n << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << 1 + (rand() % (MAXH - 1)) << ' ';
    }
    return 0;
}