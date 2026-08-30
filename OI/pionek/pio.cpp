// Task: Pionek
// Score: 100
// https://szkopul.edu.pl/problemset/problem/NZSCUwz2ACePsBKuVCIVzrRt/site/?key=statement
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int n;
vector<pii> moves;

// < 0 => b na prawo, > 0 => b na lewo, = 0 => wspoliniowe
ll det(const pii& a, const pii& b) { return (a.f * b.s - b.f * a.s); }
ll dot(const pii& a, const pii& b) { return (a.f * b.f + a.s * b.s); }

int half(const pii& a) 
{
    if (a.s >= 0) return 0; 
    return 1;
}

bool compare_vec(const pii& a, const pii& b)
{
    int h1 = half(a), h2 = half(b);
    if(h1 != h2) return h1 < h2;
    ll res = det(a, b);
    if(res == 0) return a.f < b.f;
    return res < 0;
}

ll move_dist(pii x) { return {x.f * x.f + x.s * x.s}; }
pii add_vec(pii& a, pii b) { return {a.f + b.f, a.s + b.s}; }
pii sub_vec(pii& a, pii b) { return {a.f - b.f, a.s - b.s}; }

void add_move(pii& a, pii b, ll& sum) { a = add_vec(a, b); sum = move_dist(a); }
void rem_move(pii& a, pii b, ll& sum) { a = sub_vec(a, b); sum = move_dist(a); }

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        ll x, y; cin >> x >> y;
        if(x == 0 && y == 0) continue; 
        moves.push_back({x, y});
    }
    n = moves.size();
    if(n == 0) return;
    sort(moves.begin(), moves.end(), compare_vec);
    moves.resize(2 * n);
    for(int i = 0; i < n; i++) moves[i + n] = moves[i];
}

int main()
{
    init();
    if(n == 0) { cout << 0 << "\n"; return 0; }
    int l = 0, r = 0;
    pii curr = {0, 0};
    ll curr_dist = 0, ans = 0;
    while(r < 2 * n)
    {
        add_move(curr, moves[r], curr_dist);
        ans = max(curr_dist, ans);
        while((r - l + 1 == n) || (l < r && move_dist(sub_vec(curr, moves[l])) >= curr_dist))
        {
            rem_move(curr, moves[l], curr_dist);
            ans = max(curr_dist, ans);
            l++;
        }
        r++;
    }
    while(l < r)
    {
        rem_move(curr, moves[l], curr_dist);
        ans = max(curr_dist, ans);
        l++;
    }
    cout << ans;
    //cout << "VALID";
    return 0;
}