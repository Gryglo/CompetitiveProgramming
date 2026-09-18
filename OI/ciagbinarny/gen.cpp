#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10; 
const int MAXM = 20;
const int MAXX = 3;
const int MAXK = 10;
int main()
{   
    srand(getpid());
    int n = 1 + rand() % MAXN;
    int m = 1 + rand() % MAXM;
    m = 1;
    cout << n << ' ' << m << '\n';
    int sum = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = 1 + rand() % MAXX;
        sum += a[i];
    }
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
    for(int i = 0; i < m; i++)
    {
        int l = 1 + rand() % sum;
        int r = 1 + rand() % sum;
        int k = 1 + rand() % MAXK;
        cout << min(l, r) << ' ' << max(l, r) << ' ' << k << '\n';
    }
    return 0;
}