#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2002;
const int INF = 1e16;
int n;
vector<int> t;
vector<int> val;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    t.resize(n);
    val.resize(n);
    for(int i = 0; i < n; i++) cin >> t[i] >> val[i];
}
int32_t main()
{
    init();
    //uzycie przedmioty załatwia t[i] przedmioty i dodatkowo ten przedmiot tez
    vector<int> dp(MAXN + 2, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int T = MAXN; T >= 0; T--)
        {
            dp[T] = min(dp[T], dp[T + 1]);
            if(T - (t[i] + 1) >= 0) dp[T] = min(dp[T], dp[T - (t[i] + 1)] + val[i]);
        }
    }
    cout << dp[n];
    return 0;
}