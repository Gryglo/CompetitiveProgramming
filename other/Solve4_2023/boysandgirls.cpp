#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int minGirls; 
    cin >> minGirls;

    string input;
    cin >> input;
    
    int currGirls = 0;
    int currOutBoys = 0;
    int minOutBoys = 999999999;

    queue<char> currentQueue;
    bool isFirstGirlFounded = false; 
    for(int i = 0; i < input.length(); i++)
    {
        if(!isFirstGirlFounded)
        {
            if(input[i] != 'D')
                continue;
            isFirstGirlFounded = true;
        }

        currentQueue.push(input[i]);
        if(input[i] == 'D')
            currGirls++;
        else
            currOutBoys++;

        if(currGirls >= minGirls)
        {
            if(currOutBoys < minOutBoys)
                minOutBoys = currOutBoys;
            while(currGirls >= minGirls)
            {
               if(currentQueue.front() == 'C')
               {
                    currOutBoys--;
                    if(currOutBoys < minOutBoys)
                        minOutBoys = currOutBoys;
               }
               if(currentQueue.front() == 'D')
                    currGirls--;
                currentQueue.pop();
            }
        }
    }

    if(minOutBoys >= 999999999)
    {
        cout << "NIE";
        return 0;
    }
    cout << minOutBoys;
    return 0;
}