#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 2000005;
vector<long long> positions;
int tree[4 * MAXN];
int lazy[4 * MAXN];
set<int> colors;

int n, m;
void push_down(int node, int l, int r) 
{
    if (lazy[node] > 0) 
    {
        tree[node] = lazy[node];
        if (l != r) 
        {
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int ul, int ur, int color) 
{
    push_down(node, l, r);
    if (r < ul || l > ur)
        return;
        
    
    if (ul <= l && r <= ur)
    {
        tree[node] = color;
        if (l != r) 
        {
            lazy[node * 2] = color;
            lazy[node * 2 + 1] = color;
        }
        //here
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, ul, ur, color);
    update(node * 2 + 1, mid + 1, r, ul, ur, color);

    if (tree[node * 2] == tree[node * 2 + 1])
        tree[node] = tree[node * 2];
    else
        tree[node] = -1;
}

void countColors(int node, int l, int r) 
{
    push_down(node, l, r);
    if (tree[node] == -1) 
    {
        if (l == r)
            return;
        int mid = (l + r) / 2;
        countColors(node * 2, l, mid);
        countColors(node * 2 + 1, mid + 1, r);
    } 
    else if (tree[node] != 0) 
        colors.insert(tree[node]);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    vector<int> ai(m), bi(m);
    vector<int> ci(m);

    positions.push_back(1);
    positions.push_back(n + 1);

    for (int i = 0; i < m; ++i) 
    {
        cin >> ai[i] >> bi[i] >> ci[i];
        positions.push_back(ai[i]);
        positions.push_back(bi[i] + 1);
    }

    sort(positions.begin(), positions.end());
    positions.erase(unique(positions.begin(), positions.end()), positions.end());

    int K = positions.size();

    for (int i = 0; i < m; ++i) 
    {
        int l = lower_bound(positions.begin(), positions.end(), ai[i]) - positions.begin();
        int r = lower_bound(positions.begin(), positions.end(), bi[i] + 1) - positions.begin() - 1;

        update(1, 0, K - 2, l, r, ci[i]);
    }
    countColors(1, 0, K - 2);

    cout << colors.size();

    return 0;
}