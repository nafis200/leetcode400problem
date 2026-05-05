
// 0 - 3 months:
// Google (6) — Amazon (5) — Apple (5) — Bloomberg (4)

// 0 - 6 months:
// Microsoft (8) — Accenture (4) — Meta (3) — tcs (2) — Oracle (2)

// 6 months ago:
// Adobe (17) — Uber (15) — Yahoo (12) — Zoho (8) — Walmart Labs (5) — Goldman
// Sachs (4) — Infosys (3) — TikTok (3) — J.P. Morgan (2) — IBM (2)

// problem Link: https://leetcode.com/problems/rotate-array/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

// void rotate(vector<int>& nums, int k) {
//   vector<int> ans;
//   int size = nums.size();
//   k = k % size;
//   for (int i = size - k; i < size; i++) {
//     ans.push_back(nums[i]);
//   }

//   for (int i = 0; i < size - k; i++) {
//     ans.push_back(nums[i]);
//   }
//   nums = ans;
// }

// space o (1)

void rotate(vector<int>& nums, int k) {
   int size = nums.size();
   k = k % size;
   reverse(nums.begin(),nums.end());
   reverse(nums.begin(), nums.begin() + k);
   reverse(nums.begin() + k, nums.end());
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  rotate(nums, k);

  for (auto it : nums) {
    cout << it << " ";
  }
}