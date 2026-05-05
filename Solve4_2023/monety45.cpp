#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> coins(N);
    for(int i = 0; i < N; i++) 
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    int S;
    cin >> S;

    vector<int> dp(S + 1, 1000000000), parent(S + 1, -1), coin_used(S + 1, -1);
    dp[0] = 0;

    for(int i = 0; i < N; i++) 
    {
        for(int j = coins[i]; j <= S; j++) 
        {
            if(dp[j] > dp[j - coins[i]] + 1) 
            {
                dp[j] = dp[j - coins[i]] + 1;
                parent[j] = j - coins[i];
                coin_used[j] = coins[i];
            }
        }
    }

    if(parent[S] == -1) 
    {
        cout << "NIE" << endl;
    } 
    else 
    {
        vector<int> coins;
        while(S) 
        {
            coins.push_back(coin_used[S]);
            S = parent[S];
        }

        cout << coins.size() << endl;

        for(int i = 0; i < coins.size(); i++) 
        {
            cout << coins[i] << " ";
        }
    }
    return 0;
}
