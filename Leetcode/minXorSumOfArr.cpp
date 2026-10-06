#include <bits/stdc++.h>
using namespace std;
int minimumXORSum(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int INF = 1e9;
    int MASK_SIZE = (1 << n);
    vector<vector<int>> dp(n + 1, vector<int>(MASK_SIZE, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            //polaczenie i j
            for(int mask = 0; mask < MASK_SIZE; mask++)
            {
                int curr_mask = mask | (1 << (j - 1));
                if(__builtin_popcount(curr_mask) != i) continue;
                int prev_mask = curr_mask ^ (1 << (j - 1));
                dp[i][curr_mask] = min(dp[i][curr_mask], dp[i - 1][prev_mask] + (nums1[i - 1] ^ nums2[j - 1]));
            }
        }
    }
    return dp[n][MASK_SIZE - 1];
}
int32_t main()
{
    int n; cin >> n;
    vector<int> nums1(n), nums2(n);
    for(int i = 0; i < n; i++) cin >> nums1[i];
    for(int i = 0; i < n; i++) cin >> nums2[i];
    cout << minimumXORSum(nums1, nums2);
    return 0;
}