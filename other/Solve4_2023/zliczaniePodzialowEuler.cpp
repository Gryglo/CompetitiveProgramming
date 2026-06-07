#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll dp[300'000];

int maxN = 0;
void go()
{
    dp[0] = 1;
    
    for (ll n = 1; n <= maxN; n++)
    {
        ll multiplier = 1;

        ll k = 1;
        ll liczbaPieciokatna = 0;
        ll liczbaPieciokatna2 = 0;

        while(liczbaPieciokatna <= n && liczbaPieciokatna2 <= n)
        {
            liczbaPieciokatna = k * (3 * k - 1) / 2;
            liczbaPieciokatna2 = k * (3 * k + 1) / 2;

            if (liczbaPieciokatna <= n)
                dp[n] = (dp[n] + dp[n - liczbaPieciokatna] * multiplier) % (1'000'000'007);
            if (liczbaPieciokatna2 <= n)
                dp[n] = (dp[n] + dp[n - liczbaPieciokatna2] * multiplier) % (1'000'000'007);

            multiplier *= -1;
            k++;
        }
    
        if (dp[n] < 0) 
            dp[n] += 1'000'000'007;
    }

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

    go();
    
    for (int i = 0; i < Q; i++)
        cout << dp[queries[i]] << "\n";
    return 0;
}
