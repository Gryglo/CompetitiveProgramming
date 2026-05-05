#include <iostream>
#include <vector>

using namespace std;

void kolejnePodzbiory(int N, int poczatek, vector<int>& podzbiory) 
{
    for (int i = poczatek; i <= N; i++) 
    {
        podzbiory.push_back(i);
        for (int i = 0; i < podzbiory.size(); i++) 
        {
            cout << podzbiory[i] << " ";
        }
        cout << '\n';
        kolejnePodzbiory(N, i + 1, podzbiory);
        podzbiory.pop_back();
    }
}

int main() 
{

    int N;
    cin >> N;
    vector<int> podzbiory;
    kolejnePodzbiory(N, 1, podzbiory);
    return 0;
}
