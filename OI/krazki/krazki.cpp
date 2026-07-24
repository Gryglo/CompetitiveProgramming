#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = LLONG_MAX;

int n, m;
vector<int> rurka;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; 
    rurka.resize(n);
    int currMin = INF;
    for(int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        currMin = min(curr, currMin);
        rurka[i] = currMin;
    }

    int prev = n - 1;
    for(int i = 0; i < m; i++)
    {
        if(prev < 0)
        {
            cout << '0';
            return 0;
        }
        int curr;
        cin >> curr;

        for(;prev >= 0; prev--)
        {
            if(rurka[prev] >= curr)
            {
                prev--;
                break;
            }
        }
    }
    cout << prev + 2;
    return 0;
}