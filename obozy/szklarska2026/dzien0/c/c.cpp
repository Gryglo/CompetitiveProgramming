#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
int Q, t;
unordered_map<int, bool> wa;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> Q >> t;
    int op, time, id;
    queue<pii> q;
    for(int i = 0; i < Q; i++)
    {
        cin >> op >> time >> id;
        if(t == 0)
        {
            cout << "Jest akcept! " << id << endl;
            return 0;
        }
        if(op == 2)
            wa[id] = true;
        while(!q.empty() && q.front().f <= time)
        {
            pii curr = q.front();
            q.pop();
            if(!wa[curr.s])
            {
                cout << "Jest akcept! " << curr.s << endl;
                return 0;
            }
        }
        if(op == 1)
            q.push({time + t, id});
        cout << "Dalej czekamy :(" << endl;
    }
    return 0;
}