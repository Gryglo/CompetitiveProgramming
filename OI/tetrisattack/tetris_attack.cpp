#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50005;
int n;
vector<bool> occurs(MAXN, false);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    //          num idx
    stack<int> stos;
    stack<int> inputStos;
    for(int i = 0; i < (2 * n); i++)
    {
        int curr;
        cin >> curr;
        inputStos.push(curr);
    }
    while(!inputStos.empty())
    {
        stos.push(inputStos.top());
        inputStos.pop();
    }
    stack<int> taken;
    vector<int> ans;

    while(!stos.empty())
    {
        int curr = stos.top();
        stos.pop();

        if(occurs[curr])
        {
            int last = taken.top();
            taken.pop();
            occurs[last] = false;
            if(last != curr)
            {
                stos.push(last);
                stos.push(curr);
                ans.push_back(taken.size() + 1);
            }
        }
        else
        {
            occurs[curr] = true;
            taken.push(curr);
        }
    }

    cout << ans.size() << '\n';
    for(int pos : ans)
        cout << pos << '\n';

    return 0;
}