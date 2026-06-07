#include <iostream>
#include <vector>

#define ll unsigned long long

using namespace std;

vector<pair<char, int> > stackedNumber;
ll result = 0;

void roundOnes()
{
    pair<char, int> lastPacket = stackedNumber.back();
    if(lastPacket.first == '9' || lastPacket.first == '0')
        return;
    
    result += (ll)((ll)9 - (ll)(lastPacket.first - '0'));
    lastPacket.second--;
    if(lastPacket.second <= 0)
    {
        stackedNumber.pop_back();
        if (!stackedNumber.empty() && stackedNumber.back().first == '9')
            stackedNumber.back().second++;
        else
            stackedNumber.push_back( { '9', 1 } );
    }
    else
    {
        stackedNumber.back().second--; 
        stackedNumber.push_back( { '9', 1 } );
    }
}

void checkIfAddingIsBetter()
{
    ll maxDiff = 0;
    ll diff = 99999999;
    ll currNum = 0;
    ll multiplier = 1;
    ll additionalOperations = 1;
    ll addedNum = 0;

    for(int i = 1; addedNum <= 6; i++)
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
        for(int x = 0; x < currPacket.second && addedNum < 6; x++)
        {
            currNum += (ll)(currPacket.first - '0') * multiplier;
            multiplier *= 10;
            maxDiff *= 10;
            maxDiff += 9;
            diff = maxDiff - currNum;
            if(currPacket.first != '0')
                additionalOperations += (9 - (currPacket.first - '0')) + 1;   
            addedNum++;
        }
    }
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
    else if(stackedNumber.size() == 2 && stackedNumber[0].first == '1' && stackedNumber[0].second == 1 && stackedNumber[1].first == '0')
    {
        cout << "1";
        return 0;
    }
    roundOnes();
    if(stackedNumber.size() == 1 && stackedNumber[0].first == '9')
    {
        cout << result + 2;
        return 0;
    }
    checkIfAddingIsBetter(); 
    
    for(int i = 0; i < stackedNumber.size(); i++)
    {
    	pair<char, int> currPacket = stackedNumber[i];
    	
    	if(i == stackedNumber.size() - 1 && currPacket.first == '9')
    		break;
    	
    	if(currPacket.first == '0')
    		continue;
    	result += (ll)currPacket.second + (ll) ((ll)9 - (ll)(currPacket.first - '0')) * (ll)currPacket.second;
	}
    /*
    Hymn XIV Liceum
    Otwieramy okna na świat,
    Sumujemy zyski bez strat,
    gdy szkolne skończą się dni,
    Pozostanie refren, który brzmi:
    LO XIV głośno śpiewa
    O romantyzmie ścisłych rzeczy.
    Niemożliwego nic dla nas nie ma,
    Nauka temu nie przeczy,
    Bo pożyteczne i praktyczne
    Jest to myślenie, jest to działanie
    Matematyczno - fizyczne.
    */
    cout << result + 2;
    return 0;
}