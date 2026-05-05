#include <bits/stdc++.h>
using namespace std;

const int MAXLOG = 22;
const int INF = INT_MAX;

int n;
vector<int> ans;
vector<int> currLcas;
struct Node
{
    int next[26];
    int lastI = -1;
    int parent = -1;
    Node() 
    {
        for (int i = 0; i < 26; ++i) 
            next[i] = -1;
    }
};

vector<Node> trie;

void insertTrie(const string& s, int x) 
{
    int v = 0;
    for (char c : s)
    {
        if (trie[v].next[c - 'a'] == -1) 
        {
            int u = trie.size();
            trie.push_back(Node());
            trie[v].next[c - 'a'] = u;
            trie[u].parent = v;
        }
        v = trie[v].next[c - 'a'];
        trie[v].lastI = max(trie[v].lastI, x);
    }
}


void setup()
{
    trie.push_back(Node());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    setup();
    trie[0].lastI = n;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        insertTrie(s, i + 1);
    } 
    vector<int> diff(n + 5, 0);
    for(int i = 1; i < (int) trie.size(); i++)
    {
        int l = trie[i].lastI;
        int r = trie[trie[i].parent].lastI;
        if(l < r)
        {
            diff[l]++;
            diff[r]--;
        }
    }
    vector<int> ans(n);
    long long currAns = 0;
    for(int i = 0; i < n - 1; i++)
    {
        currAns += diff[i + 1];
        cout << currAns << '\n';
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++)
    {
        if(trie[0].next[i] != -1) cnt++;
    }
    cout << cnt << '\n';
   /*  for(int i = 0; i < n; i++)
    {   
        cout << ans[i] << '\n';
    } */
    return 0;
}