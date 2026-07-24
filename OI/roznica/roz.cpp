#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int n;
string input;
vector<vector<int>> freq(26);

int PSOMS(char a, char b)
{
    int maxSum = 0;
    int currSum = 0;
    int minSum = INF;
    int newMinSum = 0;
    for(int i = 0; i < n; i++)
    {
        int value = input[i] == a ? 1 : (input[i] == b ? -1 : 0);
        currSum += value;
        
        if(value == -1)
        {
            minSum = newMinSum;
            newMinSum = min(newMinSum, currSum);
        }
        maxSum = max(maxSum, currSum - minSum);
    }
    return maxSum;
}

//numer literki
//a jako plus a b jako minus
int PSOMS_fast(int a, int b)
{
    if(freq[a].empty() || freq[b].empty())
        return 0;
    int maxSum = 0;
    int currSum = 0;
    int minSum = INF;
    int newMinSum = 0;

    int aFreqSize = freq[a].size(), bFreqSize = freq[b].size();
    int aFreqIdx = 0, bFreqIdx = 0;
    int aIdxVal = freq[a][0], bIdxVal = freq[b][0];

    while(aFreqIdx < aFreqSize || bFreqIdx < bFreqSize)
    {
        if(aIdxVal < bIdxVal)//teraz A + 1
        {
            currSum++;
            maxSum = max(maxSum, currSum - minSum);

            aFreqIdx++;
            aIdxVal = aFreqIdx < aFreqSize ? freq[a][aFreqIdx] : INF;
        }
        else    //teraz B - 1
        {
            currSum--;
            minSum = newMinSum;
            newMinSum = min(newMinSum, currSum);
            maxSum = max(maxSum, currSum - minSum);

            bFreqIdx++;
            bIdxVal = bFreqIdx < bFreqSize ? freq[b][bFreqIdx] : INF;
        }
    }
    return maxSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> input;
    //n = input.size();
    for(int i = 0; i < n; i++)
        freq[input[i] - 'a'].push_back(i);

    int result = 0;
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(i == j)
                continue;
            result = max(result, PSOMS_fast(i, j));
        }
    }
    cout << result;
    //a + 1 , b - 1
    return 0;
}