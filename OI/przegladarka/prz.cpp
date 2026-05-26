#include <bits/stdc++.h>
using namespace std;

int n;
struct TrieNode
{
    char c = '0';
    int next[26];
    int depth = 0;
    int parent = 0;
    //          depth u
    vector<pair<int, int>> childsDepths;
    bool wordEnd = false;
    TrieNode()
    {
        for(int i = 0; i < 26; i++)
            next[i] = -1;
    }
};

vector<TrieNode> trie;
void trie_add(const string& word)
{
    int v = 0;
    for(int i = 0; i < word.size(); i++)
    {
        char c = word[i];
        if(trie[v].next[c - 'a'] == -1)
        {
            trie.push_back(TrieNode());
            trie[v].next[c - 'a'] = trie.size() - 1;
            trie[trie.size() - 1].c = c;
            trie[trie.size() - 1].parent = v;
            trie[trie.size() - 1].depth = trie[v].depth + 1;
        }
        v = trie[v].next[c - 'a'];
    }
    trie[v].wordEnd = true;
}

int max_depth_DFS(int v)
{
    for(int u = 0; u < 26; u++)
    {
        if(trie[v].next[u] == -1)
            continue;
        trie[v].childsDepths.push_back({ max_depth_DFS(trie[v].next[u]), trie[v].next[u] });
    }
    if(trie[v].childsDepths.size() == 0)
        return trie[v].depth;
    else if(trie[v].childsDepths.size() > 1)
    {
        sort(trie[v].childsDepths.begin(), trie[v].childsDepths.end());
        return trie[v].childsDepths[trie[v].childsDepths.size() - 1].first;
    }
    else
        return trie[v].childsDepths[0].first;
}

string ans;
void DFS(int v)
{
    if(v != 0)
        ans += trie[v].c;
    //+PRZYPADEK JEZELI ENTER MA DZIECI
    /*
    i tak musimy isc w dol wiec klikamy enter i TAB zawsze odrazu cn
    */
    if(trie[v].wordEnd && trie[v].childsDepths.size() > 0)
        ans += "ET";
    if(trie[v].childsDepths.size() == 1)
        DFS(trie[v].childsDepths[0].second);
    else if(trie[v].childsDepths.size() == 0 && trie[v].wordEnd)
        ans += 'E';
    else
    {
        for(int i = 0; i < trie[v].childsDepths.size(); i++)
        {
            int u = trie[v].childsDepths[i].second;
            DFS(u);
    
            //musimy wracac
            //dojscie na nowo od roota literkami po enterze ostatnim  lub od entera przy uzyciu TAB
 
            //nie musi wracac 
            if(i == trie[v].childsDepths.size() - 1)
                continue;
            if(trie[v].depth < trie[v].childsDepths[i].first - trie[v].depth + 1)
            {
                //RECOVER WORD
                string recoverPath;
                int x = v;
                while(x != 0)
                {
                    recoverPath = trie[x].c + recoverPath;
                    x = trie[x].parent;
                }
                ans += recoverPath;
            }
            else
            {
                ans += 'T';
                for(int x = 0; x < trie[v].childsDepths[i].first - trie[v].depth; x++)
                    ans += 'B';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    trie.push_back(TrieNode());
    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        trie_add(input);
    }
    max_depth_DFS(0);
    DFS(0);

    cout << ans.size();
    cout << '\n' << ans;
    return 0;
}