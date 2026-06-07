#include <bits/stdc++.h>
using namespace std;

int n, t;
int qcnt = 0;

unordered_map<string, bool> cached;

bool ask(vector<int> query)
{
    string s = "? " + to_string(query.size());
    for(int x : query)
    {
        s = s + ' ' + to_string(x);
    }
    if(cached[s])
        return cached[s];
    cout << s << endl;
    /* cout << "? " << query.size();
    for(int x : query)
        cout << ' ' <<  x; */
    string ans; cin >> ans;
    if(ans == "TAK")
        cached[s] = true;
    else
        cached[s] = false;
    return (ans == "TAK");
}

vector<int> queryRange(int l, int r)
{
    vector<int> res;
    for(int i = l; i <= r; i++)
        res.push_back(i);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;

    vector<int> possible;
    for(int i = 1; i <= n; i++)
        possible.push_back(i);

    while(possible.size() > 2)
    {
        int K = possible.size();
        int L = (2 * K + 2) / 3; 
        vector<int> left, right;
        for(int i = 0; i < L; i++) 
            left.push_back(possible[i]);
        for(int i = K - L; i < K; i++) 
            right.push_back(possible[i]);
        bool leftRes = ask(left);
        bool rightRes = ask(right);
        vector<int> temp;
        if(leftRes && rightRes)
        {
            for(int i = K - L; i < L; i++)
                temp.push_back(possible[i]);
        }
        else if(leftRes)
            temp = left;
        else if(rightRes)
            temp = right;
        else 
        {
            for(int i = 0; i < K - L; i++)
                temp.push_back(possible[i]);
            for(int i = L; i < K; i++)
                temp.push_back(possible[i]); 
        }
        possible = temp;
    }
    cout << "! " << possible[0] << ' ' << possible[1] << endl;
    return 0;
}