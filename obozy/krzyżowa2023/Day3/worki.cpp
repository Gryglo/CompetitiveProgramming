#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> worki(M);

    for(int i = 1; i <= N; i++)
    {
        int value;
        cin >> value;
        vector<int> temp = worki[value - 1];
        temp.push_back(i);
        worki[value - 1] = temp;
    }

    for(int i = 0; i < M; i++)
    {
        vector<int> worek = worki[i];
        for(int wartosc : worek)
        {
            cout << wartosc << " ";
        }
        cout << "\n";
    }
    return 0;
}