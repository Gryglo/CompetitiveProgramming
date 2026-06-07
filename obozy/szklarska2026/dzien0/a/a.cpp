#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
int n, d;
priority_queue<ll> pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> n;
    for(int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        pq.push(-x);
    }
    ll ans = 0;
    while(pq.size() >= 2)
    {
        ll first = -pq.top(); pq.pop();
        ll second = -pq.top(); pq.pop();
        ans += (first + second);
        pq.push(-(first + second));
    }
    cout << ans;
    return 0;
}