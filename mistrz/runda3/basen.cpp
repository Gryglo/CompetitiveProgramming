#include <bits/stdc++.h>
using namespace std;

int main()
{
    string first, second; cin >> first >> second;
    string odkrecony = "odkrecony";
    string zakrecony = "zakrecony";
    if(first == odkrecony && second == first)
        cout << "ciepla";
    else if(first == odkrecony && second == zakrecony)
        cout << "odkrec wszystko!";
    else if(first == zakrecony && second == odkrecony)
        cout << "zimna";
    else
        cout << "odkrec wszystko!";
    return 0;
}