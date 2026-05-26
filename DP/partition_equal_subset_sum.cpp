// 0 - 3 months:
// Bloomberg (3) — Google (2) — Meta (2) — Amazon (2)

// 0 - 6 months:
// Microsoft (5)

// 6 months ago:
// TikTok (7) — Zoho (5) — TCS (4) — EPAM Systems (3) — Goldman Sachs (3) —
// LinkedIn (2) — Flipkart (2) — Walmart Labs (2) — Dream11 (2) — Visa (2)

// Problem_Link: https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;
int n;
// vector<vector<int>>memo;

// bool dp(int i, int target, vector<int>&nums){
//     if(i == n){
//         if(target == 0){
//             return true;
//         }
//         return false;
//     }
//     if(target < 0){
//         return false;
//     }
//     if(memo[i][target] != -1){
//         return memo[i][target];
//     }
//     int take = dp(i + 1, target - nums[i], nums);
//     int notTake = dp(i + 1, target, nums);
//     return memo[i][target] = take | notTake;
// }

// bool canPartition(vector<int>& nums) {
//     n = nums.size();
//     int target = 0;
//     for(auto it : nums){
//         target += it;
//     }
//     if(target % 2 == 1){
//         return false;
//     }
//     target = target / 2;
//     memo.assign(n + 1, vector<int>(target + 2, -1));
//     return dp(0, target, nums);
// }

// time o(n * target)
// space o(target)

bool canPartition(vector<int>& nums) {
  n = nums.size();
  int target = 0;
  for (auto it : nums) {
    target += it;
  }
  if (target % 2 == 1) {
    return false;
  }
  target = target / 2;
  vector<int> dp(target + 5, 0);
  dp[0] = 1;
  for (auto num : nums) {
    for (int j = target; j >= 0; j--) {
      if (j - num >= 0) {
        dp[j] = dp[j] | dp[j - num];
      }
    }
  }
  return dp[target];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 5, 11, 5};
  bool ans = canPartition(nums);
  cout << ans << "\n";
}