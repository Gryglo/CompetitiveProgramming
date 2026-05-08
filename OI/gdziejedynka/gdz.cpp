#include <bits/stdc++.h>
/* 
* LOKALNIE KOMPILUJ Z BIBLIOTEKĄ:
* cgdzlib.h -> cgdzlib.c
*/
#include "cgdzlib.h"
using namespace std;
using pii = pair<int, int>;


const int BASE = 2;
int n;

void split(vector<int>& a, vector<int>& l, vector<int>& r, int p)
{
    l.push_back(a[0]);
    for(int i = 1; i < a.size(); i++)
    {
        if(f(a[0], a[i], p))
            l.push_back(a[i]);
        else
            r.push_back(a[i]);
    }
}

pii merge(pii& l_m, pii& r_m, int p, int len)
{
    int max_diff = p * (len - 1);
    if(f(l_m.first, r_m.first, max_diff))
        return {l_m.first, r_m.first};
    if(f(l_m.first, r_m.second, max_diff))
        return {l_m.first, r_m.second};
    if(f(l_m.second, r_m.first, max_diff))
        return {l_m.second, r_m.first};
    if(f(l_m.second, r_m.second, max_diff))
        return {l_m.second, r_m.second};
    if(l_m.first != l_m.second 
        && f(l_m.first, l_m.second, max_diff))
        return {l_m.first, l_m.second};
    return {r_m.first, r_m.second};
}

pii find_max(vector<int>& a, int p)
{
    if(a.size() == 1)
        return {a[0], a[0]};
    vector<int> l, r;
    split(a, l, r, p * BASE);
    pii l_max = find_max(l, p * BASE);
    pii r_max = find_max(r, p * BASE);
    return merge(l_max, r_max, p, a.size());
}

int main() 
{
    n = inicjuj();
    //inicjuj();
    if(n == 1)
    {
        odpowiedz(1);
        return 0;
    }
    vector<int> a(n);
    for(int i = 1; i <= n; i++)
        a[i - 1] = i;
    pii p_max = find_max(a, 1);
    if(g(p_max.first, p_max.second))
        odpowiedz(p_max.second);
    else
        odpowiedz(p_max.first);
    return 0;
}
