// 0 - 3 months:
// Google (12) — Amazon (7) — Microsoft (6) — Bloomberg (3)

// 0 - 6 months:
// Meta (9)

// 6 months ago:
// TikTok (5) — Wix (5) — Coupang (4) — TCS (3) — Adobe (3) — Zoho (3) — Uber
// (3) — IBM (2) — Infosys (2) — Oracle (2)

// Problem_Link: https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> result;
// int n;

// void permute(vector<int>&ans,vector<int>& nums, int index){
//     if(index == n){
//         result.push_back(ans);
//         return;
//     }

//     permute(ans, nums, index + 1);
//     ans.push_back(nums[index]);
//     permute(ans, nums, index + 1);
//     ans.pop_back();
//     return;
// }

// vector<vector<int>> subsets(vector<int>& nums) {
//     n = nums.size();
//     vector<int>ans;
//     permute(ans, nums, 0);
//     return result;
// }

vector<vector<int>> result;
int n;

vector<vector<int>> subsets(vector<int>& nums) {
  n = nums.size();

  for (int i = 0; i < pow(2, n); i++) {
    vector<int> ans;
    for (int j = 0; j < 32; j++) {
      if (i >> j & 1) {
        ans.push_back(nums[j]);
      }
    }
    result.push_back(ans);
  }
  return result;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = subsets(nums);
  for (auto num : ans) {
    cout << "[";
    for (auto i : num) {
      cout << i << " ";
    }
    cout << "]";
  }
}