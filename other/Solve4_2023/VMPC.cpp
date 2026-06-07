#include <iostream>
#include <vector>

using namespace std;
int n;
int ciag[400];
int ciag2[400];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        ciag[i] = num;
    }

    for(int i = 0; i < n; i++)
    {
        cout << ciag[(ciag[ciag[i] % n] + 1) % n] << " ";
    }
    return 0;
}
