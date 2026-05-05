#include <iostream>
#include <vector>
using namespace std;

long long length, maxJump, currentFront = 0;
long long cactusCounts[1000009];
long long minCactus[1000009];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> length >> maxJump;
    
    for(long long i = 1; i <= length; i++)
    {
        cin >> cactusCounts[i];
    }
    
    vector<pair<long long, long long>> deque;
    deque.push_back({0, 0});

    for(long long i = 1; i <= length + 1; i++)
    {
        minCactus[i] = cactusCounts[i] + deque[currentFront].first;
        
        while(!deque.empty() && minCactus[i] < deque.back().first)
            deque.pop_back();
        deque.push_back({minCactus[i], i});
        if(deque[currentFront].second == i - maxJump)
            currentFront++;
    }
    
    cout << minCactus[length + 1];
    return 0;
}
