#include <iostream>

#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;

    ll rest;

    ll result = 0;
    if(N > 30)
    {
        rest = N % 30;
        //cout << rest << endl;
        result = result + ((N - rest) / 30) * 16;
        N = rest;
        //cout << result << endl;
    }

    //16
    for(ll i = 1; i <= N; i++)
    {
        if(((i % 2 == 0) || (i % 3 == 0)) && (i % 5 != 0))
        {
            result++;
        }
    }
    cout << result << endl;
}