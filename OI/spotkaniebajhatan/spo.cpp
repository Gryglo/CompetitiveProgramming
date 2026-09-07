#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
using namespace std;
using pii = pair<int, int>;
const int INF = 4e9;
const int MAX_V = 1e9;
int n;
int e[4] = { -INF, INF, -INF, INF };
vector<pii> p;

int p_dist(int x, int y) { return abs(x - y);}
bool valid_point(pii& a){ return (((a.f + a.s) % 2 == 0) && ((a.f - a.s) % 2 == 0)); }
bool check_bit(int& mask, int i) { return (mask & (1 << i)) > 0; }
void rotate_45(pii& a) { a = { a.f + a.s, a.f - a.s }; }
void rotate_45_back(pii& a){ a = { (a.f + a.s) / 2, (a.f - a.s) / 2 }; }

int cnt_mask(int& mask)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        bool added = false;
        for(int j = 0; j < 2; j++)
            if(check_bit(mask, j))
                if(p[i].f == e[j]) {cnt++; added = true; break; }
        if(added) continue;
        for(int j = 2; j < 4; j++)
            if(check_bit(mask, j))
                if(p[i].s == e[j]) {cnt++; break;}
    }
    return cnt;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    p.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i].f >> p[i].s;
    for(int i = 0; i < n; i++) rotate_45(p[i]);
    for(int i = 0; i < n; i++)
    {
        e[0] = max(e[0], p[i].f);
        e[1] = min(e[1], p[i].f);
        e[2] = max(e[2], p[i].s);
        e[3] = min(e[3], p[i].s);
    }
}

int32_t main()
{
    init();
    
    int mid_x = (e[0] + e[1]) / 2;
    int mid_y = (e[2] + e[3]) / 2;
    int m_x_d = p_dist(e[0], mid_x);
    int m_y_d = p_dist(e[2], mid_y); 
    int x_d_1 = p_dist(e[0], -INF);
    int x_d_2 = p_dist(e[1], INF);
    int y_d_1 = p_dist(e[2], -INF);
    int y_d_2 = p_dist(e[3], INF);

    vector<int> possible_x = 
    {INF, -INF, mid_x, e[0] - m_y_d, e[1] + m_y_d, e[0] - y_d_1, e[0] - y_d_2,
        e[1] + y_d_1, e[1] + y_d_2, 0};
    vector<int> possible_y = 
    {INF, -INF, mid_y, e[2] - m_x_d, e[3] + m_x_d, e[2] - x_d_1, e[2] - x_d_2,
        e[3] + x_d_1, e[3] + x_d_2, 0};
    vector<pii> ans(n + 1, {LLONG_MAX, 0});
    for(int x : possible_x)
    {
        for(int y : possible_y)
        {
            for (int dx : {0, 1}) 
            {
                for (int dy : {0, 1}) 
                {
                    pii curr = { x + dx, y + dy };
                    int d = -INF;
                    d = max(d, p_dist(e[0], curr.f));
                    d = max(d, p_dist(e[1], curr.f));
                    d = max(d, p_dist(e[2], curr.s));
                    d = max(d, p_dist(e[3], curr.s));

                    int mask = 0;
                    if(p_dist(e[0], curr.f) == d) mask |= 1;
                    if(p_dist(e[1], curr.f) == d) mask |= 2;
                    if(p_dist(e[2], curr.s) == d) mask |= 4;
                    if(p_dist(e[3], curr.s) == d) mask |= 8;

                    if(!valid_point(curr)) continue;
                    int cnt = cnt_mask(mask);
                    rotate_45_back(curr);
                    ans[cnt] = curr;       
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(ans[i].f == LLONG_MAX) cout << "NIE\n";
        else cout << ans[i].f << ' ' << ans[i].s << '\n';
    }
    return 0;
}