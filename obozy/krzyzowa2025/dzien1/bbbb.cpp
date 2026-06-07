#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
int n, m;

struct Node
{
    char curr = '0';
    char next[26];
    int l, r;
    vector<int> ids;
    Node()
    {
        for(int i = 0; i < 26; i++)
            next[i] = -1;
    }
};

int main()
{
    fastio;
    cin >> n >> m;
    vector<string> input(n);
    for(int i = 0; i < n; i++)
        cin >> input[i];
    sort(input.begin(), input.end());

    vector<Node> trie1;
    trie1.push_back(Node());
    trie1[0].l = 0, trie1[0].r = n - 1;

    for(int i = 0; i < n; i++)
    {
        int v = 0;
        for(char c : input[i])
        {
            if(trie1[v].next[c - 'A'] == -1)
            {
                Node u;
                u.curr = c;
                u.l = i, u.r = i;
                trie1[v].next[c - 'A'] = trie1.size();
                trie1.push_back(u);
                v = trie1[v].next[c - 'A'];
            }
            else
            {
                v = trie1[v].next[c - 'A'];
                trie1[v].r = i;
            }
        }
    }
    
    vector<Node> trie2;
    trie2.push_back(Node());
    for(int i = 0; i < n; i++)
        trie2[0].ids.push_back(i);
    for(int x = 0; x < n; x++)
    {
        int v = 0;
        for(int i = input[x].size() - 1; i >= 0; i--)
        {
            char c = input[x][i];
            if(trie2[v].next[c - 'A'] == -1)
            {
                Node u;
                u.curr = c;
                trie2[v].next[c - 'A'] = trie2.size();
                trie2.push_back(u);
            }
            v = trie2[v].next[c - 'A'];
            trie2[v].ids.push_back(x);
        }
    }

    while(m--)
    {
        string a, b;
        cin >> a >> b;
        int v1 = 0;
        for(char c : a)
        {
            v1 = trie1[v1].next[c - 'A'];
            if(v1 == -1)
                break;
        }
        //sprawdz
        if(v1 == -1)
        {
            cout << 0 << '\n';
            continue;
        }
        int v2 = 0;
        for(int i = b.size() - 1; i >= 0; i--)
        {
            char c = b[i];
            v2 = trie2[v2].next[c - 'A'];
            if(v2 == -1)
                break;
        }
        if(v2 == -1)
        {
            cout << 0 << '\n';
            continue;
        }

        //binsearch po trie2[v2].ids.size()
        int L, R;

        int l = 0, r = trie2[v2].ids.size() - 1;
        int x = trie1[v1].l;
        while(l < r)
        {
            int m = (l + r) / 2;
            if(trie2[v2].ids[m] >= x)
                r = m;
            else
                l = m + 1;
        }
        L = l;
        if(trie2[v2].ids[L] < x)
        {
            cout << 0 << '\n';
            continue;
        }

        l = L, r = trie2[v2].ids.size() - 1;
        x = trie1[v1].r;
        while(l < r)
        {
            int m = (l + r) / 2;
            if(r - l == 1)
            {
                if(trie2[v2].ids[r] <= x)
                    l = r;
                break;
            }
            if(trie2[v2].ids[m] <= x)
                l = m;
            else
                r = m - 1;
        }
        R = l;

        cout << R - L + 1 << '\n';
    }
    return 0;
}