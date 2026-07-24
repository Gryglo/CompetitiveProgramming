#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

const int MAXN = 1000000 + 5;

int n, maxNum;
vector<int> visited(MAXN + 1, -1); //[num] idx
vector<int> dist(MAXN + 1, MAXN); //[num] dist
vector<int> primes;
vector<int> sieve(MAXN + 1); //[num] dividor
queue<pii> q;// num, idx
vector<pii> ans; // dist, idx

void make_sieve()
{
    sieve[0] = 1;
    sieve[1] = 1;
    for(int i = 2; i <= maxNum; i++)
    {
        if(sieve[i] != 0)
            continue;
        primes.push_back(i);
        sieve[i] = i;
        for(int x = 2 * i; x <= maxNum; x += i)
            sieve[x] = i;
    }
}

void addNode(int num, int from, int idx)
{
    int thisCost = dist[from] + 1;
    if(visited[num] == -1)
    {
        visited[num] = idx;
        dist[num] = thisCost;
        q.push( { num, idx } );
    }
    else
    {
        if(visited[num] == idx)
            return;
        ans[idx] = min(ans[idx], { thisCost + dist[num], visited[num] });
        ans[visited[num]] = min(ans[visited[num]], { thisCost + dist[num], idx });
    }
}

void BFS()
{
    while(!q.empty())
    {
        pii curr = q.front();
        q.pop();

        for(int p : primes)
        {
            if(curr.f * p > maxNum)
                break;
            addNode(curr.f * p, curr.f, curr.s);
        }
        
        int num = curr.f;
        while(num > 1)
        {
            addNode(curr.f / sieve[num], curr.f, curr.s);
            num /= sieve[num];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans.resize(n, { MAXN, -1 });
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        maxNum = max(maxNum, a);
        if(visited[a] != -1)
        {
            ans[i] = { 0, visited[a] };
            ans[visited[a]] = min(ans[visited[a]], { 0, i });
        }
        else
        {
            q.push({ a, i });
            visited[a] = i;
            dist[a] = 0;
        }
    }
    make_sieve();
    BFS();
    for(int i = 0; i < n; i++)
        cout << ans[i].s + 1 << '\n';
    return 0;
}