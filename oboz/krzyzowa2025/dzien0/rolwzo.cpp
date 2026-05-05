#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
const ll INF = LLONG_MAX;

ll n, m;
vector<ll> a;

int checkX(ll x)
{
    ll cnt = 0;
    vector<ll> t(a);
    for(int i = 1; i < n; i++)
    {
        if(t[i] - t[i - 1] > x)
        {
            ll dec = t[i] - t[i - 1] - x;
            cnt += dec;
            t[i] = t[i] - dec;
        }
        if(cnt > m)
            return -1;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(t[i] - t[i + 1] > x)
        {
            ll dec = t[i] - t[i + 1] - x;
            cnt += dec;
            t[i] = t[i] - dec;
        }
        if(cnt > m)
            return -1;
    }

    if(x == 0)
    {
        ll toRem = 0;
        for(int i = 0; i < n; i++)
            toRem += t[i];
        if(m - cnt - toRem >= 0)
            return 0;
        else
            return -1;
    }

    //wyrownany teren
    vector<ll> A(n);
    vector<ll> B(n);
    
    //x to jest nasze b
    for(int i = 0; i < n; i++)
    {
        //t[i]
        ll sT = 0;
        sT = (t[i] - 1) / x;
        ll l = max(0LL, i - sT);
        //a + b*x
        ll currA = t[i] - (i - l) * x;
        A[l] += (currA - x * l);
        B[l] += x;
        if(i + 1 < n)
        {
            A[i + 1] -= (currA - x * l);
            B[i + 1] -= x;

            currA = t[i] - x;
            A[i + 1] += (currA + x*(i + 1));
            B[i + 1] += -x;
            int r = i + sT;
            if(r + 1 < n)
            {
                A[r + 1] -= (currA + x*(i + 1));
                B[r + 1] -= -x;
            }
        }
    }

    vector<ll> prefA(n);
    vector<ll> prefB(n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            prefA[i] = A[0];
            prefB[i] = B[0];
        }
        else
        {
            prefA[i] = prefA[i - 1] + A[i];
            prefB[i] = prefB[i - 1] + B[i];
        }
    }
    ll minRem = INF;
    int mini = -1;
    for(int i = 0; i < n; i++)
    {
        if(prefA[i] + prefB[i] * i < minRem)
        {
            minRem = prefA[i] + prefB[i] * i;
            mini = i;
        }
    }
    if(m - cnt - minRem >= 0)
        return mini;
    else
        return -1;
}

int main()
{
    fastio;
    cin >> n >> m;
    ll maxH = 0;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxH = max(maxH, a[i]);
    }
    if(n == 1)
    {
        cout << 1 << " " << a[0];
        return 0;
    }
    /* 
3 2000
1000 1 1000
    */
    ll l = 0, r = maxH;
    int mini;
    while(l < r)
    {
        ll m = (l + r) / 2;
        mini = checkX(m);
        if(mini != -1)
            r = m;
        else
            l = m + 1;
    }
    mini = checkX(l);
    cout << mini + 1 << " " << l;
    return 0; 
}