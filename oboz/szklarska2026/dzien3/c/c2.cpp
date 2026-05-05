#include <bits/stdc++.h>    
using namespace std;
#define f first
#define s second
using pii = pair<int, int>;

const int INF = INT_MAX;

int n;
int a = INF, b = 2;
vector<vector<pii>> adj;

void setup()
{
    adj.resize(n);
}

int ask(vector<int>& colors)
{
    cout << "?";
    for(int c : colors)
        cout << ' ' << c;
    cout << endl;
    int res; cin >> res; return res;
}

int main()
{
    cin >> n;
    setup();

    int lastV = -1;
    for(int i = 1; i < n; i++)
    {
        vector<int> temp(n);
        temp[0] = 1;
        temp[i] = 2;
        int curr = ask(temp);
        if(lastV == -1)
        {
            a = curr;
            b = curr;
            lastV = curr;
            continue;
        }

        if(curr < lastV)
        {
            a = curr;
            b = lastV;
        }
        else if(curr > lastV)
        {
            a = lastV;
            b = curr;
        }
    }
    vector<pii> ans;
    vector<int> possible;
    vector<bool> added(n); 
    int curr = 0;
    vector<int> currList;
    while(curr != -1)
    {
        added[curr] = true;
        currList.push_back(curr);
        possible.clear();
        for(int i = 0; i < n; i++)
        {
            if(!added[i])
                possible.push_back(i);
        }
        if(possible.size() == 0)
        {
            break;
        }
        int l = 0, r = possible.size() - 1;
        while(l < r)
        {
            int m = (l + r) / 2;
            int sz = (r - l + 1);
            if(sz % 2 == 0)
            {
                //[l, m] i [m + 1, r]
                vector<int> left(n);
                left[curr] = 1;
                for(int i = l; i <= m; i++)
                    left[possible[i]] = 2;
                int sumL = ask(left);
                int leftSize = m - l + 1;
                if(sumL < leftSize * b)
                    r = m;
                else
                    l = m + 1;
            }
            else
            {
                //[l, m] i [m, r]
                vector<int> left(n);
                left[curr] = 1;
                for(int i = l; i <= m; i++)
                    left[possible[i]] = 2;
                int sumL = ask(left);
                int leftSize = m - l + 1;
                if(sumL < leftSize * b)
                    r = m;
                else
                    l = m + 1;
            }
        }
        //l to nasza droga
        ans.push_back({curr, possible[l]});
        added[possible[l]] = true;
        curr = -1;
        for(int i = 0; i < n; i++)
        {
            if(!added[i])
            {
                curr = i;
                break;
            }
        }
    }

    for(int i = 1; i < currList.size(); i++)
        ans.push_back({0, currList[i]});
    cout << "! " << ans.size() << endl;
    for(pii curr : ans)
    {
        cout << curr.f + 1 << ' ' << curr.s + 1 << endl;
    }
    return 0;
}