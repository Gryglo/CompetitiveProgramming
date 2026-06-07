#include <iostream>
#define ll long long

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;

    ll sum = 0;
    ll countInserts = 0;
    for(int i = 0; i < Q; i++)
    {
        string type;
        cin >> type;
        if(type == "SUM")
            cout << sum << '\n';
        else
        {
            ll x;
            cin >> x;
            if(type == "INSERT")
                sum += x;
                countInserts++;
            else
                sum += countInserts * x;
        }
    }
    return 0;
}