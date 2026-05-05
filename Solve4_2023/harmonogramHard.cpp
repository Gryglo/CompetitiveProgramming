#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int n, k;


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k;

    int s, t;
    cin >> s >> t;

    vector<vector<int>> graph(n + 1);
    vector<int> priority(n + 1, 0);

    set<int> highPriority;

    highPriority.insert(s);

    for(int i = 0; i < k; i++)
    {
        int a, b; 
        cin >> a >> b;

        graph[a].push_back(b);
        priority[b]++;

        if(highPriority.find(b) != highPriority.end())
        {
            highPriority.insert(a);
        }
    }

    deque<int> q;

    bool isSAdded = false;

    for(int i = 1; i <= n; i++)
    {
        if(i == s)
            continue;

        if(priority[i] <= 0)
        {
            if(highPriority.find(i) != highPriority.end())
            {
                q.push_front(i);
                highPriority.erase(i);
            }
            else if(i != t)
                q.push_back(i);
        }
    }

    if(priority[s] <= 0)
    {
        q.push_front(s);
    }
    
    //vector<int> result;

    int countNumbers = 0;
    while(!q.empty())
    {
        int currTask = q.front();
        //cout << currTask;
        q.pop_front();

        //result.push_back(currTask);

        if(isSAdded)
            countNumbers++;

        if(currTask == s)
            isSAdded = true;

        for(int neighbourTask : graph[currTask])
        {
            priority[neighbourTask]--;
            if(priority[neighbourTask] <= 0)
            {
                if(neighbourTask == s)
                    continue;

                if(highPriority.find(neighbourTask) != highPriority.end())
                {
                    q.push_front(neighbourTask);
                    highPriority.erase(neighbourTask);
                    //cout << "Priorytet: " << neighbourTask;
                }
                else if (neighbourTask != t)
                    q.push_back(neighbourTask);
            }
        }
        if(priority[s] <= 0 && !isSAdded)
        {
            q.push_front(s);
        }
    }

    cout << countNumbers;
    /*
    for(int number : result)
        cout << number << " ";
    */
    return 0;
}