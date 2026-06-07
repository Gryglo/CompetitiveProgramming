#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct CharFreq {
    char c;
    int freq;
    CharFreq(char c, int freq) : c(c), freq(freq) {}
};

struct Compare {
    bool operator()(CharFreq const& cf1, CharFreq const& cf2) {
        return cf1.freq < cf2.freq;
    }
};

string najmniejszy_lex(string napis) {
    vector<int> count(26, 0);
    for (char c : napis) {
        count[c - 'a']++;
    }

    priority_queue<CharFreq, vector<CharFreq>, Compare> maxHeap;
    for (char c = 'a'; c <= 'z'; c++) {
        if (count[c - 'a'] > 0) {
            maxHeap.push(CharFreq(c, count[c - 'a']));
        }
    }

    string result = "";
    CharFreq prev('#', -1);
    while (!maxHeap.empty()) {
        CharFreq curr = maxHeap.top();
        maxHeap.pop();
        result += curr.c;

        if (prev.freq > 0) {
            maxHeap.push(prev);
        }

        curr.freq--;
        prev = curr;
    }

    if (result.length() != napis.length()) {
        return "NIE";
    } else {
        return result;
    }
}

int main() {
    string wejscie;
    cin >> wejscie;
    string wynik = najmniejszy_lex(wejscie);
    cout << wynik;
    return 0;
}
