#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
int n, d;
vector<ll> ciag;

ll ans = 0;
vector<ll> mem;
ll subtask3func(int x)
{
    if(x <= 1)
        return 0;
    if(mem[x] != -1)
        return mem[x];
    int h1 = x / 2;
    int h2 = x - h1;
    ll curr = ciag[0] * x + subtask3func(h1) + subtask3func(h2);
    mem[x] = curr;
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> n;
    ciag.resize(n);
    mem.resize(n + 1, -1);
    int prev = 0;
    bool subtask3 = true;
    for(int i = 0; i < n; i++)
    {
        cin >> ciag[i];
        if(i > 0)
            if(ciag[i] != prev)
                subtask3 = false;
        prev = ciag[i];
    }   
    if(subtask3)
    {
        cout << subtask3func(n);
        return 0;
    }
    return 0;
}