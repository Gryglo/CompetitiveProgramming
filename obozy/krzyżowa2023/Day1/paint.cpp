#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    long long int paint = 1;

    for(int i = 0; i < input.size(); i++)
    {
        char character = input[i];
        if(character == 'A' || character == 'a' || character == 'e'|| character == 'b' || character == 'd' || character == 'D' || character == 'g' || character == 'O' || character == 'o' || character == 'P'|| character == 'p'|| character == 'R'|| character == 'Q'|| character == 'q')
        {
            paint++;
        }
        else if(character == 'B')
        {
            paint += 2;
        }
    }

    cout << paint;
    return 0;
}
