#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    pair<int, int> dobreTyczki;
    cin >> dobreTyczki.first;
    cin >> dobreTyczki.second;

    int chinskaTyczka;
    cin >> chinskaTyczka;

    vector<bool> pole(N);
    for(int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        pole[i] = (bool) value;
    }

    vector<bool> dp(N, false);
    vector<bool> dp2(N, false);

    dp[0] = true;
    dp2[0] = true;
    int fahrestValue = 0;
    for(int i = 1; i < N; i++)
    {
        dp[i] = (!pole[i]) && (
        ((i - dobreTyczki.first >= 0)  ? (dp[i - dobreTyczki.first])  : false) ||
        ((i - dobreTyczki.second >= 0) ? (dp[i - dobreTyczki.second]) : false));

        if(dp[i])
            if(i > fahrestValue)
                fahrestValue = i;

        dp2[i] = (!pole[i]) && (
        ((i - dobreTyczki.first >= 0)  ? (dp2[i - dobreTyczki.first])  : false) ||
        ((i - dobreTyczki.second >= 0) ? (dp2[i - dobreTyczki.second]) : false) ||
        ((i - chinskaTyczka >= 0)      ? (dp[i - chinskaTyczka])       : false));

        if(dp2[i])
            if(i > fahrestValue)
                fahrestValue = i;
    }

    cout << fahrestValue + 1;
    return 0;
}
