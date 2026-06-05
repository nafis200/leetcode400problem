// 0 - 3 months:
// Amazon(2)
// 0 - 6 months
// Bloomberg (7) - Meta (2)

// 6 months ago:
// Google (27) - Microsoft (13) - tcs (3) - Walmart Labs (2)
// Uber (2) -  Cisco (2) - GlassDoor

// Problem_Link:
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

//  4 5 6 7 0 1 2 3 4

// think target 5 and 4

// if duplicate worst case o(n) otherwise o(logn)

bool search(vector<int>& nums, int target) {
  int l = 0, r = nums.size() - 1, mid = 0, ans = 0;

  while (l <= r) {
    mid = l + (r - l) / 2;
    if (nums[mid] == target) {
      ans = 1;
      return ans;
    }
    if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
      l++;
      r--;
        continue;
    }

    // Left sorted
    if (nums[l] <= nums[mid]) {
      if (target >= nums[l] && target < nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else {
      if (target <= nums[r] && nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;

  bool ans = search(nums, target);

  cout << ans << "\n";
}