#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;


//pokrywa caly ciag
//           L    R
vector<pair<pair<int, int>, int>> ciag;

int binarySearch(int target)
{
    int l = 0;
    int r = n - 1;
    while(l < r)
    {
        int mid = l + (r - l) / 2;

        pair<pair<int, int>, int> midElem = ciag[mid];
        if(target < midElem.first.first)
            r = mid - 1;
        else if(target > midElem.first.second)
            l = mid + 1;
        else if(target >= midElem.first.first && target <= midElem.first.second)
            return mid;
    }
    return l;
}

int32_t main()
{
    cin >> n >> q;
    ciag.resize(n);
    int currIdx = 1; 
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        ciag[i] = { { currIdx, currIdx + (val - 1) }, (i & 1) ? -1 : val };
        currIdx += val;
    }
    
    /* for(int i = 0; i < n; i++)
    {
        pair<pair<int, int>, int> przedzial = ciag[i];
        cout << i + 1 << ':' << '\n';
        cout << przedzial.first.first << " "  << przedzial.first.second << " ";
        cout << "Value: " << przedzial.second << '\n';
    } */

    while(q--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        int leftIdx = binarySearch(l);
        int rightIdx = binarySearch(r);

        /* cout << "L: " << leftIdx << " R: " << rightIdx << '\n'; */

        //sytuacja gdzie l i r sa tym samy wiadrze
        if(leftIdx == rightIdx)
        {
            int sum = 0;
            if(ciag[leftIdx].second != -1)
                sum = (r + 1) - l;
            cout << sum << '\n';
            continue;
        }
        if(k == 0)
        {
            cout << '0' << '\n';
            continue;
        }
        bool sizesTrick = true;
        int currK = rightIdx - leftIdx;
        if(currK <= k)
            sizesTrick = false;

        pair<pair<int, int>, int> left = ciag[leftIdx];
        pair<pair<int, int>, int> right = ciag[rightIdx];
        int lAdd = LLONG_MAX;
        int rAdd = LLONG_MAX;
        vector<int> midSizes;

        int sum = 0; 
        if(left.second != -1)
        {
            lAdd = (left.first.second + 1) - l;
            sum += lAdd;
        }

        if(right.second != -1)
        {
            rAdd = (r + 1) - right.first.first;
            sum += rAdd;
        }
        //najpierw pomiedzy
        for(int i = ((left.second == -1) ? leftIdx + 1 : leftIdx + 2); i < rightIdx; i += 2)
        {
            int toAdd = ciag[i].second;
            if(sizesTrick)
                midSizes.push_back(toAdd);
            sum += toAdd;
        }

        if(!sizesTrick)
        {
            cout << sum << '\n';
            continue;
        }
        
        if(midSizes.size() > 0)
            sort(midSizes.begin(), midSizes.end());
        
        int toRem = (currK - k);
        int sizeIdx = 0;

        while(toRem > 0)
        {
            if(toRem == 2)
            {   
                if(lAdd < LLONG_MAX && rAdd < LLONG_MAX && sizeIdx != midSizes.size() && lAdd + rAdd < midSizes[sizeIdx])
                    sum -= (lAdd + rAdd);
                else
                    sum -= midSizes[sizeIdx];
                break;
            }
            else if(toRem == 1)
            {
                if(sizeIdx == midSizes.size())
                    sum -= min(lAdd, rAdd);
                else if(lAdd < midSizes[sizeIdx] || rAdd < midSizes[sizeIdx])
                    sum -= min(lAdd, rAdd);
                else
                    sum -= midSizes[sizeIdx];
                break;
            }
            else
            {
                sum -= midSizes[sizeIdx];
                sizeIdx++;
                toRem -= 2;
            }
        }

        cout << sum << '\n';
    }
    return 0;
}