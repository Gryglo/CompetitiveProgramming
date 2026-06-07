/* 
    -=-=-=-=-=-=-
    TASK: SZATNIA
    SCORE: 100
    LINK: https://szkopul.edu.pl/problemset/problem/E_UP8if3dQ6IUlFNsD1CQOdy/site/?key=statement
    -=-=-=-=-=-=-
*/
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using event = pair<pii, int>;

const int KMAX = 100'000;
const int INF = INT_MAX;

int n, p;
vector<int> plan_c;
vector<int> plan_end;
vector<int> item_c;
vector<int> item_end;
vector<bool> ans;
vector<event> events; //(pos, typ, idx)
vector<int> dp(KMAX + 2);

void add_item(int x, int b)
{
    for(int i = KMAX; i >= x; i--)
        dp[i] = max(dp[i], min(dp[i - x], b));
}

void init()
{
    cin >> n;
    item_c.resize(n);
    item_end.resize(n);
    for(int i = 0; i < n; i++)
    {
        int c, a, b; cin >> c >> a >> b;
        item_c[i] = c;
        item_end[i] = b;
        events.push_back({{a, 0}, i});
    }
    cin >> p;
    plan_end.resize(p);
    plan_c.resize(p);
    for(int i = 0; i < p; i++)
    {
        int m, k, s; cin >> m >> k >> s;
        plan_c[i] = k;
        plan_end[i] = m + s;
        events.push_back({{m, 1}, i});
    }
    dp[0] = INF;
    ans.resize(p);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    sort(events.begin(), events.end());
    for(event& e : events)
    {   
        if(e.f.s == 0) add_item(item_c[e.s], item_end[e.s]);
        else ans[e.s] = (dp[plan_c[e.s]] > plan_end[e.s]);
    }
    for(int i = 0; i < p; i++) cout << ((ans[i]) ? "TAK\n" : "NIE\n");
    return 0;
}