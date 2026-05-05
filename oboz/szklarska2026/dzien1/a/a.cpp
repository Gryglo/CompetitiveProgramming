#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXA = 100000;
struct Square
{
    ll x1, y1, x2, y2;
};

int n;
long double P;
Square target;

vector<Square> rivers;
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    rivers.resize(n);
    for(int i = 0; i < n; i++)
    {
        Square river;
        cin >> river.x1 >> river.y1 >> river.x2 >> river.y2;
        if(river.x1 == river.x2)
        {
            if(river.x2 < river.x1)
            {
                swap(river.x1, river.x2);
                swap(river.y1, river.y2);
            }
        }
        else if(river.y1 == river.y2)
        {
            if(river.y2 < river.y1)
            {
                swap(river.x1, river.x2);
                swap(river.y1, river.y2);
            }
        }
        rivers[i] = river;
    }
    cin >> P;
    P/=100;
    cin >> target.x1 >> target.y1 >> target.x2 >> target.y2;
    ll calePole = (target.x2 - target.x1)* (target.y2 - target.y1);
    
    ll potrzebnePole = calePole * P;

    if(n == 1)
    {
        ll l = 0, r = MAXA;
        int ans = r;
        while(l <= r)
        {
            ll m = (l + r) / 2;
            Square region = rivers[0];
            region.x1 -= m;
            region.y1 -= m;
            region.x2 += m;
            region.y2 += m;
            Square curr;
            curr.x1 = max(target.x1, region.x1);
            curr.y1 = region.y1;
            curr.x2 = min(target.x2, region.x2);
            curr.y2 = region.y2;
            if(curr.x1 >= curr.x2) //nic nie pokrywa
                l = m + 1;
            else
            {
                ll pole = (curr.x2 - curr.x1) * (curr.y2 - curr.y1);
                if(pole >= potrzebnePole)
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
        }
        cout << ans;
    }

    return 0;
}