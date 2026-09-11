#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int n;
vector<vector<int>> points;

int solve()
{
    n = points.size();
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        pii m_v = {abs(points[i + 1][0] - points[i][0]), abs(points[i + 1][1] - points[i][1])};
        ans += (min(m_v.f, m_v.s) + (max(m_v.f, m_v.s) - min(m_v.f, m_v.s)));
    }
    return ans;
}

void init()
{
    cin >> n;
    points.resize(n, vector<int>(2));
    for(int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
}

int32_t main()
{
    init();
    cout << solve();
    return 0;
}