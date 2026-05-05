#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int input;
    cin >> input;
    
    for(int i = -input; i <= input; i++)
    {
        for(int j = -input; j<=input; j++)
        {
            double odleglosc = sqrt(i*i + j*j);
            if(odleglosc <= input)
            {
                cout << "#";
            }
            else{
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}
