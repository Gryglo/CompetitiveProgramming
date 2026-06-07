#include <iostream>
using namespace std;

int go(int N, int maxNum) 
{
    if (N == 0)    
        return 1;

    int count = 0;

    for (int i = 1; i <= N && i <= maxNum; i++) 
        count = (count + go(N - i, i)) % (1'000'000'000 + 7);


    return count;
}

int main() 
{
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int N;
        cin >> N;
        cout << go(N, N) << "\n";
    }
    return 0;
}
