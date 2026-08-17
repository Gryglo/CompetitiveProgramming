#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    ll S_max = 0, cnt_max = 0;
    for(ll S = 2; S <= 10000000; S++)
    {
        int cnt = 0;
        for(ll i = 2; i * i <= S; i++) if(S % i == 0) cnt += 2;
        if(cnt > cnt_max)
        {
            S_max = S; cnt_max = cnt;
        }
    }
    cout << S_max << ' ' << cnt_max;
    return 0;
}