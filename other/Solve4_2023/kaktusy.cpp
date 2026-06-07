#include <iostream>
#include <vector>
#define ll long long

using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K;
    cin >> N >> K;
    N += 2;

    vector<ll> sum(N);
    sum[0] = 0;
    ll firstVal;
    cin >> firstVal;
    sum[1] = firstVal;
    sum[N - 1] = 0;


    for(int i = 2; i < N; i++)
    {
        ll val;
        if(i == N - 1)
            val = 0;
        else
            cin >> val;

        ll smallestValue = 1e18;
        for(int j = 1; j <= K; j++)
        {
            if(i - j >= 0 && sum[i - j] <= smallestValue)
            {
                smallestValue = sum[i - j];
                //sum[i] = val + sum[i - 1];
            }
        }
        sum[i] = val + smallestValue;
    }
    cout << sum[N - 1];
    return 0;
}
