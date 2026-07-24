#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000000;

int n, m; 
string inputLizak;
vector<int> lizak;
//[liczba]- przedzial
vector<pair<int, int>> segments(MAXN + 1, { -1, -1 });

int sum = 0;
pair<int, pair<int, int>> longestEvenSegment = { -1, { -1, -1 }};
pair<int, pair<int, int>> longestOddSegment = { -1, { -1, -1 }};

void computeMaxSegments()
{
    int firstOne = -1;
    int lastOne = -1;
    for(int i = 0; i < inputLizak.size(); i++)
    {
        int curr = (inputLizak[i] == 'T') ? 2 : 1;
        lizak[i] = curr;
        if(curr == 1)
        {
            if(firstOne == -1)
                firstOne = i;
            lastOne = i;
        }
        sum += curr;
    }   
    
    if(sum % 2 == 0) //parzysty lizak
    {
        //suma
        longestEvenSegment = { sum ,{ 0, n - 1 }};

        if(firstOne != -1)
        {
            int firstSegment = sum - ((n - lastOne - 1) * 2 + 1);
            int secondSegment = sum - ((firstOne) * 2 + 1);
            //cout << firstSegment << ' ' << secondSegment << '\n';

            if(n - 1 - firstOne > lastOne) 
                longestOddSegment = { secondSegment, { firstOne + 1, n - 1 }}; //second
            else
                longestOddSegment = { firstSegment, { 0, lastOne - 1 }}; //first
        }
    }
    else
    {
        longestOddSegment = { sum ,{ 0, n - 1 }};
        if(firstOne != -1)
        {
            int firstSegment = sum - ((n - lastOne - 1) * 2 + 1);
            int secondSegment = sum - ((firstOne) * 2 + 1);
            //cout << firstSegment << ' ' << secondSegment << '\n';
            if(n - 1 - firstOne > lastOne) 
                longestEvenSegment = { secondSegment, { firstOne + 1, n - 1 }}; //second
            else
                longestEvenSegment = { firstSegment, { 0, lastOne - 1 }}; //first 
        }
    }
}

void calculateSegments()
{
    if(longestEvenSegment.first != -1)
    {
        segments[longestEvenSegment.first] = { longestEvenSegment.second.first, longestEvenSegment.second.second };
        while(longestEvenSegment.first >= 3) //mozna ciac
        {
            if(lizak[longestEvenSegment.second.first] == 2)
                longestEvenSegment.second.first++;
            else if(lizak[longestEvenSegment.second.second] == 2)
                longestEvenSegment.second.second--;
            else
            {
                longestEvenSegment.second.first++;
                longestEvenSegment.second.second--;
            }
            longestEvenSegment.first -= 2;
            segments[longestEvenSegment.first] = { longestEvenSegment.second.first, longestEvenSegment.second.second };
        }
    }
    if(longestOddSegment.first != -1)
    {
        segments[longestOddSegment.first] = { longestOddSegment.second.first, longestOddSegment.second.second };
        while(longestOddSegment.first >= 3) //mozna ciac
        {
            if(lizak[longestOddSegment.second.first] == 2)
                longestOddSegment.second.first++;
            else if(lizak[longestOddSegment.second.second] == 2)
                longestOddSegment.second.second--;
            else
            {
                longestOddSegment.second.first++;
                longestOddSegment.second.second--;
            }
            longestOddSegment.first -= 2;
            segments[longestOddSegment.first] = { longestOddSegment.second.first, longestOddSegment.second.second };
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> inputLizak;
    lizak.resize(n);
    computeMaxSegments();
    calculateSegments();
    while(m--)
    {
        int query;
        cin >> query;
        
        if(query > sum || segments[query].first == -1)
            cout << "NIE\n";
        else
            cout << segments[query].first + 1 << ' ' << segments[query].second + 1 << '\n'; 
    }
    return 0;
}