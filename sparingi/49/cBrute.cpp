#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll k;

bool canWin = true;
//turn = true -> my; false przeciwnik
void solve(int val, int lastMove, bool turn)
{
    if(val == 0 && !turn)
        canWin = false;
    for(int i = 1; i <= lastMove; i++)
    {
        if(val - i < 0)
            break;
        solve(val - i, i, !turn);
    }
}


int main()
{
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(n == 1)
    {
        vector<ll> dp(arr[0] + 5);
    }
    cout << canWin;
    return 0;
}