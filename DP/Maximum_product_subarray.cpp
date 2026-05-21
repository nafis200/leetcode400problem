//  0 - 3 months:
// Google (8) — LinkedIn (6) — Amazon (3) — Bloomberg (3)

// 0 - 6 months:
// Microsoft (5) — Meta (3) — Goldman Sachs (3) — Salesforce (2)

// 6 months ago:
// Wayfair (14) — Apple (10) — Adobe (9) — Uber (7) — TikTok (5) — Yahoo (4) — J.P. Morgan (2) — tcs (2) — Oracle (2) — DE Shaw (2)

// Problem_Link: https://leetcode.com/problems/maximum-product-subarray/description/

#include<bits/stdc++.h>
using namespace std;

// time o(m) space o(1)

int maxProduct(vector<int>& nums) {

        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < 0) {
                swap(mx, mn);
            }

            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);

            ans = max(ans, mx);
        }

        return ans;
    }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2, 3, -2, 4};
    int ans = maxProduct(nums);
    cout << ans << "\n";
}