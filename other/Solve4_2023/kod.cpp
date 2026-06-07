#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;

    vector<ll> ciag(N);
    for (ll i = 0; i < N; ++i) 
    {
        cin >> ciag[i];
    }


    ll M;
    cin >> M;

    for (ll i = 0; i < M; ++i) 
    {
        ll x;
        cin >> x;

        ll low = 0; 
        ll high = N;


        while (low < high)
        {
            ll mid = (high - low) / 2 + low;

            if (ciag[mid] >= x) 
            {
                high = mid;
            } 
            else 
            {
                low = mid + 1;
            }
        }
        
        cout << N - low << "\n";
    }

    return 0;
}
