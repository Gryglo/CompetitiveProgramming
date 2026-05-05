#include <iostream>
#include <vector>
using namespace std;

int maxN = 0;
vector<int> go()
{
    vector<int> dp(maxN + 1, 0);
    dp[0] = 1;
    
    for (int x = 1; x <= maxN; x++)
        for (int y = x; y <= maxN; y++)
            dp[y] = (dp[y] + dp[y - x]) % (1'000'000'007);

    return dp;
}

int main() 
{
    int Q;
    cin >> Q;
    
    int queries[Q];
    for (int i = 0; i < Q; i++) 
    {
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }
    
    vector<int> dp = go();
    
    for (int i = 0; i < Q; i++)
        cout << dp[queries[i]] << "\n";
    
    return 0;
}
