#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Square
{
    vector<pii> p;
    Square()
    {
        p.resize(2);
    }
};
struct Event
{
    int y, x, add, d;
    Event(int y, int x, int add, int d)
    {
        this->y = y;
        this->x = x;
        this->add = add;
        this->d = d;
    }
};

const ll MAX_A = 100'005;

int n;
ll P;
Square target;
vector<Square> rivers;
ll squareLen;

vector<pii> t;  //{minimum, min_cnt}
vector<int> lazy;

bool increaseSize(int x, vector<pii>& p)
{
    p[0].f -= x;
    p[0].s -= x;
    p[1].f += x;
    p[1].s += x;
    
    p[0].f = max(p[0].f, target.p[0].f); //obcinanie lewego boku
    p[0].s = max(p[0].s, target.p[0].s); //obcinanie dolu
    p[1].f = max(p[1].f, target.p[0].f); //obcinanie lewego boku
    p[1].s = max(p[1].s, target.p[0].s); //obcinanie dolu

    p[0].f = min(p[0].f, target.p[1].f); //obcinanie lewego boku
    p[0].s = min(p[0].s, target.p[1].s); //obcinanie dolu
    p[1].f = min(p[1].f, target.p[1].f); //obcinanie lewego boku
    p[1].s = min(p[1].s, target.p[1].s); //obcinanie dolu

    if (p[0].f == p[1].f || p[0].s == p[1].s)
        return false;
    return true;
}

void build(int v, int l, int r)
{
    if(l == r)
        t[v] = {0, 1};
    else
    {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = {0, t[2 * v].s + t[2 * v + 1].s};
    }
}

void init()
{
    t.assign(4 * MAX_A, {0, 0});
    lazy.assign(4 * MAX_A, 0);
    build(1, 0, MAX_A - 1);
}


void refresh(int v)
{
    //2 * v, 2 * v + 1
    if(t[2 * v].f < t[2 * v + 1].f)
        t[v] = {t[2 * v].f, t[2 * v].s};
    else if(t[2 * v].f > t[2 * v + 1].f)
        t[v] = {t[2 * v + 1].f, t[2 * v + 1].s};
    else
        t[v] = {t[2 * v].f, t[2 * v].s + t[2 * v + 1].s};
}

void push(int v, int l, int r)
{
    if(lazy[v] == 0) return;
    t[v].f += lazy[v];
    if(l != r)
    {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }   
    lazy[v] = 0;
}

void update(int v, int l, int r, int tl, int tr, int x)
{
    push(v, l, r);
    if(l > r || l > tr || r < tl) return;
    if(tl <= l && r <= tr)
    {
        lazy[v] += x;
        push(v, l, r);
    }
    else
    {
        int m = (l + r) / 2;
        update(2 * v, l, m, tl, tr, x);
        update(2 * v + 1, m + 1, r, tl, tr, x);
        refresh(v);
    }
}

void update(int l, int r, int x)
{
    update(1, 0, MAX_A - 1, l, r, x);
}


bool sortEvents(Event& a, Event& b)
{
    if(a.y == b.y) 
    {
        if(a.x == b.x)
            return a.add > b.add;
        else
            return a.x < b.x;
    }
    else
        return a.y < b.y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rivers.resize(n);
    for(int i = 0; i < n; i++)
    {
        Square river;
        cin >> river.p[0].f >> river.p[0].s >> river.p[1].f >> river.p[1].s;
        sort(river.p.begin(), river.p.end());
        rivers[i] = river;
    }
    cin >> P;
    cin >> target.p[0].f >> target.p[0].s >> target.p[1].f >> target.p[1].s;
    squareLen = target.p[1].f - target.p[0].f;
    ll calePole = squareLen * (target.p[1].s - target.p[0].s);
    ll minPole = calePole * P; //P%
    calePole *= 100; //100%
    init();
    ll ans = MAX_A;
    int l = 0, r = MAX_A;
    while(l <= r)
    {
        int m = (l + r) / 2;
        vector<Event> events;
        for(int i = 0; i < n; i++)
        {
            Square radius = rivers[i];
            if(!increaseSize(m, radius.p)) continue;
            Event start = Event(radius.p[0].s, radius.p[0].f, 1, 
                (radius.p[1].f - radius.p[0].f));
            Event end = Event(radius.p[1].s, radius.p[1].f, -1, 
                (radius.p[1].f - radius.p[0].f));
            events.push_back(start);
            events.push_back(end);
        }
        sort(events.begin(), events.end(), sortEvents);
        int lastY = -1;
        ll sum = 0;
        init();
        for(Event& curr : events)
        {
            sum += (curr.y - lastY) * (MAX_A - t[1].s); 
            lastY = curr.y;
            if(curr.add > 0)
            {
                int uL = curr.x;
                int uR = uL + curr.d;
                update(uL, uR - 1, curr.add);
            }
            else
            {
                int uR = curr.x;
                int uL = uR - curr.d;
                update(uL, uR - 1, curr.add);
            }
            // update na indeksie x do x + d - 1
        }

        //dodac nie dodane
        //cerr << sum << '\n';
        //sum * 100%
        if(sum * 100 >= minPole)
        {
            r = m - 1;
            ans = m;
        }
        else
            l = m + 1;
    }
    cout << ans;
    return 0;
}