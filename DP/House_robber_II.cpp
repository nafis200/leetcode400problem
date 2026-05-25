// 0 - 3 months:
// Google (2) — Bloomberg (2)

// 0 - 6 months:
// Databricks (4) — Amazon (3) — Meta (2) — TikTok (2) — Salesforce (2)

// 6 months ago:
// Microsoft (21) — Apple (6) — LinkedIn (3) — Uber (3) — Nordstrom (3) —
// Datadog (3) — ByteDance (2) — DE Shaw (2) — Visa (2) — ServiceNow (2)

// Problem_Link: https://leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<vector<int>>> memo;

int dp(int i, int last, int first, vector<int>& nums) {
  if (i == n) {
    return 0;
  }
  if (memo[i][last][first] != -1) {
    return memo[i][last][first];
  }
  int ans = dp(i + 1, 0, first, nums);
  if (i != n - 1 && last != 1) {
    ans = max(ans, dp(i + 1, 1, first, nums) + nums[i]);
  } else {
    if (i == n - 1 && first != 1 && last != 1) {
      ans = max(ans, dp(i + 1, 1, first, nums) + nums[i]);
    }
  }
  return memo[i][last][first] = ans;
}

int rob(vector<int>& nums) {
  n = nums.size();
  memo.assign(n + 2, vector<vector<int>>(2, vector<int>(2, -1)));
  int ans = dp(1, 1, 1, nums) + nums[0];
  ans = max(ans, dp(1, 0, 0, nums));

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {2, 3, 2};
  int ans = rob(nums);
  cout << ans << "\n";
}