#include <bits/stdc++.h>
#include "arc.h"
using namespace std;

const int INF = INT_MAX;
int k;

stack<int> min_s;
vector<int> ans;
queue<int> pending;
bool all_loaded = false;
bool load_pending()
{
    if(all_loaded) return false;
    int curr = wczytaj();
    if(curr == 0)
    {
        all_loaded = true;
        return false;
    }
    pending.push(curr);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    k = inicjuj();
    while(pending.size() < k)
        if(!load_pending()) break;
    
    while(!pending.empty())
    {
        int curr = pending.front();
        pending.pop();
        while(!min_s.empty() && min_s.top() < curr)
        {
            if(ans.size() + pending.size() + 1 <= k)
                break;
            ans.pop_back();
            min_s.pop();
        }
        int last_min = curr;
        if(!min_s.empty())
            last_min = min(min_s.top(), curr);
        min_s.push(last_min);
        ans.push_back(curr);
        load_pending();
    }
    for(int x : ans)
        wypisz(x);
    return 0;
}
