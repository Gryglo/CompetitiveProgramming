#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const ll INF = INT_MAX;
vector<vector<ll>> dp;
int n;
string input;
unordered_set<string> wzorce;
void computeDp(int firstMarki, const string& wzor, int i, int add)
{
    string temp = "";
    for(int d = 0; d < firstMarki; d++)
        temp += wzor[d];
    
    for(int d = max(0,firstMarki); d < wzor.size(); d++) //znak to jest pierwszy zapytania
    {
        temp += wzor[d];
        int lasti = firstMarki;
        if(lasti == -1) lasti = d;
        if(wzorce.find(temp) != wzorce.end()) 
        {
            for(int z = 4; z >= max(0, 4 - laslti); z--)
            {
                dp[i + d][z] = 
                min(dp[i + d][z], dp[i - 1][z] + add);
            }
            for(int z = max(0, 4 - lasti) - 1; z >= 0; z--)
            {
                dp[i + d][z] = 
                min(dp[i + d][z], dp[i + d][z + 1]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> input;
    for(int i = 0; i < n; i++)
    {
        string wzor; cin >> wzor;
        wzorce.insert(wzor);
        for(int x = 0; x < wzor.size(); x++) 
        {
            string wzor1 = wzor; wzor1[x] = '?'; wzorce.insert(wzor1);
            for(int y = x + 5; y < wzor.size(); y++)
            {
                string wzor2 = wzor1; wzor2[y] = '?'; wzorce.insert(wzor2);
            }
        }
    }
    dp.resize(input.size() + 1, vector<ll>(5, INF));
    //+4 3 2 1 0
    // a b b b b a
    for(int i = 0; i <= 4; i++) dp[0][i] = 0;
    for(int i = 0; i < input.size(); i++)
    {
        string wzor;
        for(int x = i; x < min((int)input.size(), i + 10); x++)
            wzor += input[x];
        computeDp(-1, wzor, i + 1, 0);
        for(int x = 0; x < wzor.size(); x++) 
        {
            string wzor1 = wzor; wzor1[x] = '?';
            computeDp(x, wzor1, i + 1, 1);
            for(int y = x + 5; y < wzor.size(); y++)
            {
                string wzor2 = wzor1; wzor2[y] = '?';
                computeDp(x, wzor2, i + 1, 2);
            }
        }
    }
    ll minAns = input.size();
    for(int i = 0; i <= 4; i++)
        minAns = min(minAns, dp[input.size()][i]);
    cout << minAns;
    return 0;
}