#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() 
{
    string input;
    cin >> input;

    unordered_map<char, int> charCount;

    for (char c : input) 
    {
        charCount[c]++;
    }

    string palindrome;
    string sortedHalf;

    char oddChar = '\0';

    for (const auto &entry : charCount) {
        char c = entry.first;
        int count = entry.second;

        palindrome += string(count / 2, c);

        if (count % 2 == 1) {
            if (oddChar == '\0' || c < oddChar) {
                oddChar = c;
            }
        }
    }

    sortedHalf = palindrome;
    sort(sortedHalf.begin(), sortedHalf.end());

    string result = sortedHalf + (oddChar != '\0' ? string(1, oddChar) : "") + string(sortedHalf.rbegin(), sortedHalf.rend());

    cout << result;

    return 0;
}