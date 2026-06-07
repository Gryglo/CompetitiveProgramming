#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    map<int, int> licznik;

    for(int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        licznik[value]++;
    }

    for(auto it : licznik)
    {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}
