// 0 - 6 months:
// Google (4) — Bloomberg (2)

// 6 months ago:
// Meta (5) — Amazon (5) — TikTok (2) — Snap (2)

// Problem_Link: https://leetcode.com/problems/combination-sum-iv/description/

#include<bits/stdc++.h>
using namespace std;
 
vector<int>memo;

int dp(vector<int>& nums, int remain){
    if(remain == 0){
        return 1;
    }
    if(remain < 0){
        return 0;
    }
    if(memo[remain] != -1){
        return memo[remain];
    }
    int ans = 0;
    for(auto num : nums){
        ans += dp(nums, remain - num);
    }
   return memo[remain] = ans;
}

 int combinationSum4(vector<int>& nums, int target) {
    memo.assign(target + 5, -1);
    int ans = dp(nums, target);
    return ans;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3};
    int target = 4;
    int ans = combinationSum4(nums, target);
    cout << ans << "\n";
}