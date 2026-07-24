#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, vector<int>> reservationsMap;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    int lastHour = 0;
    for(int i = 0; i < n; i++)
    {
        int start, end; 
        cin >> start >> end;
        reservationsMap[end].push_back(start);
        lastHour = max(lastHour, end);
    }
    //25 + 24 + 23 + 22 + 21 + 20 + 19 + 18 + 17 + 16 + 15 + 14 + 13 + 12 + 11 + 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1
    vector<int> dp(lastHour + 1);
    dp[0] = 0;
    for(int i = 1; i <= lastHour; i++)
    {
        int currMaxHour = dp[i - 1];
        auto endHourIt = reservationsMap.find(i); 
        if(endHourIt != reservationsMap.end())
        {
            const int& endHour = endHourIt->first;
            for(const int& startHour : endHourIt->second)
            currMaxHour = max(currMaxHour, dp[startHour] + (endHour - startHour));
        }
        dp[i] = currMaxHour;
    }
    
    cout << dp[lastHour];
    return 0;
}


/* for(int i = 0; i <= lastHour; i++)
cout << i << ' ';
cout << '\n';
for(int i = 0; i <= lastHour; i++)
cout << dp[i] << ' '; */
/* for(pair<int, vector<int>> rezerwacja : reservationsMap)
{
    cout << "Koniec: " << rezerwacja.first << "\n";
    cout << "Początki: ";
    for(int curr : rezerwacja.second)
    cout << curr << " ";
    cout << "\n\n";
} */
/* vector<pair<int, int>> reservations;

bool compareReservations(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first)
    return a.first < b.first;
    return a.second < b.second;
} */
/* sort(reservations.begin(), reservations.end(), compareReservations);
for(int i = 0; i < n; i++)
cout << reservations[i].first << ' ' << reservations[i].second << '\n'; */