#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> fib = {1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074,32951280099,53316291173,86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920,2504730781961,4052739537881,6557470319842,10610209857723,17167680177565,27777890035288,44945570212853,72723460248141,117669030460994,190392490709135,308061521170129,498454011879264,806515533049393,1304969544928657,2111485077978050,3416454622906707,5527939700884757,8944394323791464,14472334024676221,23416728348467685,37889062373143906,61305790721611591,99194853094755497,160500643816367088,259695496911122585,420196140727489673,679891637638612258};
int p;

int findClosest(ll& target)
{
    int l = 0; 
    int r = fib.size() - 1;

    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(target == fib[mid])
            return mid;
        if(target > fib[mid])
            l = mid + 1;
        else //target < fib[mid]
            r = mid - 1;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /* int idx = fib.size();
    cout << "{0,1";
    while(fib[idx - 2] + fib[idx - 1] < 1000000000000000000LL)
    {
        fib.push_back(fib[idx - 2] + fib[idx - 1]);
        cout << ',' << fib[idx];
        idx++;
    }
    cout << '}'; */
    cin >> p;
    while(p--)
    {
        ll k;
        cin >> k;
        
        int operations = 1;
        int closestSmallerIdx = findClosest(k);
        //cout << closestSmallerIdx << '\n';
        while(fib[closestSmallerIdx] != k)
        {
            if(closestSmallerIdx + 1 == fib.size())
                k -= fib[closestSmallerIdx];
            else if(k - fib[closestSmallerIdx] < fib[closestSmallerIdx + 1] - k)
                k -= fib[closestSmallerIdx];
            else
                k = fib[closestSmallerIdx + 1] - k;
            closestSmallerIdx = findClosest(k);
            operations++;
            //cout << closestSmallerIdx << '\n';
        }
        cout << operations << '\n';
    }
    return 0;
}