#include <iostream>
#define ll long long

using namespace std;
int main()
{
    int N;
    cin >> N;

    ll result = 0;

    ll start;
    cin >> start;

    if(N > 1)
    {
        bool up;
        ll prev;
        cin >> prev;
        if(start > prev)
            up = false;
        else
            up = true;
        
        for(int i = 2; i < N; i++)
        {
            ll value;
            cin >> value;

            if(value > prev && !up)
            {
                result++;
                up = true;
            }
            else if(value < prev && up)
            {
                result++;
                up = false;
            }
            prev = value;
        }
    }

    cout << result;

    return 0;
}