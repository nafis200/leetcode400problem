

// 0 - 3 months: Google (13) — Amazon (9) — Microsoft (7) — Meta (4)
// 0 - 6 months: Bloomberg (7) — Apple (2) — Uber (2)
// 6 months ago: Adobe (31) — Yahoo (18) — Yandex (7) — tcs (2) — Accenture (2)

// Problem_Link: https://leetcode.com/problems/remove-element/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

// int removeElement(vector<int>& nums, int val) {
//      multiset<int>st;
//      for(auto it : nums){
//          if(it != val){
//             st.insert(it);
//          }
//      }
//      int i = 0;
//      for(auto it : st){
//          nums[i] = it;
//          i++;
//      }
//      return st.size();
//  }

// time o(n) space o(1)

int removeElement(vector<int>& nums, int val) {
  int n = nums.size();
  int i = 0;
  for (i = 0; i < n; i++) {
    if (nums[i] == val) {
      break;
    }
  }
  for (int j = i + 1; j < n; j++) {
    if (nums[j] != val) {
      swap(nums[i], nums[j]);
      i++;
    }
  }
  return i;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  int ans = removeElement(nums, val);
  for (int i = 0; i < ans; i++) {
    cout << nums[i] << " ";
  }
}