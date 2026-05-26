#include <bits/stdc++.h>
using namespace std;

int n, m;

int min_down = INT_MAX;
int min_down_idx = -1;

int min2_down = INT_MAX;
int min2_down_idx = -1;
int max_up = 0;
//          size, top num, idx wiezy
vector<pair<int, pair<int, int>>> stacks;
//      idx wiezy
vector<int> numIdx(1000000 + 5);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /* 
        jak chcemy sciezke ruchow napisac to musimy wiedziec gdzie jest kazdy element w jakiej wiezy
    */
    cin >> n >> m;
    int emptyPlaceIdx = -1;
    int sortedIdx = -1;
    int sortedSize = -1;
    for(int i = 0; i < m; i++)
    {
        int a; 
        cin >> a;
        if(a == 0)
        {
            emptyPlaceIdx = i;
            continue;
        }
        int prev = 0;
        bool currSorted = true;
        int top = 0;
        for(int j = 0; j < a; j++)
        {
            int x; 
            cin >> x;
            numIdx[x] = i;
            if(j == 0)
            {   
                top = x;
                max_up = max(max_up, x);
            }
            if(j == a - 1)
            {   
                if(x < min_down)
                {
                    min2_down = min_down;
                    min2_down_idx = min_down_idx;
                    min_down = x;
                    min_down_idx = i;
                }
            }
            if(x != prev + 1)
                currSorted = false;
            prev = x;
        }
        if(currSorted)
        {
            sortedIdx = i;
            sortedSize = a;
        }
        stacks.push_back({ a, { top, i } });
    }

    if(sortedIdx != -1)
    {
        cout << n - sortedSize << '\n';
        /* 
            kazdy po kolei element na ta wieze i zaczynamy od sortedSize + 1
        */
        for(int i = sortedSize + 1; i <= n; i++)
            cout << numIdx[i] + 1 << " " << sortedIdx + 1 << '\n';
        return 0;
    }

    if(emptyPlaceIdx != -1)
    {
        cout << n << '\n'; 
        /* 
            kazdy element po prostu po kolei na ten idx
        */
        for(int i = 1; i <= n; i++)
            cout << numIdx[i] + 1 << " " << emptyPlaceIdx + 1 << '\n';
        return 0;
    }

    if(max_up <= min_down)
    {
        cout << -1 << '\n';
        return 0;
    }
    sort(stacks.begin(), stacks.end());

    for(int i = 0; i < stacks.size(); i++)
    {
        /* 
         !!! co jezeli min_down to ten sam idx!

         wiec potrzebne sa 2 min


         jednak to sie nigdy nie wydarzy bo niemozliwe by top byl wiekszy od dolu bo jest posortowane zawsze
        */
        int target_min_stack = min_down;
        int target_min_stack_idx = min_down_idx;
        if(stacks[i].second.first > target_min_stack)
        {
            cout << n + stacks[i].first << '\n';
            /* 
                stacks[i].first razy ruch na inna wieze gdzies gdzie jest ten min_down
                a potem wszystko wrzucamy na ten idx i jak bedzie sytuacja ze kolejna
                liczba jest juz na tym indeksie to oznacza to ze to ona byla przerzucona
                przy czyszczeniu stosu wiec wtedy przenosimy ja ze stosu na ktory zostala 
                przeniesiona
            */
            for(int j = 0; j < stacks[i].first; j++)
                cout << stacks[i].second.second + 1 << " " << target_min_stack_idx + 1 << '\n';
            
            for(int j = 1; j <= n; j++)
            {
                if(numIdx[j] == stacks[i].second.second)
                    cout << target_min_stack_idx + 1 << " " << stacks[i].second.second + 1 << '\n';
                else
                    cout << numIdx[j] + 1 << " " << stacks[i].second.second + 1 << '\n';
            }
            return 0;
        }
    }
    return 0;
}