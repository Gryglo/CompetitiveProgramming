#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100001;
vector<int> numerki(MAXN, 0);
int n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        numerki[a]++;
    }

    for(int i = 0; i < MAXN; i++)
    {
        while(numerki[i] > 0)
        {
            numerki[i]--;
            cout << i << " ";
        }
    }
    return 0;
}
