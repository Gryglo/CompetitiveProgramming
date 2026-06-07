#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> ciag;

void go(int number) 
{   
    if(ciag.size() == k) 
    {
        for(int i = 0; i < k; i++)
            cout << ciag[i] << " ";

        cout << "\n";
        return;
    }
//+ 1 - (K - ciag.size())
    for(int i = number; i <= n; i++) 
    {
        ciag.push_back(i); 
        go(i + 1);
        ciag.pop_back(); 
    }
}

int main() 
{
    cin >> n >> k;
    go(1);
    return 0;
}
