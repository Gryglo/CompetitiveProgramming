#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, p, d;
//2^21 2097152
ll t[(2097152 + 5) * 2];
ll a[2000000 + 5];

ll N = 1;

void update(int i, ll x)
{
    int v = N + i;
    t[v] = x;
    v/=2;
    while(v > 0)
    {
        t[v] = max(t[2 * v], t[2 * v + 1]);
        v/=2;
    }
}

ll query(int l, int r)
{
    int v1 = N + l;
    int v2 = N + r;
    ll w = max(t[v1], t[v2]);
    while(v1/2 != v2/2)
    {
        if(v1 % 2 == 0)
            w = max(w, t[v1 + 1]);
        if(v2 % 2 == 1)
            w = max(w, t[v2 - 1]);
        v1/=2; v2/=2;
    }
    return w;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> d;
    while(N < n)
        N = N << 1;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = 0, r = 0;
    ll sum = a[0];
    while (r + 1 < d){
        r++; sum += a[r];
    }
    //cout << sum;
    t[N] = sum;
    while(r < n - 1)
    {
        sum -= a[l];
        l++; r++;
        sum += a[r];
        update(l, sum);
    }
    /* for(int i = N; i < N + n; i++)
    {
        cout << t[i] << ' ';
    }
    cout << '\n';
    cout << query(0, 1) << " " << query(5, n - 1) 
    << " " << query(2, n - 2) << " " << query(3, 5) << " "; */
    
    int ans = d;
    l = 0, r = d - 1; // 0 1 2 3 4 5 6 7    5
    sum = t[N];

    while(l + (d - 1) <= r && r < n)
    {
        ll seg_sum = sum - query(l, r - (d - 1));
        if(seg_sum <= p)
        {
            ans = max(ans, r - l + 1);
            r++;
            sum += a[r];
        }
        else
        {
            sum -= a[l];
            l++;
        }
    }
    cout << ans;
    return 0;
}