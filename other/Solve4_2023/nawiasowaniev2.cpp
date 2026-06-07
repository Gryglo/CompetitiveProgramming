#include <iostream>
#include <vector>

using namespace std;

int n, Q;
string input;
vector<pair<short/*otwarte nawiasy*/, short/*zamkniete nawiasy*/>> bracketsTree;

pair<short, short> connectBracketSequences(const pair<int, int>& left, const pair<int, int>& right)
{
    int connected = min(left.first, right.second);
    return {left.first + right.first - connected, left.second + right.second - connected};
}

void buildBracketsTree(int v, int l, int r)
{
    if(l == r)
    {
        if(input[l] == '(')
            bracketsTree[v] = {1, 0};
        else
            bracketsTree[v] = {0, 1};
    }
    else
    {
        int mid = (l + r) / 2;
        buildBracketsTree(2 * v, l, mid);
        buildBracketsTree(2 * v + 1, mid + 1, r);
        bracketsTree[v] = connectBracketSequences(bracketsTree[2 * v], bracketsTree[2 * v + 1]);
    }
}

pair<int, int> query(int v, int l, int r, int& targetL, int& targetR)
{
    if(l > targetR || r < targetL)
        return {0, 0};
    if(l >= targetL && r <= targetR)
        return bracketsTree[v];
    int mid = (l + r) / 2;
    pair<int, int> left = query(2 * v, l, mid, targetL, targetR);
    pair<int, int> right = query(2 * v + 1, mid + 1, r, targetL, targetR);
    return connectBracketSequences(left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> Q;
    //int size = N * 2.65;
    bracketsTree.resize(n * 3);
    cin >> input;

    buildBracketsTree(1, 0, n - 1);

    for(int i = 0; i < Q; i++)
    {
        int left, right;
        cin >> left >> right;
        left--;
        right--;
        pair<int, int> result = query(1, 0, n - 1, left, right);
        if(result.first == 0 && result.second == 0)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
    return 0; 
}
