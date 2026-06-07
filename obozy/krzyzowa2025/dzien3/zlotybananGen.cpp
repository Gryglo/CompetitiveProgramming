#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 10;
const int MAXD = 10;
const int MAXVAL = 10;
int main()
{
    fastio;
    srand(getpid());
    int n = 1 + (rand() % (MAXN));
    n = 4;
    int d = 1 + (rand() % (MAXD));
    cout << n << " " << d << '\n';
    for(int i = 0; i < n; i++)
        cout << (1 + (rand() % (MAXVAL))) << ' ';
    
    return 0;
}