#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const int MAXN = 100'005;

int n;
ll k;
vector<int> pos(MAXN);
int32_t main()
{
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        pos[x] = i;
    }
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    vector<int> fails(n);
    int cycleSum = 0;
    //pos[1] = ans
    int prevIdx = pos[1];
    for(int i = 2; i <= n; i++)
    {
        int currDiff;
        if(pos[i] > pos[i - 1])
            currDiff = pos[i] - pos[i - 1];
        else
            currDiff = n - pos[i - 1] + pos[i];
        cycleSum += currDiff;
        if(i > 2)
            fails[i - 2] = fails[i - 3] + currDiff;
        else
            fails[0] = currDiff;
    }
    int currDiff;
    if(pos[1] > pos[n])
        currDiff = pos[1] - pos[n];
    else
        currDiff = n - pos[n] + pos[1];
    cycleSum += currDiff;
    fails[n - 1] = fails[n - 2] + currDiff;

    ll ans = 0;
    ans += pos[1];
    k--;
    ll cycleCnt = k / n;
    ll rest = k % n;
    ans += cycleCnt * cycleSum;
    if(rest > 0)
        ans += fails[rest - 1];
    cout << ans;
    return 0;
}