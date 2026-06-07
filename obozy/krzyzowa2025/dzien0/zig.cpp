#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
int n, k;
vector<vector<string>> slowa(26);
vector<int> ptx(26);
int main()
{
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        slowa[x[0] - 'a'].push_back(x);
    }

    for(int i = 0; i < 26; i++)
        sort(slowa[i].begin(), slowa[i].end());
    for(int i = 0; i < k; i++)
    {
        char x;
        cin >> x;
        cout << slowa[x - 'a'][ptx[x - 'a']] << '\n';
        ptx[x - 'a'] = (ptx[x - 'a'] + 1) % slowa[x - 'a'].size();
    }
    return 0;
}