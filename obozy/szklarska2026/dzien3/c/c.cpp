#include <bits/stdc++.h>    
using namespace std;
#define f first
#define s second
using pii = pair<int, int>;

const int INF = INT_MAX;

int n;
int a = INF, b = 0;
vector<pii> ans;
vector<bool> added;
unordered_map<string, int> cached_res;

int ask(vector<int>& colors)
{
    string curr = "?";
    for(int i = 0; i < n; i++)
        curr = curr + ' ' + to_string(colors[i]);
    if(cached_res.find(curr) != cached_res.end())
        return cached_res[curr];
    cout << curr << endl;
    int res; cin >> res; 
    cached_res[curr] = res;
    return res;
}

int ask(int x, vector<int>& possible)
{
    vector<int> colors(n);
    colors[x] = 1;
    for(int i = 0; i < possible.size(); i++)
        colors[possible[i]] = 2;
    return ask(colors);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    added.resize(n);
    vector<int> temp(n);
    temp[0] = 1;
    temp[1] = 2;
    a = ask(temp); //lub to jest b

    int targetV = 0;
    for(int i = 0; i < n; i++)
    {
        temp.assign(n, 2);
        temp[i] = 1;
        int currSum = ask(temp);
        if(currSum != (n - 1) * a)
        {
            targetV = i;
            break;
        }
    }
    vector<int> possibleD; //drzewo z inna waroscia
    for(int i = 0; i < n; i++)
    {
        if(i == targetV) continue;
        possibleD.push_back(i);
    }
    int l = 0, r = possibleD.size() - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        vector<int> segment(n);
        segment[targetV] = 1;
        for(int i = l; i <= m; i++)
            segment[possibleD[i]] = 2;
        int currSum = ask(segment);
        if(l == r)
        {
            b = currSum;
            break;
        }
        if(currSum != a * (m - l + 1))
            r = m;
        else
            l = m + 1;
    }   
    if(a > b) swap(a, b);
    if(a == b) //losowe krawedzie
    {
        cout << "! " << n - 1 << endl;
        for(int i = 2; i <= n; i++)
            cout << 1 << ' ' << i << endl;
        return 0;
    }

    queue<int> q;
    q.push(0);
    added[0] = true;
    while(ans.size() < n - 1)
    {
        int currV = q.front();
        q.pop();
        vector<int> possible; //poczatkowo wszystkie wolne moga byc z a
        for(int i = 0; i < n; i++)
        {
            if(added[i]) continue;
            possible.push_back(i);
        }
        int currSum = ask(currV, possible);
        int aCnt = (possible.size() * b - currSum)/(b - a);
        if(aCnt == 0)//nie ma zadnego a to laczymy do b
        {
            if(q.size() == 0) //JEZELI NIE MA INNEJ MOZLIWOSCI
            {
                q.push(possible.back());
                ans.push_back({currV, possible.back()});
                added[possible.back()] = true;
                possible.pop_back();
            }
            continue;
        }
        
        while(aCnt > 0)
        {
            l = 0, r = possible.size() - 1; //szukamy wszystkie a
            while(l < r)
            {
                int m = (l + r) / 2;
                vector<int> prefix;
                for(int i = l; i <= m; i++)
                    prefix.push_back(possible[i]);
                int prefSum = ask(currV, prefix);
                if(prefSum == b * prefix.size()) //same b
                    l = m + 1;
                else
                    r = m;
            }
            //l to a wiec laczymy
            q.push(possible[l]);
            ans.push_back({currV, possible[l]});
            added[possible[l]] = true;
            vector<int> newPossible;
            for(int j = l + 1; j < possible.size(); j++)    
                newPossible.push_back(possible[j]);
            possible = newPossible;
            aCnt--;
        }
    }
    cout << "! " << n - 1 << endl;
    for(pii y : ans)
        cout << y.f + 1 << ' ' << y.s + 1 << endl;
    return 0;
}