#include <bits/stdc++.h>
#include "arc.h"
using namespace std;
int k;
vector<int> a;
int main()
{   
    //cerr << ((7000000 * sizeof(int)) / 1000000) << '\n';
    k = inicjuj();
    int curr = wczytaj();
    while(curr != 0)
    {
        a.push_back(curr);
        curr = wczytaj();
    }
    int ans_size = 0;
    int last_i = 0;
    while(ans_size < k)
    {
        int curr_max = 0;
        int curr_max_i = 0;
        for(int i = last_i; i < a.size() - ((k - 1) - ans_size); i++)
        {
            if(a[i] > curr_max)
            {
                curr_max = a[i];
                curr_max_i = i;
            }
        }
        wypisz(curr_max);
        ans_size++;
        last_i = curr_max_i + 1;
    }
    return 0;
}
