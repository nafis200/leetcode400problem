// 0 - 3 months:
// Amazon (9) — Meta (2) — TikTok (2) — Nvidia (2) — Anduril (2)
// 0 - 6 months:
// Google (4) — Bloomberg (4) — Citadel (2) — Niantic (2)
// 6 months ago:
// Microsoft (22) — Apple (18) — Adobe (17) — Yahoo (12) — Uber (6) — Zoho (4) —
// Oracle (3) — Goldman Sachs (3) — J.P. Morgan (2) — IBM (2)

// problem Link:
// https://leetcode.com/problems/find-the-duplicate-number/description/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
  int slow = nums[0];
  int fast = nums[nums[0]];
  while (fast != slow) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }
  fast = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return fast;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> nums = {3, 1, 3, 4, 2};
  int ans = findDuplicate(nums);
  cout << ans << "\n";
}