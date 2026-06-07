#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{

    int N_cyna, N_zloto, S;
    
    cin >> N_cyna;
    vector<int> cyna(N_cyna);
    for (int i = 0; i < N_cyna; i++) 
        cin >> cyna[i];

    cin >> N_zloto;
    vector<int> zloto(N_zloto);
    for (int i = 0; i < N_zloto; i++) 
        cin >> zloto[i];
    
    cin >> S;
    vector<int> dp(S + 1, -1);
    dp[0] = 0;


    for (int i = 0; i <= S; i++) 
    {

        if (dp[i] != -1) 
        {
            for (int valCyna : cyna)
            {
                if (i + valCyna <= S)
                    dp[i + valCyna] = max(dp[i + valCyna], dp[i]);
            }


            for (int valZloto : zloto)
            {
                if (i + valZloto <= S)
                    dp[i + valZloto] = max(dp[i + valZloto], dp[i] + 1);
            }
        }

    }

    if (dp[S] == -1) 
        cout << "NIE" << '\n';
    else 
        cout << dp[S] << '\n';
    return 0;
}
