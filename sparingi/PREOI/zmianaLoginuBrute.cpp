#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
vector<pair<string, string>> moves = 
{
    {"AG", "SS"},
    {"GS", "AA"}, 
    {"SA", "GG"}, 
    {"SS", "AG"}, 
    {"AA", "GS"}, 
    {"GG", "SA"}
};

int main()
{
    int n; cin >> n;
    string a, b; cin >> a >> b;
    if(a == b)
    {
        cout << "Tak\n" << 0;
        return 0;
    }
    unordered_map<string, bool> visited;
    queue<pair<string, int>> q;
    q.push({a, 0});
    visited[a] = true;
    while(!q.empty())
    {
        pair<string, int> curr = q.front();
        q.pop();
        string currS = curr.first;
        int moveCnt = curr.second;
        for(int x = 0; x < moves.size(); x++)
        {
            for(int i = 0; i < n - 1; i++)
            {
                if(currS[i] == moves[x].f[0] && currS[i + 1] == moves[x].f[1])
                {
                    string newS = currS;
                    newS[i] = moves[x].s[0];
                    newS[i + 1] = moves[x].s[1];
                    if(newS == b)
                    {
                        cout << "Tak\n" << moveCnt + 1;
                        return 0;
                    }
                    if(visited.find(newS) == visited.end())
                    {
                        q.push({newS, moveCnt + 1});
                        visited[newS] = true;
                    }
                }
            }
        }
    }
    cout << "NIE";
    return 0;
}