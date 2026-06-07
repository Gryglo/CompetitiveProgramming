#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using square = pair<pii, pii>;

int n; ll k;
vector<vector<int>> ground;
vector<vector<ll>> pref;

vector<int> lowest_block;

bool is_free(int x, int y)
{
    return (ground[x][y] <= 2 * k);
}

ll compute_ground_sum(square& g)
{
    ll sum = pref[g.s.f][g.s.s];
    if(g.f.f > 0) sum -= pref[g.f.f - 1][g.s.s]; //gora
    if(g.f.s > 0) sum -= pref[g.s.f][g.f.s - 1]; //lewo
    if(g.f.f > 0 && g.f.s > 0) sum += pref[g.f.f - 1][g.f.s - 1]; //lewy gorny rog
    return sum;
}

bool is_ground_valid(square& g)
{
    return (compute_ground_sum(g) >= k); 
}

square find_area()
{
    for(int x = 0; x < n; x++)
    {
        stack<pii> left_c;
        for(int y = 0; y < n; y++)
        {
            if(!is_free(x, y))
            {
                lowest_block[y] = x;
                while (!left_c.empty())
                {
                    pii curr = left_c.top();
                    left_c.pop();
                    square area = {curr, {x, y - 1}};
                    if(is_ground_valid(area))
                        return area;
                }
                continue;
            }
            int last_c_x = (left_c.empty()) ? x + 1 : left_c.top().f;
            if(lowest_block[y] + 1 < last_c_x)
            {
                left_c.push({lowest_block[y] + 1, y});
                continue;
            }
            int min_y = n + 1;
            while(!left_c.empty() && left_c.top().f <= lowest_block[y])
            {
                pii curr = left_c.top();
                left_c.pop();
                square area = {curr, {x, y - 1}};
                if(is_ground_valid(area))
                    return area;
                min_y = min(min_y, curr.s);
            }
            if(min_y < n + 1)
                if(left_c.empty() || lowest_block[y] + 1 < left_c.top().f)
                    left_c.push({lowest_block[y] + 1, min_y});
        }
        while (!left_c.empty())
        {
            pii curr = left_c.top();
            left_c.pop();
            square area = {curr, {x, n - 1}};
            if(is_ground_valid(area))
                return area;
        }
    }
    return {{-1, -1}, {-1, -1}};
}

square find_answear(square area)
{
    ll sum = compute_ground_sum(area);
    if(sum >= k && sum <= 2 * k) return area;
    if(sum < k) return {{-1, -1}, {-1, -1}};
    square a1, a2;
    if(area.s.f - area.f.f >= area.s.s - area.f.s)
    {
        int m_x = (area.s.f + area.f.f) / 2;
        a1 = find_answear({area.f, {m_x, area.s.s}});
        a2 = find_answear({{m_x + 1, area.f.s}, area.s});
    }
    else
    {
        int m_y = (area.s.s + area.f.s) / 2;
        a1 = find_answear({area.f, {area.s.f, m_y}});
        a2 = find_answear({{area.f.f, m_y + 1}, area.s});
    }
    if(a1.f.f != -1) return a1;
    return a2;
}

void init()
{
    cin >> k >> n;
    ground.resize(n, vector<int>(n));
    pref.resize(n, vector<ll>(n));
    lowest_block.resize(n, -1);
    for(int x = 0; x < n; x++) 
    for(int y = 0; y < n; y++) 
    {
        cin >> ground[x][y];
        ll sum = ground[x][y];
        if(x > 0) sum += pref[x - 1][y];
        if(y > 0) sum += pref[x][y - 1];
        if(x > 0 && y > 0) sum -= pref[x - 1][y - 1];
        pref[x][y] = sum;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    square target_area = find_area();
    if(target_area.f.f == -1)
    {
        cout << "NIE";
        return 0;
    }
    square ans = find_answear(target_area);
    cout << ans.f.s + 1 << ' ' << ans.f.f + 1 << ' ' << ans.s.s + 1 << ' ' << ans.s.f + 1;
    return 0;
}