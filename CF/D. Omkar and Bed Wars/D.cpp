#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<char> a;
    for(int i = 0; i < n; i++) 
    {
        char curr; cin >> curr;
        if(curr == 'L' && a.size() > 0 && a.back() == 'R')
        {
            a.pop_back();
            a.push_back('0');
        }
        else a.push_back(curr);
    }
    if(a[0] == 'L' && a[a.size() - 1] == 'R')
    {
        a.pop_back();
        a[0] = '0';
    }

    vector<int> r_c;
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
    {   
        if(a[i] == 'R') cnt++;
        else 
        {
            if(cnt > 0) r_c.push_back(cnt);
            cnt = 0;
        }
        if(i == a.size() - 1)
        {
            if(a[i] == 'R' && a[0] == 'R')
            {
                if(r_c.size() == 0) r_c.push_back(cnt);
                else r_c[0] += cnt;
            }
            else if(cnt > 0) r_c.push_back(cnt);
        }
    }
    vector<int> l_c;
    cnt = 0;
    for(int i = 0; i < a.size(); i++)
    {   
        if(a[i] == 'L') cnt++;
        else 
        {
            if(cnt > 0) l_c.push_back(cnt);
            cnt = 0;
        }
        if(i == a.size() - 1)
        {
            if(a[i] == 'L' && a[0] == 'L')
            {
                if(l_c.size() == 0) l_c.push_back(cnt);
                else l_c[0] += cnt;
            }
            else if(cnt > 0) l_c.push_back(cnt);
        }
    }
    if(r_c.size() > 0 && r_c[0] == a.size())
    {
        r_c[0]++;
    }
    
    if(l_c.size() > 0 && l_c[0] == a.size())
    {
        l_c[0]++;
    }

    int ans = 0;
    for(int curr_c : r_c)
    {
        ans += (curr_c / 3 + (curr_c % 3 == 2));
    }
    for(int curr_c : l_c)
    {
        ans += (curr_c / 3 + (curr_c % 3 == 2));
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}