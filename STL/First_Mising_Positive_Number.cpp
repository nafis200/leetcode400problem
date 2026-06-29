// 0 - 3 months:
// Amazon (6) — Microsoft (5) — Google (3) — Bloomberg (3) — Netflix (3)

// 0 - 6 months:
// Oracle (4) — Meta (3) — MakeMyTrip (3) — Myntra (2) — Geico (2) — Sprinklr
// (2) — Zomato (2)

// 6 months ago:
// Adobe (15) — Apple (14) — Uber (5) — Nutanix (5) — Walmart Labs (4) — Goldman
// Sachs (4) — Yahoo (4) — Morgan Stanley (3) — Celigo (3) — Flipkart (2)

// Problem_Link:
// https://leetcode.com/problems/first-missing-positive/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

int firstMissingPositive(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<int> nums1;
  set<int> st;
  for (auto i : nums) {
    if (i > 0) {
      if (st.find(i) == st.end()) {
        nums1.push_back(i);
      }
    }
    st.insert(i);
  }
  sort(nums1.begin(), nums1.end());
  int ans = -1;
  int cur = 1;
  for (int i = 0; i < nums1.size(); i++) {
    if (cur != nums1[i]) {
      ans = cur;
      break;
    }
    cur++;
  }
  ans = cur;
  return ans;
}

//  1 2 3

//  1 er index 0
//  2 er index 1
//  3 er index 2

//  2 3 1



class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
   int n = nums.size();
   for(int i = 0; i < n; i++){
     while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
        swap(nums[nums[i] - 1], nums[i]);
     }
   }

   int ans = -1;
   for(int i = 0; i < n; i++){
     if(i + 1 != nums[i]){
         ans = i + 1;
         break;
     }
   }
   if(ans == -1){
     ans = n + 1;
   }
   return ans;
}
};

//  2 3 1
//  3 2 1
//  1 2 3

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {100000, 3, 4000, 2, 15, 1, 99999};
  int ans = firstMissingPositive(nums);
  cout << ans << "\n";
}