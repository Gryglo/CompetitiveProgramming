#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll canBeExchanged(vector<int> coins, int S, vector<ll>& cameFrom, vector<ll>& coinOn)
{
    vector<bool> dp(S + 1);
    vector<ll> sum(S + 1, 0);

    dp[0] = true;
    sum[0] = 0;

    sort(coins.begin(), coins.end());

    for(int i = 1; i <= S; i++)
    {
        for(int coinVal : coins)
        {
            if(coinVal <= i && dp[i - coinVal])
            {
                if(sum[i - coinVal] + 1 >= sum[i]) 
                {
                    cameFrom[i] = i - coinVal;
                    coinOn[i] = coinVal;

                    sum[i] = sum[i - coinVal] + 1;
                    dp[i] = true;
                }
            }
        }
    }

    return sum[S];
}

int main()
{
    int N;
    cin >> N;

    vector<int> coins(N);
    for(int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    int S;
    cin >> S;

    vector<ll> cameFrom(S + 1, 0);
    vector<ll> coinOn(S + 1, 0);
    ll result = canBeExchanged(coins, S, cameFrom, coinOn);
    if (result == 0 && S > 0)
    {
        cout << "NIE";
        return 0;
    }
    else
    {
        cout << result;
        cout << '\n';

        vector<ll> results;
        for(int i = S; i >= 0; i)
        {
            if(coinOn[i] == 0)
                break;

            results.push_back(coinOn[i]);
            i = cameFrom[i];
        }
        reverse(results.begin(), results.end());
        for(ll val : results)
        {
            cout << val << " ";
        }
    }
    return 0;
}
