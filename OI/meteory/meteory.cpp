#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

/* 
n panstw
m stacji
k zapytan
*/

int n, m, k;
vector<vector<int>> countryIdxs; //n
vector<int> need; //n
vector<pair<pair<int, int>, int>> q; //k

vector<int> L;//n
vector<int> R;//n
vector<vector<int>> segments; //k - countryI
//vector<vector<BinSegment>> segments; //k
vector<int> ans; //n

int M;
vector<ll> t;
void update(int l, int r, const int& x)
{
    int vl = l + M;  
    int vr = r + M;
    t[vl] += x;
    if(vl == vr) return;
    t[vr] += x;
    while(vl/2 != vr/2)
    {
        if(vl % 2 == 0)
            t[vl + 1] += x;
        if(vr % 2 == 1)
            t[vr - 1] += x;
        vl/=2;
        vr/=2;
    }
}

ll query(const int& i)
{
    int v = i + M;
    ll sum = 0;
    while(v > 0)
    {
        sum += t[v];
        v/=2;
    }
    return sum;
}

bool isCountryHappy(const int& country)
{
    ll sum = 0;
    for(const int& currI : countryIdxs[country])
    {
        sum += query(currI);
        if(sum >= need[country]) return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    M = 1;
    while(M < m) M = M << 1;
    countryIdxs.resize(n);
    need.resize(n);
    for(int i = 0; i < m; i++)
    {
        int x; cin >> x; x--;
        countryIdxs[x].push_back(i);
    }
    for(int i = 0; i < n; i++)
        cin >> need[i];
    
    cin >> k;
    q.resize(k);
    for(int i = 0; i < k; i++)
    {
        cin >> q[i].f.f >> q[i].f.s >> q[i].s;
        q[i].f.f--; q[i].f.s--;
    }
    segments.resize(k);
    L.resize(n);
    R.resize(n);
    for(int i = 0; i < n; i++)
    {
        L[i] = 0; R[i] = k - 1;
        segments[(k - 1) / 2].push_back(i);
    }
    
    ans.resize(n, -1);
    int finished = 0;
    while(finished < n)
    {
        t.assign(2 * M, 0);
        for(int i = 0; i < k; i++)
        {
            //kolejne przedzialy
            if(q[i].f.f > q[i].f.s)
            {
                update(q[i].f.f, m - 1, q[i].s);
                update(0, q[i].f.s, q[i].s);
            }
            else
                update(q[i].f.f, q[i].f.s, q[i].s);
            
            while(segments[i].size() > 0)
            {
                int countryI = segments[i].back();
                segments[i].pop_back();
                //mid = i
                if(isCountryHappy(countryI))
                {
                    ans[countryI] = i;
                    R[countryI] = i - 1;
                }
                else
                    L[countryI] = i + 1;
                if(L[countryI] > R[countryI])
                {
                    finished++;
                    continue;
                }

                segments[(L[countryI] + R[countryI]) / 2].push_back(countryI);
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(ans[i] == -1) cout << "NIE\n";
        else cout << ans[i] + 1 << '\n';
    }
    //[0, k - 1]
    return 0;
}