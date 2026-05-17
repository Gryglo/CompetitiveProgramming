#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int, int>;

const int MAXN = 40;

int n;
int mid;
int code;
vector<int> decode;

string mask_to_string(int mask, int len)
{
    string res = "";
    while(len--)
    {
        if(mask % 2 == 1)
            res += '1';
        else
            res += '0';
        mask /= 2;
    }
    return res;
}

vector<pii> compute_sums(int bit_c, bool left)
{
    int max_mask = 1 << bit_c;
    int offset = (left) ? 0 : (mid);
    vector<pii> res;
    for(int mask = 0; mask < max_mask; mask++)
    {
        int sum = 0;
        int t_mask = mask;
        int num_i = offset;
        while(t_mask > 0)
        {
            if(t_mask % 2 == 1)
                sum += decode[num_i];
            num_i++;
            t_mask /= 2;
        }
        res.push_back({sum, mask});
    }
    return res;
}

void init()
{
    mid = n/2;
    decode.resize(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    init();
    for(int i = 0; i < n; i++)
        cin >> decode[i];
    cin >> code;

    vector<pii> l_sums = compute_sums(mid, true); // (sum, mask)
    vector<pii> r_sums = compute_sums(n - mid, false); // (sum, mask)

    sort(l_sums.begin(), l_sums.end());
    sort(r_sums.begin(), r_sums.end());    

    int l = 0;
    int r = r_sums.size() - 1;

    while(l < l_sums.size() && r > 0)
    {
        if(l_sums[l].f + r_sums[r].f == code)
        {
            cout << mask_to_string(l_sums[l].s, mid) << mask_to_string(r_sums[r].s, n - mid);
            return 0;
        }
        else if(l_sums[l].f + r_sums[r].f > code)
            r--;
        else
            l++;
    }
    cout << "BRAK";
    return 0;
}