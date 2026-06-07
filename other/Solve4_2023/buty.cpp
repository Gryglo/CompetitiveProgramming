
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<int> toFind(N);
    for(int i = 0; i < N; i++)
        cin >> toFind[i];


    
/*
    unordered_map<int, int> lowestPrice;
    for(int i = 0; i < M; i++)
    {
        int size, price;
        cin >> size >> price;

        int sizeLowestPrice = 999999999;

        if(lowestPrice.find(size) != lowestPrice.end())
            sizeLowestPrice = lowestPrice[size];

        if(price < sizeLowestPrice)
            lowestPrice[size] = price;
    }

    for(const int& wantedSize : toFind)
    {
        if(lowestPrice.find(wantedSize) != lowestPrice.end())
        {

        }
        else
        {
            cout << "NIE";
            return 0;
        }
    }
*/
    return 0;
}
