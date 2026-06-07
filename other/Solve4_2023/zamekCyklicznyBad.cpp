#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAXN = 1000000;

//         liczba count
pair<char, int> stackedNumber[MAXN];
int frontIndex = 0;
int backIndex = 0;
int result = 0;

void roundOnes() {
    pair<char, int>& lastPacket = stackedNumber[backIndex];
    if (lastPacket.first == '9' || lastPacket.first == '0')
        return;

    result += 9 - (lastPacket.first - '0');
    lastPacket.second--;
    if (lastPacket.second <= 0)
        backIndex--;
    else
        stackedNumber[backIndex].second--;

    if (stackedNumber[backIndex].first == '9')
        stackedNumber[backIndex].second++;
    else {
        backIndex++;
        stackedNumber[backIndex] = { '9', 1 };
    }
}

void jumpNumber() {
    pair<char, int>& firstPacket = stackedNumber[frontIndex];
    int diffSum = (9 - (firstPacket.first - '0')) * firstPacket.second;
    frontIndex++;

    if (stackedNumber[backIndex].first == '9')
        stackedNumber[backIndex].second += firstPacket.second;
    else {
        backIndex++;
        stackedNumber[backIndex] = { '9', firstPacket.second };
    }

    result += (firstPacket.second + diffSum);
}

void removeLeadingZeros() {
    if (stackedNumber[frontIndex].first == '0')
        frontIndex++;
}

void checkIfAddingIsBetter() {
    int lookForCount = 6;

    int maxDiff = 0;
    int diff = 0;
    int currNum = 0;
    int multiplier = 1;
    int additionalOperations = 1;
    int addedNum = 0;

    for (int i = 1; addedNum < 7; i++) {
        if (backIndex - i < frontIndex)
            break;

        pair<char, int>& currPacket = stackedNumber[backIndex - i];
        if (i >= 2 && currPacket.first == '9' && currPacket.second + additionalOperations > diff) {
            for (int x = 1; x < i; x++) {
                pair<char, int>& prevPacket = stackedNumber[backIndex - x];
                currPacket.second += prevPacket.second;
            }
            backIndex -= (i - 1); // Zmniejszamy backIndex zamiast pop_back
            result += diff;
            return;
        }
        if (i == 6)
            return;

        for (int x = 0; x < currPacket.second && addedNum < lookForCount; x++) {
            additionalOperations += 9 - (currPacket.first - '0');
            currNum += (currPacket.first - '0') * multiplier;
            multiplier *= 10;
            maxDiff *= 10;
            maxDiff += 9;
            diff = maxDiff - currNum;
            addedNum++;
        }
    }
}

bool targetPacket() {
    return (backIndex - frontIndex == 0 && stackedNumber[frontIndex].first == '9');
}

int countDigit(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        count++;
    }
    return count;
}

int main() {
    string input;
    cin >> input;

    if (input == "1") 
    {
        cout << "0";
        return 0;
    }

    stackedNumber[0] = { input[0], 1 };

    for (int i = 1; i < input.size(); i++) 
    {
        if (input[i - 1] == input[i])
            stackedNumber[backIndex] = { input[i], stackedNumber[backIndex].second + 1 };;
        else 
        {
            backIndex++;
            stackedNumber[backIndex] = { input[i], 1 };
        }
    }

    if (backIndex == 0 && stackedNumber[0].first == '9') 
    {
        cout << "2";
        return 0;
    } 
    else if (backIndex == 1 && stackedNumber[0].first == '1' && stackedNumber[1].first == '0') {
        cout << "1";
        return 0;
    }

    checkIfAddingIsBetter();
    roundOnes();

    while (!targetPacket()) {
        removeLeadingZeros();
        if (targetPacket())
            break;
        jumpNumber();
    }

    cout << result + 2;
    return 0;
}
