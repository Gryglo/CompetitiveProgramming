#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sortujPoKoncu(pair <int, int> a,  pair <int, int> b)
{
    if(a.second != b.second)
    {
        return (a.second < b.second);
    }
    else
    {
        return (a.first < b.second);
    }
}

int main()
{
    int ile;
    cin >> ile;

    vector<pair <int, int>> pary(ile);




    for (int i = 0; i<ile; i++)
    {
        cin >> pary[i].first;
        cin >> pary[i].second;
    }
    //sort (pary.second, pary.second + ile);
    sort(pary.begin(), pary.end(), sortujPoKoncu);
    for (int i = 0; i<ile; i++)
    {
        cout << pary[i].first << " " << pary[i].second << endl;
    }
    return 0;
}