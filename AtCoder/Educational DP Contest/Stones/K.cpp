#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
vector<int> a;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}
int32_t main()
{
    init();
    vector<bool> dp(k + 1);
    dp[0] = false;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[j] > i) break;
            if(!dp[i - a[j]])
            {
                dp[i] = true;
                break;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second");
    return 0;
}