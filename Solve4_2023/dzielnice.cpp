#include <iostream>
#include <vector>

using namespace std;

int find(int number, vector<int>& parent)
{
    if(parent[number] != number)
    {
        parent[number] = find(parent[number], parent);
    }
    return parent[number];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int dzielnice, ulice;
    cin >> dzielnice >> ulice;

    vector<int> parent(dzielnice);
    for(int i = 0; i < dzielnice; i++)
    {
        parent[i] = i;
    }

    int result = dzielnice;
    for(int i = 0; i < ulice; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        int kapitanA = find(a, parent);
        int kapitanB = find(b, parent);
        if(kapitanA != kapitanB)
        {
            result--;
            parent[kapitanB] = kapitanA;
        }
        cout << result << '\n';
    }
    return 0;
}
