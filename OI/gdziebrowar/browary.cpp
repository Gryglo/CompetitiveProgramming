#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> dist;
vector<int> demand;

int minCost;
int cost = 0;
int maxL, maxR;
int demandSumL = 0, demandSumR = 0;
int distSumL = 0, distSumR = 0;

void poprawGranice()
{
    //granice poprawiamy w lewo
    while(distSumL + dist[maxL] < distSumR)
    {
        distSumL += dist[maxL];
        maxL = (maxL + 1) % n;
        cost += demand[maxL] * distSumL;
        
        cost -= demand[maxR] * distSumR;
        distSumR -= dist[maxR];
        maxR = (maxR + 1) % n;

        demandSumL += demand[maxL];
        demandSumR -= demand[maxL];
    }
}

int32_t main()
{
    cin >> n;
    dist.resize(n);
    demand.resize(n);
    for(int i = 0; i < n; i++)
        cin >> demand[i] >> dist[i];

    //0-based
    maxL = 0; //1
    maxR = 1; //2 cale kolko w prawo

    for(int i = n - 1; i >= 1; i--)
    {
        demandSumR += demand[i];
        distSumR += dist[i];
        cost += distSumR * demand[i];
    }
    minCost = cost;
    poprawGranice();
    
    for(int i = 1; i < n; i++)
    {
        cost = cost - demandSumL * dist[i - 1] + (demandSumR + demand[i - 1]) * dist[i - 1];
        demandSumL -= demand[i];
        demandSumR += demand[i - 1];
        distSumR += dist[i - 1];
        distSumL -= dist[i - 1];
        poprawGranice();
        minCost = min(minCost, cost);
    }

    cout << minCost;
    return 0;
}