#include <iostream>
#include <vector>

#define ll long long
using namespace std;

void buildTree(ll v, ll l, ll r, const vector<int>& hotels, vector<ll>& hotelsTree)
{
    if(l == r)
        hotelsTree[v] = hotels[l];
    else
    {
        ll mid = (l + r) / 2;
        buildTree(2 * v, l, mid, hotels, hotelsTree);
        buildTree(2 * v + 1, mid + 1, r, hotels, hotelsTree);
        hotelsTree[v] = hotelsTree[2 * v] + hotelsTree[2 * v + 1];
    }
}

ll sum(ll v, ll l, ll r, ll targetL, ll targetR, const vector<ll>& hotelsTree)
{
    if(targetL > targetR)
        return 0;
    if(l == targetL && r == targetR)
        return hotelsTree[v];
        
    ll mid = (l + r) / 2;
    return sum(
        2 * v, 
        l, mid, 
        targetL, min(targetR, mid), 
        hotelsTree) 
        + sum(
        2 * v + 1, 
        mid + 1, r, 
        max(targetL, mid + 1), targetR, 
        hotelsTree);
}

void editTree(ll v, ll l, ll r, ll targetPos, ll targetValue, vector<ll>& hotelsTree)
{
    if(l == r)
        hotelsTree[v] = targetValue;
    else
    {
        ll mid = (l + r) / 2;
        if(targetPos <= mid)
            editTree(2 * v, l, mid, targetPos, targetValue, hotelsTree);
        else
            editTree(2 * v + 1, mid + 1, r, targetPos, targetValue, hotelsTree);
        hotelsTree[v] = hotelsTree[2 * v] + hotelsTree[2 * v + 1];
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> hotels(n);
    for (int i = 0; i < n; ++i) 
        cin >> hotels[i];
    
    vector<ll> hotelsTree(n * 4);
    buildTree(1, 0, n - 1, hotels, hotelsTree);

    for(int i = 0; i < q; i++)
    {
        int option, firstVal, secondVal;
        cin >> option >> firstVal >> secondVal;
        if(option == 1)
            editTree(1, 0, n - 1, firstVal - 1, secondVal, hotelsTree);
        else
            cout << sum(1, 0, n - 1, firstVal - 1, secondVal - 1, hotelsTree) << '\n';
    }
    return 0;
}
