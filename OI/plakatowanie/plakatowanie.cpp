#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    stack<int> heights;
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int width, height;
        cin >> width >> height;

        while(!heights.empty() && height < heights.top())
            heights.pop();
        if(!heights.empty() && height == heights.top())
            continue;
        result++;
        heights.push(height);
    }
    cout << result;
    return 0;
}