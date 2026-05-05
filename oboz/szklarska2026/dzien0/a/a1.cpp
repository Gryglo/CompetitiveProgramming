#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;
using ll = long long;
int n, d;
vector<ll> ciag;

ll ans = 0;
vector<ll> mem(5000, -1); //1 << (13 - 1)~5000

ll brute(ll mask)
{
    if(mem[mask] != -1)
    {
        return mem[mask];
    }
    int cntBits = 0;
    ll sum = 0;
    vector<int> bitsPos;
    int cntDiv = 0;
    ll maskCopy2 = mask;
    while(maskCopy2 > 0)
    {
        if(maskCopy2 % 2 == 1)
        {
            cntBits++;
            sum += ciag[cntDiv];
            bitsPos.push_back(cntDiv);
        }
        maskCopy2 /= 2;
        cntDiv++;
    }
    if(cntBits == 1)
    {
        mem[mask] = 0;
        return 0;
    }

    ll minRes = 1000000000;
    for(ll currMask = 1; currMask < ((1 << cntBits) - 1); currMask++)
    {
        ll leftSum = sum, rightSum = 0;
        ll leftMask = mask;
        ll rightMask = 0;
        //1 << bitsPos[]
        ll maskCopy = currMask;
        cntDiv = 0;
        for(int pos : bitsPos)
        {
            if(maskCopy % 2 == 0)
            {
                leftMask = leftMask ^ (1 << pos); // na tym pos jest 1
                rightMask = rightMask | (1 << pos);
                rightSum += ciag[pos];
                leftSum -= ciag[pos];
            }
            maskCopy /= 2;
        }

        ll currRes = brute(leftMask) + brute(rightMask) + sum;
        minRes = min(minRes, currRes);
    }
    mem[mask] = minRes;
    return minRes;
}

ll subtask3func(int x)
{
    if(x <= 1)
        return 0;
    if(mem[x] != -1)
        return mem[x];
    int h1 = x / 2;
    int h2 = x - h1;
    ll curr = ciag[0] * x + subtask3func(h1) + subtask3func(h2);
    mem[x] = curr;
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> n;
    ciag.resize(n);
    int prev = 0;
    bool subtask3 = true;
    for(int i = 0; i < n; i++)
    {
        cin >> ciag[i];
        if(i > 0)
        if(ciag[i] != prev)
        subtask3 = false;
        prev = ciag[i];
    } 
    if(subtask3)
    {
        mem.resize(n + 1, -1);
        cout << subtask3func(n);
        return 0;
    }
    ll fullMask = (1 << n) - 1;
    cout << brute(fullMask);
    return 0;
}