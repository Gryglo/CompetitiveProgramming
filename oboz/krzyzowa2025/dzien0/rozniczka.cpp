#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    int n = 10;
    vector<int> ciag(n);
    vector<int> A(n);
    vector<int> B(n);


    int l = 2, r = 5;
    int a = 2;
    int b = 2;
    //a + b*i

    
    //0 1 2 3 4 5 6 7 8 9
    //0 0 2 4 6 8 0 0 0 0
    //wiemy ze index 2 wiec
    A[l] += (a-(b*l));
    A[r+1] -= (a-(b*l));
    B[l] += b;
    B[r+1] -= b;

    a = 6;
    b = -2;
    l = 6, r = 8;
    A[l] += (a-(b*l));
    A[r+1] -= (a-(b*l));
    B[l] += b;
    B[r+1] -= b;

    vector<int> aPref(n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            aPref[i] = A[0];
        else
            aPref[i] = aPref[i - 1] + A[i];
        cout << aPref[i] << ' ';
    }
    cout << '\n';
    vector<int> bPref(n);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            bPref[i] = B[0];
        else
            bPref[i] = bPref[i - 1] + B[i];
        cout << bPref[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < n; i++)
    {
        cout << aPref[i] + bPref[i] * i << ' ';
    }
    return 0;
}