#include <iostream>

using namespace std;
int liczby[1000001]; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for(int i = 1; i <= N; i++)
    {
        int value;
        cin >> value;
        if(liczby[value] == 0)
            liczby[value] = i;
    }
    for(int i = 0; i < Q; i++)
    {
       int input;
       cin >> input;
       if(liczby[input] == 0)
        cout << "NIE" << '\n';
       else
        cout << liczby[input] << '\n';
    }
    return 0;
}
