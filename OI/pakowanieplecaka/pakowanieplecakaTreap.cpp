#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct Node
{
    int x;
    int priority;
    int lazy = 0;
    Node* l = nullptr;
    Node* r = nullptr;
    Node(int x)
    {
        this->x = x;
        priority = rand();
    }
    Node()
    {
        priority = rand();
    }
};

void push(Node* v)
{
    if(v->lazy > 0)
    {
        v->x += v->lazy;
        if(v->r != nullptr)
            v->r->lazy += v->lazy;
        if(v->l != nullptr)
            v->l->lazy += v->lazy;
        v->lazy = 0;
    }
}

void split(Node* v, int x, Node*& l, Node*& r)
{
    if(v == nullptr)
    {
        //musimy zadbac o to by odlaczyc
        l = nullptr;
        r = nullptr;
        return;
    }
    push(v);
    if(v->x >= x)
    {
        //prawe drzewko ale nie wszystkie musza byc w prawym drzewku
        split(v->l, x, l, v->l); // tutaj dajemy taki ghost wierzcholek ale ostatnim jest v
        r = v;
    }
    else
    {
        //lewe drzewko
        split(v->r, x, v->r, r);
        l = v;
    }
}

int findLastLower(Node* v, int x)
{
    if(v->r == nullptr)
        return v->x;
    else
        return findLastLower(v->r, x);
}

Node* merge(Node* l, Node* r)
{
    if (!l || !r) return l ? l : r; //moze byc tylko jeden nullptr

    if(l->priority > r->priority)
    {
        //l root i l mniejsze wiec
        push(l);
        l->r = merge(l->r, r);
        return l;
    }
    else
    {
        //r root i r wieksze
        push(r);
        r->l = merge(l, r->l);
        return r;
    }
}

void insertNode(Node*& v, int x)
{
    Node* l;
    Node* r;
    split(v, x, l, r);
    //teraz dodajemy na całym r x
    //ale trzeba jeszcze dodac nowy element ktory jest rowny 
    //ostatni mniejszy + x, ten element jest w l
    if(r != nullptr)
        r->lazy += x;
    if(l != nullptr)
        x += findLastLower(l, x);

    v = merge(merge(l, new Node(x)), r);
}

void printTree(Node* v)
{
    if(v == nullptr)
        return;
    push(v);
    printTree(v->l);
    if(v->x != 0) cout << v->x << ' ';
    printTree(v->r);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    Node* root(0);
    for(int i = n - 1; i >= 0; i--)
        insertNode(root, a[i]);
    printTree(root);
    return 0;
}