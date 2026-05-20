#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> ans(n + 1);
    int max_w = 0;
    for(int k = 1; k <= n; k++)
    {
        int cnt_w = 0;
        vector<vector<int>> added;
        for(int i = 0; i + (k - 1) < n; i += k)
        {
            vector<int> curr;
            for(int x = i; x < i + k; x++) curr.push_back(a[x]);
            bool end = false;
            for(vector<int>& v : added)
            {
                int cnt = 0;
                for(int x = 0; x < v.size(); x++) 
                {
                    if(v[x] != curr[x]) break;
                    cnt++;
                }
                if(cnt == v.size()){ end = true; break; }
            }
            if(end) continue;
            vector<int> curr_rev = curr;
            reverse(curr_rev.begin(), curr_rev.end());
            added.push_back(curr);
            added.push_back(curr_rev);
            cnt_w++;
        }
        max_w = max(max_w, cnt_w);
        ans[cnt_w].push_back(k);
    }
    cout << max_w << ' ' << ans[max_w].size() << '\n';
    for(int x : ans[max_w]) cout << x << ' ';
    return 0;
}