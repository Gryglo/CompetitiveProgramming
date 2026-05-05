#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q;
vector<int> ciag;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ciag.resize(n);
    for(int i = 0; i < n; i++)
        cin >> ciag[i];

    while(q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        a--; b--;
        if(type == 2)
        {
            //query 
            int sum = 0;
            for(int i = a; i <= b; i++)
                sum += ciag[i];
            cout << sum << '\n';
        }
        else
        {
            //update
            int x = 1;
            for(int i = a; i <= b; i++)
            {
                ciag[i] += x;
                x++;
            }
        }
    }
    return 0;
}