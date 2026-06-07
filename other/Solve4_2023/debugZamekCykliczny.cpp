#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;

//         liczba count 
vector<pair<char, int>> stackedNumber;
int result = 0;

void roundOnes()
{
    pair<char, int> lastPacket = stackedNumber.back();
    if(lastPacket.first == '9' || lastPacket.first == '0')
        return;
    
    result += 9 - (lastPacket.first - '0');
    lastPacket.second--;
    if(lastPacket.second <= 0)
        stackedNumber.pop_back();
    else
        stackedNumber.back().second--;

    if(stackedNumber.back().first == '9')
        stackedNumber.back().second++;
    else
        stackedNumber.push_back( { '9', 1 } );
   
}

void jumpNumber()
{
    pair<char, int> firstPacket = stackedNumber.front();
    int diffSum = (9 - (firstPacket.first - '0')) * firstPacket.second;
    stackedNumber.erase(stackedNumber.begin());

    if(stackedNumber.back().first == '9')
        stackedNumber.back().second += firstPacket.second;
    else
        stackedNumber.push_back( { '9', firstPacket.second } );

    //              skoki          dopelnianie
    result += (firstPacket.second + diffSum);
}

void removeLeadingZeros()
{
    if(stackedNumber[0].first == '0')
        stackedNumber.erase(stackedNumber.begin());
}

void checkIfAddingIsBetter()
{
    int lookForCount = 7;

    int maxDiff = 0;
    int diff = 0;
    int currNum = 0;
    int multiplier = 1;
    int additionalOperations = 1;
    int addedNum = 0;
    for(int i = 1; addedNum < lookForCount; i++)
    {
        if((int) stackedNumber.size() - i < 0)
            break;
        pair<char, int> currPacket = stackedNumber[stackedNumber.size() - i];
        if(i >= 2 && currPacket.first == '9' && currPacket.second + additionalOperations > diff)
        {
            
            int originalArraySize = stackedNumber.size();
            for(int x = 1; x < i; x++)
            {
                pair<char, int> prevPacket = stackedNumber[originalArraySize - x];
                currPacket.second += prevPacket.second;
                stackedNumber.pop_back();
            }
            stackedNumber[originalArraySize - i] = currPacket;
            result += diff; 
            return;
        }
        if(i == 6)
            return;
        for(int x = 0; x < currPacket.second && addedNum < lookForCount; x++)
        {
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

bool targetPacket()
{
    if(stackedNumber.size() == 1 && stackedNumber[0].first == '9')
        return true;
    return false;
}

int countDigit(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) 
    {
        n = n / 10;
        count++;
    }
    return count;
}

int main() 
{
    string input;
    cin >> input;

    if(input == "1")
    {
        cout << "0";
        return 0;
    }
    else if(input == "0")
    {
        cout << "1";
        return 0;
    }

    stackedNumber.push_back({ input[0], 1 });
    int lastIndex = 0;
    for(int i = 1; i < input.size(); i++)
    {
        if(input[i - 1] == input[i])
            stackedNumber[lastIndex] = { input[i], stackedNumber[lastIndex].second + 1 };
        else
        {
            lastIndex++;
            stackedNumber.push_back({ input[i], 1 });
        }
    }

    if(stackedNumber.size() == 1 && stackedNumber[0].first == '9')
    {
        cout << "2";
        return 0;
    }
    else if(stackedNumber.size() == 2 && stackedNumber[0].first == '1' && stackedNumber[1].first == '0')
    {
        cout << "1";
        return 0;
    }

    cout << "START=-------------\n";
    for(pair<char, int> para : stackedNumber)
        cout << para.first << " " << para.second << '\n';
    cout << "=-------------\n";
    cout << result << '\n';

    checkIfAddingIsBetter(); 


    cout << "2=-------------\n";
    for(pair<char, int> para : stackedNumber)
        cout << para.first << " " << para.second << '\n';
    cout << "=-------------\n";
    cout << result << "\n";



    roundOnes();
    while(!targetPacket())
    {
        removeLeadingZeros();
        if(targetPacket())
            break;
        jumpNumber();

        cout << "=-------------\n";
        for(pair<char, int> para : stackedNumber)
            cout << para.first << " " << para.second << '\n';
        cout << "=-------------\n";
        cout << result << "\n";
    }

    cout << result + 2;
    return 0;
}