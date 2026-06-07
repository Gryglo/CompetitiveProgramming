#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
int n, m, l;
long double x, y;
int main()
{
    fastio;
    cin >> n >> m >> l >> x >> y;
    vector<pii> buses(n);
    for(int i = 0; i < n; i++)
        cin >> buses[i].f >> buses[i].s;
    sort(buses.begin(), buses.end());

    vector<pii> people(m);
    for(int i = 0; i < m; i++)
    {
        cin >> people[i].f;
        people[i].s = i;
    }
    sort(people.begin(), people.end());

    vector<long double> ans(m);
    int currBus = 0;
    //                      cost      end
    priority_queue<pair<long double, int>> pq;
    for(int i = 0; i < m; i++)
    {
        int currGuy = people[i].f;
        while(!pq.empty() && pq.top().second < currGuy)
            pq.pop();
        while(currBus < n && buses[currBus].f <= currGuy)
        {
            long double cost = 
            ((long double)(buses[currBus].s - buses[currBus].f) / x)
            + (long double)(l - buses[currBus].s) / y;
            pq.push({-cost, buses[currBus].s});
            currBus++;
        }

        long double walkCost = (long double)(l - currGuy) / y;
        if(!pq.empty() && -pq.top().f < walkCost)
            ans[people[i].s] = -pq.top().f;
        else
            ans[people[i].s] = walkCost;
        
    }
    cout << fixed << setprecision(6);
    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';
    return 0;
}