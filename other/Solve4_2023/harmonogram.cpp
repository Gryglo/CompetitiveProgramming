#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vector<vector<int>> graph(n + 1);
    vector<int> priority(n + 1);
    for(int i = 0; i < k; i++)
    {
        int a, b; 
        cin >> a >> b;

        graph[a].push_back(b);
        priority[b]++;
    }

    queue<int> q;

    for(int i = 1; i <= n; i++)
        if(priority[i] == 0)
            q.push(i);
    
    vector<int> result;
    while(!q.empty())
    {
        int currTask = q.front();
        q.pop();

        result.push_back(currTask);

        for(int neighbourTask : graph[currTask])
        {
            priority[neighbourTask]--;
            if(priority[neighbourTask] == 0)
                q.push(neighbourTask);
        }
    }

    for(int number : result)
        cout << number << " ";
    return 0;
}