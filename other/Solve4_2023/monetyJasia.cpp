#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> coins;

int calGcdForCoins()
{
    int gcd = coins[0];
    for (int i = 1; i < coins.size(); i++) 
    {
        gcd = gcd > 1 ? __gcd(gcd, coins[i]) : 1;
        if (gcd == 1) 
            break;
    }
    return gcd;
}

int BFS()
{
    vector<int> minNum(coins[0], INT_MAX);
    queue<int> q;
    minNum[0] = 0;
    q.push(0);
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(int coin : coins)
        {
            int nextVal = curr + coin;
            int rest = nextVal % coins[0];

            if(nextVal < minNum[rest]) //czyli jeszcze takiej reszty nie było
            {
                minNum[rest] = nextVal;
                q.push(nextVal);
            }
        }
    }
    
    int result = 0;
    for(int i = 0; i < coins[0]; i++) 
        result = max(result, minNum[i]);

    return result - coins[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    coins.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
        if(coins[i] == 1)
        {
            cout << '0';
            return 0;
        }
    }

    int currGcd = calGcdForCoins();

    if(currGcd > 1)
    {
        cout << "NIE";
        return 0;
    }

    cout << BFS() + 1;
    return 0;
}