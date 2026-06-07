#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int lenght;
    cin >> lenght;

    vector<long long int> input;

    long long int result = 0;
    long long int count = 0;

    for(int i = 0; i < lenght; i++)
    {
        int value;
        cin >> value;
        input.push_back(value);
    }

    for(int i = lenght - 1; i >= 0; i--)
    {
        int value = input[i];
        //cout << value;


        if(value == 1)
            count++;
        else if(value == 0)
            result += count;
    }
    
    cout << result;
    
    return 0;
}
