#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;

const int N = 10;
const ll K = 1000;
const ll H = 1000;
//const ll K = 1000;
int main()
{
    srand(getpid());
    int n = 1 + (rand() % N);
    int k = 1005;
    cout << n << ' ' << k << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << (rand() % H) << ' ';
    }
    return 0;
}