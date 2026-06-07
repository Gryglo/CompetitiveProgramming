#include <iostream>
#include <algorithm>

using namespace std;
int main() 
{
    string result = "abb";
    char character = ' ';
    result = result.substr(0, result.length()/2) + character + result.substr(result.length()/2);
    cout << result;
    return 0;
}
