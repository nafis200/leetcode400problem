// 0 - 3 months:
// Cisco (10) — Microsoft (9) — Databricks (9) — Google (8) — Amazon (8) — Meta (6) — TikTok (5) — Bloomberg (3) — Oracle (2) — Uber (2)

// 0 - 6 months:
// LinkedIn (3) — PhonePe (3) — Adobe (2) — EPAM Systems (2) — Goldman Sachs (2) — DE Shaw (2) — Airbnb (2) — Accenture (2) — PayPal (2) — Agoda (2)

// 6 months ago:
// Apple (19) — Yahoo (10) — Arcesium (5) — ByteDance (4) — Walmart Labs (4) — Sigmoid (3) — Nordstrom (3) — Citadel (3) — Infosys (2) — Flipkart (2)

// Problem_Link: https://leetcode.com/problems/house-robber/description/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>memo;

int dp(vector<int>& nums, int i, int prev){
    if(i == n){
        return 0;
    }
    if(memo[i][prev] != -1){
        return memo[i][prev];
    }
    int ans = dp(nums, i + 1, 0);
    if(prev == 0){
        ans = max(ans, nums[i] + dp(nums, i + 1, 1));
    }
    return memo[i][prev] = ans;
}

int rob(vector<int>& nums) {
    n = nums.size();
    memo.assign(n, vector<int>(2, -1));

    int ans = dp(nums, 1, 0);
    ans = max(ans, nums[0] + dp(nums, 1, 1));
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2,1,1,2};
    int ans = rob(nums);
    cout << ans << " ";
}