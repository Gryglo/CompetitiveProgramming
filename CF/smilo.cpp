#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int l = 0;
    int r = n - 1;
    int combo = 0, moves = 0;
    while(l <= r)
    {
        if(l == r)
        {
            if(a[r] == 1)
            {
                moves++;
                break;
            }
            else if(a[r] == 0)
            {
                break;
            }
            //odrazu uzywamy i konczymy
            int sum = combo + a[r];
            if(sum % 2 == 0)
            {
                /*
                0 8
                1 7 1 
                2 6 2
                3 5 3
                4 4 4
                  0 5
                */
                moves += ((sum / 2) + 1) - combo;
            }
            else
            {
                /*
                0 7
                1 6 1 3
                2 5 2
                3 4 3
                0 1 4
                0 0 5
                */
               moves += ((sum / 2) + 2) - combo;
            }

            break;
        }

        if(combo == a[r])
        {
            moves++;
            combo = 0;
            a[r] = 0;
            r--;
        }
        else if(a[l] + combo < a[r])
        {
            moves += a[l];
            combo += a[l];
            a[l] = 0;
            l++;
        }
        else //>=
        {
            moves += a[r] - combo + 1;
            a[l] -= a[r] - combo;
            combo = 0;
            r--;
        }
        if(a[l] == 0) l++; 
    }
    cout << moves << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}