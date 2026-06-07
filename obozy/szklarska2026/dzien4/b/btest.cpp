#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int next[26];
    int last_seen = -1;
    int parent = -1;
    Node() {
        for (int i = 0; i < 26; ++i) next[i] = -1;
    }
};

vector<Node> trie;

void insert(const string& s, int idx) {
    int curr = 0;
    for (char c : s) {
        int bit = c - 'a';
        if (trie[curr].next[bit] == -1) {
            int next_node = trie.size();
            trie.push_back(Node());
            trie[curr].next[bit] = next_node;
            trie[next_node].parent = curr;
        }
        curr = trie[curr].next[bit];
        trie[curr].last_seen = max(trie[curr].last_seen, idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) return 0;

    trie.reserve(2000005);
    trie.push_back(Node());
    trie[0].last_seen = n;

    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        insert(s, i);
    }


    vector<int> diff(n + 2, 0);

    for (int i = 1; i < (int)trie.size(); i++) {
        int L = trie[i].last_seen;
        int P = trie[trie[i].parent].last_seen;
    
        if (L < P) {
            diff[L]++;
            if (P <= n) diff[P]--;
        }
    }
    diff[n]++;

    long long current_ans = 0;
    for (int i = 1; i <= n; ++i) {
        current_ans += diff[i];
        cout << current_ans << "\n";
    }

    return 0;
}