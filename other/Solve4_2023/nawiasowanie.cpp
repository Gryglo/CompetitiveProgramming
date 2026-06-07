#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct BracketSequence
{
    int open, closed;
    BracketSequence(int open = 0, int closed = 0)
    {
        this->open = open;
        this->closed = closed;
    }
    
};

int n, Q;
string input;
vector<BracketSequence> bracketsTree;

BracketSequence connectBracketSequences(const BracketSequence& left, const BracketSequence& right)
{
    int connected = min(left.open, right.closed);
    return BracketSequence(left.open + right.open - connected, left.closed + right.closed - connected);
}

void buildBracketsTree(int v, int l, int r)
{
    if(l == r)
    {
        if(input[l] == '(')
            bracketsTree[v] = BracketSequence(1, 0);
        else
            bracketsTree[v] = BracketSequence(0, 1);
    }
    else
    {
        int mid = (l + r) / 2;
        buildBracketsTree(2 * v, l, mid);
        buildBracketsTree(2 * v + 1, mid + 1, r);
        bracketsTree[v] = connectBracketSequences(bracketsTree[2 * v], bracketsTree[2 * v + 1]);
    }
}

BracketSequence query(int v, int l, int r, int& targetL, int& targetR)
{
    if(l > targetR || r < targetL)
        return BracketSequence(0, 0);
    if(l >= targetL && r <= targetR)
        return bracketsTree[v];
    int mid = (l + r) / 2;
    BracketSequence left = query(2 * v, l, mid, targetL, targetR);
    BracketSequence right = query(2 * v + 1, mid + 1, r, targetL, targetR);
    return connectBracketSequences(left, right);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> Q;
    bracketsTree.resize(4 * n);
    cin >> input;

    buildBracketsTree(1, 0, n - 1);

    for(int i = 0; i < Q; i++)
    {
        int left, right;
        cin >> left >> right;
        left--;
        right--;
        BracketSequence result = query(1, 0, n - 1, left, right);
        if(result.open == 0 && result.closed == 0)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
    return 0; 
}
