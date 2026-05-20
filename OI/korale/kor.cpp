#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll POW = 200003;
//const ll POW2 = 200007; jakby byl potrzebny drugi hash

int n;
vector<ll> a;
vector<ll> h1, h2;
vector<ll> P;

void computePowers()
{
    P.resize(n);
    P[0] = 1;
    for(int i = 1; i < n; i++)
        P[i] = (P[i - 1] * POW) % MOD;
}

void computeHash()
{
    computePowers();
    h1.resize(n);
    h1[0] = a[0];
    for(int i = 1; i < n; i++) 
        h1[i] = (h1[i - 1] + (a[i] * P[i]) % MOD) % MOD;
    h2.resize(n);
    h2[0] = a[n - 1];
    for(int i = 1; i < n; i++)
        h2[i] = (h2[i - 1] + (a[n - 1 - i] * P[i]) % MOD) % MOD;	
}

ll getHashOnSegment(int l, int r, vector<ll>& curr_h)
{
    int diff = (n - 1) - r; 
    ll prev = (l > 0) ? curr_h[l - 1] : 0;
    ll curr = (curr_h[r] + MOD - prev) % MOD;
    curr = (curr * P[diff]) % MOD;
    return curr;
}

ll getHash(int i, int k)
{
    // 0 1 2 3 4 5 6 7 8 9
    // . . .         x x x
    int r = i + (k - 1);
    int l = i;
    return getHashOnSegment(l, r, h1);
}

ll getHashRev(int i, int k)
{
    //   x x x
    // 9 8 7 6 5 4 3 2 1 0
    // 0 1 2 3 4 5 6 7 8 9
    //             x x x
    int r = (n - 1) - i;
    int l = r - (k - 1);
    return getHashOnSegment(l, r, h2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    computeHash();
    vector<vector<int>> ans(n + 1);
    int max_w = 0;
    for(int k = 1; k <= n; k++)
    {
        unordered_map<ll, bool> prev_h;
        int cnt_w = 0;
        for(int i = 0; i + (k - 1) < n; i += k)
        {
            ll curr_h = getHash(i, k);
            ll curr_h_rev = getHashRev(i, k);
            if(prev_h.find(curr_h) != prev_h.end() || 
            prev_h.find(curr_h_rev) != prev_h.end())
                continue;
            cnt_w++;
            prev_h[curr_h] = true;
        }
        max_w = max(max_w, cnt_w);
        ans[cnt_w].push_back(k);
    }
    cout << max_w << ' ' << ans[max_w].size() << '\n';
    for(int x : ans[max_w])
        cout << x << ' ';
    return 0;
}