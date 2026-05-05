#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;

const int N = 1000;
const ll K = 100000;
//const ll K = 1000;
int main()
{
    srand(getpid());
    int n = 1 + (rand() % N);
    int k = 1 + (rand() % K);
    cout << n << ' ' << k << '\n';
    vector<int> ciag(n);
    for(int i = 0; i < n; i++)
        ciag[i] = i + 1;
    random_shuffle(ciag.begin(), ciag.end());
    for(int i = 0; i < n; i++)
        cout << ciag[i] << '\n';
    return 0;
}