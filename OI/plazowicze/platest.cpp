#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, z;
ll X;
int main()
{
    ll x = 0;
    map<long double, int> a;
    for(ll i = 0; i < 1000000; i++)
    {
        if(x + i > 1e9)
        {
            cout << i - 1 << '\n';
            cout << x << '\n';
            break;
        }
        if(i != 0)
            a[i] = 1;
        x += i;
    }

    ll op = 0;
    long double test = 1e9;
    cout << fixed;
    int prevCnt = 1;
    while(test > 0)
    {
        op++;
        auto it = a.rbegin(); //najwiekszy
        long double t = it->first;
        int cnt = it->second;
        if(prevCnt != cnt)
        {
            cout << op << ": " << cnt << " " << a.size() << " " << t << '\n';
        }
        test -= cnt;
        //na dwie czesci
        long double part = t / 2;
        a[part] += 2; 
        a.erase(t);
    }
    

    //cin >> n >> X >> z;
    return 0;
}