#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> pos;  //[0-4][x] = idx

bool cmp(int a, int b)
{
    int aPrzedB = 0;
    int bPrzedA = 0;
    for(int i = 0; i < 5; i++)
    {
        if(pos[i][a] < pos[i][b])
            aPrzedB++;
        else
            bPrzedA++;
    }
    if(aPrzedB > bPrzedA) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pos.resize(5, vector<int>(n + 1));
    vector<int> ciag(n);
    for(int i = 0; i < n; i++)
        ciag[i] = i + 1;
    for(int x = 0; x < 5; x++)
    {
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            pos[x][a] = i;
        }
    }
    sort(ciag.begin(), ciag.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << ciag[i] << ' ';
    return 0;
}