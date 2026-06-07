#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    //ifuj do n do 3
    int cntWrong1 = 0;
    int cntWrong2 = 0;
    int bothWrong = 0;

    for(int i = 1; i <= n; i++)
    {
        int a;  cin >> a;
        if(a != i && a == n - i + 1)
            cntWrong1++;
        if(a != n - i + 1 && a == i)
            cntWrong2++;
        if(a != i && a != n - i + 1)
            bothWrong++;
    }

    if(bothWrong == n)
        cout << "Tie\n";
    else if(cntWrong2 + bothWrong < cntWrong1)
        cout << "Second\n";
    else if(cntWrong1 + bothWrong <= cntWrong2)
        cout << "First\n";
    else 
        cout << "Tie\n"; 
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}