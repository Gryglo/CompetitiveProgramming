#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct Node
{
    int x;
    int priority;
    int lazy = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int x)
    {
        this->x = x;
        this->priority = rand();
    }
};

void push(Node* v)
{
    if(v->lazy > 0)
    {
        v->x += v->lazy;
        if(v->right != nullptr)
            v->right->lazy += v->lazy;
        if(v->left != nullptr)
            v->left->lazy += v->lazy;
        v->lazy = 0;
    }
}



Node* insertNode(Node* v, int x, int lastLower)
{
    /* 
    Drzewo BST
    prawe podrzewo zawsze wieksze od v
    lewe mniejsze rowne v
    gdy idziemy w lewo to dodajemy do v i lazy na prawo o wartosci x oczywiscie
    */
    if(v == nullptr)
        return new Node(lastLower + x);
    
    push(v);
    if(x <= v->x)
    {
        v->x += x;
        if(v->right != nullptr) v->right->lazy += x;
        v->left = insertNode(v->left, x, lastLower);
    }
    else
        v->right = insertNode(v->right, x, v->x);
    
    return v;
}

void printTree(Node* v)
{
    if(v == nullptr)
        return;
    push(v);
    printTree(v->left);
    if(v->x != 0) cout << v->x << ' ';
    printTree(v->right);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    Node* root = new Node(0);
    for(int i = n - 1; i >= 0; i--)
        insertNode(root, a[i], 0);
    printTree(root);
    return 0;
}