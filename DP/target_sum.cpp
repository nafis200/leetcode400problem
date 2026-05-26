// 0 - 3 months:
// Microsoft (4) — Amazon (2)

// 0 - 6 months:
// Google (6) — Meta (2)

// 6 months ago:
// Bloomberg (10) — Pinterest (8) — Zoho (2) — Myntra (2) — Nuro (2) —
// ServiceNow (2) — Salesforce (2)

// problem_link: https://leetcode.com/problems/target-sum/description/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>memo;
int n;
int max_sum = 2001;

int dp(int i, int target, int sum, vector<int>&nums){
    if(i == n){
        if(target == sum){
            return 1;
        }
        return 0;
    }
    if(memo[i][sum + max_sum] != -1){
        return memo[i][sum + max_sum];
    }
    int ans = dp(i + 1, target, sum + nums[i], nums);
    ans += dp(i + 1, target, sum - nums[i], nums);
    return memo[i][sum + max_sum] = ans;
}

int findTargetSumWays(vector<int>& nums, int target) {
  n = nums.size();
  memo.assign(n + 1, vector<int>(5000, - 1)); 
  int ans = 0;
  ans = dp(0, target, 0, nums);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;
  int ans = findTargetSumWays(nums, target);
  cout << ans << "\n";
}