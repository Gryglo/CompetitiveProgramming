#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std; 

int n;
ll K;

void generateCoinsSumsGreater(int index, ll currSum, int currCount, const vector<ll>& coins, 
priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>& coinsSums)
{
    if(index == coins.size())
    {
        coinsSums.push( {currSum, currCount} );
        return;
    }

    generateCoinsSumsGreater(index + 1, currSum, currCount, coins, coinsSums);
    generateCoinsSumsGreater(index + 1, currSum + coins[index], currCount + 1, coins, coinsSums);
}

void generateCoinsSums(int index, ll currSum, int currCount, const vector<ll>& coins, 
priority_queue<pair<long long, int>>& coinsSums)
{
    if(index == coins.size())
    {
        coinsSums.push( {currSum, currCount} );
        return;
    }

    generateCoinsSums(index + 1, currSum, currCount, coins, coinsSums);
    generateCoinsSums(index + 1, currSum + coins[index], currCount + 1, coins, coinsSums);
}

int main()
{
    cin >> n >> K;

    int halfN = n/2;
    vector<ll> firstHalf(halfN);
    vector<ll> secondHalf(n % 2 == 0 ? halfN : halfN + 1);

    for(int i = 0; i < halfN; i++)
        cin >> firstHalf[i];
    for(int i = halfN; i < n; i++)
        cin >> secondHalf[i - halfN];

    priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> firstHalfSums;
    priority_queue<pair<long long, int>> secondHalfSums;

    generateCoinsSumsGreater(0, 0, 0, firstHalf, firstHalfSums);
    generateCoinsSums(0, 0, 0, secondHalf, secondHalfSums);

    int minCoins = 99999999;
    while(!firstHalfSums.empty() && !secondHalfSums.empty())
    {
        pair<long long, int> currFirstSum = firstHalfSums.top();
        pair<long long, int> currSecondSum = secondHalfSums.top();

        pair<long long, int> currSum = { currFirstSum.first + currSecondSum.first, currFirstSum.second + currSecondSum.second };

        if(currSum.first == K && currSum.second < minCoins)
            minCoins = currSum.second;

        if(currSum.first > K)
            secondHalfSums.pop();
        else if(currSum.first <= K)
            firstHalfSums.pop();
    }

    if(minCoins == 99999999)
        cout << "NIE";
    else
        cout << minCoins;


    return 0; 
}