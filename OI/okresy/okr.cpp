#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string a;
vector<int> pi;
vector<int> dp;

void KMP()
{
    int pref = 0;
    for(int i = 1; i < n; i++)
    {
        while(pref != 0 && a[pref] != a[i])
            pref = pi[pref - 1];
        if(a[pref] == a[i])
            pref++;
        pi[i] = pref;
    }
}

void init()
{
    pi.resize(n);
    dp.resize(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a;
    init();
    KMP();
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(pi[i] == 0) continue;
        int min_pref = (dp[pi[i] - 1] != 0) ? dp[pi[i] - 1] : pi[i];
        dp[i] = min_pref;
        ans += (i + 1) - min_pref;
    }
    cout << ans;
    return 0;
}