#include <bits/stdc++.h>
using namespace std;

int n, x;
int main()
{
    cin >> n >> x;
    int currSum = 0;
    int maxLeftIndex = 0;
    int minPigNumber = 1000000001;
    int currMaxLeftIndex = 0;
    queue<int> pigBanks;
    for(int i = 0; i < n; i++)
    {
        int currPig;
        cin >> currPig;
        currSum += currPig;
        pigBanks.push(currPig);
        while(currSum >= x)
        {
            if(pigBanks.size() < minPigNumber)
            {
                minPigNumber = pigBanks.size();
                maxLeftIndex = currMaxLeftIndex;
            }
            int lastPigValue = pigBanks.front();
            currSum -= lastPigValue;
            pigBanks.pop();
            currMaxLeftIndex++;
        }
    }
    cout << minPigNumber << " " << maxLeftIndex + 1;
    return 0;
}