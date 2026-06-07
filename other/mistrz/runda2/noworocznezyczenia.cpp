#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string input; cin >> input;
    while(input.size() > 1)
    {
        int sum = 0;
        for(int i = 0; i < input.size(); i++)
            sum += input[i] - '0';
        input = to_string(sum);
    }
    if(input == "1") cout << "Szczesliwego Nowego Roku";
    else cout << input;
    return 0;
}