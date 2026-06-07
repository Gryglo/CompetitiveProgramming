#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int n;
int ways = 0;
vector<int> decisions;

bool isSafe()
{
    if(decisions.empty()) return true;
    int currIndex = decisions.size() - 1;
    for(int i = 0; i < currIndex; i++)
    {
        if(decisions[i] == decisions.back())
            return false;
        if(decisions[i] == decisions.back() - (currIndex - i) || decisions[i] == decisions.back() + (currIndex - i))
            return false;
    }
    return true;
}

void solve()
{
    if(!isSafe()) return;
    for(int i = 0; i < n; i++)
    {
        if(decisions.size() == n){ ways++; return; }
        decisions.push_back(i);
        solve();
        decisions.pop_back();
    }

}

int main()
{
    cin >> n;

    solve();
    cout << ways;
    return 0;
}
