#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> tower1(N);
    vector<int> tower2(M);

    for (int i = 0; i < N; ++i) 
    {
        cin >> tower1[i];
    }

    for (int i = 0; i < M; ++i) 
    {
        cin >> tower2[i];
    }

    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; ++i)
    {
        sum1 += tower1[i];
    }
    for (int i = 0; i < M; ++i) 
    {
        sum2 += tower2[i];
    }

    int moves = 0;
    //int difference = abs(sum1 - sum2);

    while (sum1 != sum2) 
    {
        moves++;
        if (sum1 > sum2) 
        {
            int value = tower1.back();
            tower1.pop_back();
            //cout << "\n" <<value;
            sum1 -= value;
        } 
        else 
        {
            int value = tower2.back();
            tower2.pop_back();
           // cout << "\n" <<value;
            sum2 -= value;
        }
        if(sum1 == sum2)
        {
            cout << moves;
            return 0;
        }
    }

    cout << moves;

    return 0;
}
