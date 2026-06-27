#include <bits/stdc++.h>
using namespace std;

const int MAXK = 5;
const int MAXD = 10;
const int MAXX = 10;

int main()
{
    srand(getpid());
    int k = 1 + rand() % MAXK;
    int z = 1 + rand() % k;
    int d = 1 + rand() % MAXD;
    cout << k << ' ' << z << ' ' << d << '\n'; 
    vector<int> x;
    for(int i = 0; i < k; i++) x.push_back(rand() % (MAXX + 1));
    sort(x.begin(), x.end());
    for(int i = 0; i < k; i++) cout << x[i] << ' ';
    return 0;
}