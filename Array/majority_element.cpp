// 0 - 3 months:
// Google (27) — Amazon (16) — Microsoft (8) — Meta (6) — Bloomberg (5)

// 0 - 6 months:
// TCS (2) — Oracle (2)

// 6 months ago:
// Adobe (8) — Accenture (7) — Apple (5) — DE Shaw (5) — Zoho (4) — IBM (3) —
// Deloitte (2) — Goldman Sachs (2) — Autodesk (2) — Netflix (2)

// problem_link : https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;

// time o(nlogn) space o(n)

// int majorityElement(vector<int>& nums) {
//    map<int,int>mp;
//    for(auto it : nums){
//       mp[it]++;
//    }
//    int mx = 0;
//    int ans = 0;
//    for(auto it : mp){
//        if(it.second > mx){
//           mx = it.second;
//           ans = it.first;
//        }
//    }
//   return ans;
// }

// time o(nlogn) space o(1)

// int majorityElement(vector<int>& nums) {
//   sort(nums.begin(), nums.end());

//   int n = nums.size();
//   int start = 0, end = 0;

//   int mx = 0, ans = 0;

//   for (int i = 0; i < n;) {
//     start = i;
//     end = i;
//     while ((i < n) && nums[start] == nums[end]) {
//       i++;
//       end = i;
//     }
//     int len = end - start;
//     if (len > mx) {
//       mx = len;
//       ans = nums[start];
//     }
//   }

//   int len = end - start;
//   if (len > mx) {
//     mx = len;
//     ans = nums[start];
//   }

//   return ans;
// }

// time o(n) space o(1)

int majorityElement(vector<int>& nums) {
    int power = 0;
    int ans = 0;
    for(auto it : nums){
         if(power == 0){
            ans = it;
         }
        if(it == ans){
            power++;
        }
        else{
            power--;
        }
    }
    return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

  int ans = majorityElement(nums);

  cout << ans << "\n";
}