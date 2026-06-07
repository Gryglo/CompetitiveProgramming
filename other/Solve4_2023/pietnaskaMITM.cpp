#include <iostream>
#include <bitset>
#include <queue>
#include <unordered_map> 
#define ull unsigned long long
using namespace std;
                      //G   L  P  D
short directions[4] = {-4, -1, 1, 4};
string movesNames = "GLPD";
ull targetStateBitMask = 18364758544493064720;

ull stateElementFromBitMask(short idx, ull bitMask)
{
    return (bitMask >> (4 * idx)) & 15;
}

/*
pair<short, short> posFromBitMask(short posBitMask)
{
    return { (posBitMask >> 2) & 3, posBitMask & 3 };
}

short posToBitMask(short x, short y)
{
    return (x << 2) | y;
}
*/

string bfs(ull startingStateBitMask, short startPos)
{
    unordered_map<ull, string> visitedStart;
    unordered_map<ull, string> visitedEnd;
    
    //      start/end   bitmask      pos    moves
    queue<pair<bool, pair<ull, pair<short, short>>>> q;

    q.push( { true, { startingStateBitMask, { startPos, 0} } } );
    visitedStart[startingStateBitMask] = "";

    q.push( { false, { targetStateBitMask, { 0, 0 } } } );
    visitedEnd[targetStateBitMask] = "";


    while(!q.empty())
    {
        pair<bool, pair<ull, pair<short, short>>> curr = q.front();
        q.pop();
        bool start = curr.first;
        ull currState = curr.second.first;
        short currPos = curr.second.second.first;
        short movesCount = curr.second.second.second;
        if(movesCount > 30)
            continue;

        string path = start ? visitedStart[currState] : visitedEnd[currState];

        for(short i = 0; i < 4; i++)
        {
            if ((i == 1 && currPos % 4 == 0) || (i == 2 && currPos % 4 == 3))   
                continue;
                
            short nextPos = currPos + directions[i];
            if(nextPos >= 0 && nextPos < 16)
            {
                ull newState = currState | (stateElementFromBitMask(nextPos, currState) << (4 * currPos)); 
                newState &= ~(15ULL << (4 * nextPos));

                if(start)
                {
                    if(visitedStart.find(newState) == visitedStart.end())
                    {
                        visitedStart[newState] = path + movesNames[i];
                        q.push( { true, { newState, { nextPos, movesCount + 1 } } } );
                    }

                    if(visitedEnd.find(newState) != visitedEnd.end())
                        return visitedStart[newState] + visitedEnd[newState];
                }
                else
                {
                    if(visitedEnd.find(newState) == visitedEnd.end())
                    {
                        visitedEnd[newState] = movesNames[3 - i] + path;
                        q.push( { false, { newState, { nextPos, movesCount + 1 } } } );
                    }

                    if(visitedStart.find(newState) != visitedStart.end())
                        return visitedStart[newState] + visitedEnd[newState];
                }
            }
        }
    }
    return "NIE";
}
int main() 
{
    ull inputBitMask = 0;
    short startPos;
    for(int i = 0; i < 16; i++)
    {
        ull value;
        cin >> value;
        if(value == 0) startPos = i;
        inputBitMask |= (value << (4 * i));
    }

    /*
    //wpisywanie na zera dziala
    ull newState = inputBitMask | (stateElementFromBitMask(2, inputBitMask) << (4 * 8)); 
    newState &= ~(15 << (4 * 2));

    bitset<64> binary(inputBitMask); 
    cout << "Bitmask1: " << binary << '\n'; 
    bitset<64> binary2(newState); 
    cout << "Bitmask2: " << binary2 << '\n'; 
    */

    string result = bfs(inputBitMask, startPos);
    //cout << result << '\n';
    result += '0';
    string finalResult = "";
    for(int i = 0; i < result.size() - 1; i++)
    {
        if((result[i] == 'L' && result[i + 1] == 'P') 
        || (result[i] == 'P' && result[i + 1] == 'L')
        || (result[i] == 'G' && result[i + 1] == 'D') 
        || (result[i] == 'D' && result[i + 1] == 'G'))
            i += 2;
        else
            finalResult += result[i];
    }
    cout << finalResult;

    return 0;
}
