#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m;

ll min_len_p = LLONG_MAX;
ll min_hole_p = -1;
ll min_i_p = -1;

ll min_len_l = LLONG_MAX;
ll min_hole_l = -1;
ll min_i_l = -1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    /* 
    testujemy wszystkie liczby od 1 do m lub n w zaleznosci co dodajemy
    dla P to max m-1 i dla D to max do n-1

    PO ILU SIE ZACYKLA M? lcm(m/gcd, p/gcd)
    PO ILU SIĘ ZACYKLA N?
    PO ILU SIE ZACYKLA WSZYSTKO?
    
    
    6xP 16 = 8

    */


    //DLA ixP (1, i)
    for(ll i = 1; i <= m - 1; i++)
    {
        ll curr_len = i + 1;
        ll gcd_m_i = gcd(m, i);
        ll cycle_m = m/gcd_m_i;
        ll cycle_n = n;
        ll whole_cycle = lcm(cycle_n, cycle_m);
        ll segments = whole_cycle / n;
        ll hole = (m - ((i + 1) * segments)) / segments;
        if(hole > 0)
            curr_len += hole * 2;// PPLL
        if(curr_len < min_len_p)
        {
            min_len_p = curr_len;
            min_i_p = i;
            min_hole_p = hole;
        }
    }
    for(ll i = 1; i <= n - 1; i++)
    {
        ll curr_len = i + 1;
        ll gcd_n_i = gcd(n, i);
        ll cycle_n = n/gcd_n_i;
        ll cycle_m = m;
        ll whole_cycle = lcm(cycle_n, cycle_m);
        ll segments = whole_cycle / m;
        ll hole = (n - ((i + 1) * segments)) / segments;
        if(hole > 0)
            curr_len += hole * 2;// DDGG
        if(curr_len < min_len_l)
        {
            min_len_l = curr_len;
            min_i_l = i;
            min_hole_l = hole;
        }
    }
    if(min_len_p <= min_len_l)
    {
        cout << min_len_p << '\n';
        string ans;
        for(int x = 0; x < min_i_p; x++)
            ans += 'P';
        for(int x = 0; x < min_hole_p; x++)
            ans += 'P';
        for(int x = 0; x < min_hole_p; x++)
            ans += 'L';
        ans += 'D';
        cout << ans;
    }
    else
    {
        cout << min_len_l << '\n';
        string ans;
        for(int x = 0; x < min_i_l; x++)
            ans += 'D';
        for(int x = 0; x < min_hole_l; x++)
            ans += 'D';
        for(int x = 0; x < min_hole_l; x++)
            ans += 'G';
        ans += 'P';
        cout << ans;
    }
    return 0;
}