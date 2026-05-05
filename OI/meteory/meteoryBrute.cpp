#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int n, m, k;
vector<vector<int>> countryIdxs;
vector<int> need;
vector<pair<pair<int, int>, int>> q;

struct BinSegment
{
    int idx;
    int l, r, m;
    BinSegment(int i)
    {
        idx = i;
        l = 0, r = k - 1;
        m = r / 2;
    }
};
vector<vector<BinSegment>> segments;
vector<int> ans;

vector<int> t;
vector<int> lazy;


int main()
{
    cin >> n >> m;
    t.resize(4 * m, 0);
    lazy.resize(4 * m, 0);
    t[5] = 4;
    t[6] = 2;
    t.assign(4 * m, 0);
    lazy.assign(4 * m, 0);
    cout << t[5] << ' ' << t[6];
    //[0, k - 1]
    return 0;
}