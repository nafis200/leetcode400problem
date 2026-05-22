// 0 - 3 months:
// Amazon (18) — Google (14) — tcs (7) — Bloomberg (5) — Meta (4) — Microsoft
// (4)

// 0 - 6 months:
// Apple (4) — Goldman Sachs (3) — Adobe (2) — Walmart Labs (2) — Cisco (2) —
// TomTom (2)

// 6 months ago:
// Yahoo (12) — Oracle (9) — Uber (9) — TikTok (7) — DoorDash (7) — Salesforce
// (6) — Infosys (4) — Media.net (4) — MakeMyTrip (4) — Flipkart (3)

// Problem_Link : https://leetcode.com/problems/jump-game/description/

#include <bits/stdc++.h>
using namespace std;

// time o(n ^ 2) space o(n)

// vector<bool>memo;
// vector<bool>vis;
// int n;

// bool dp(int i,vector<int>& nums){
//     if(i == n - 1){
//         return true;
//     }
//     if(i >= n){
//         return false;
//     }
//     if(vis[i] != false){
//         return memo[i];
//     }
//     bool ans = false;
//     for(int j = 1; j <= nums[i]; j++){
//         ans |= dp(i + j, nums);
//         if(ans == true){
//             break;
//         }
//     }
//     vis[i] = true;
//     memo[i] = ans;
//     return memo[i];
// }

// bool canJump(vector<int>& nums) {
//     n = nums.size();
//     memo.assign(n + 1,false);
//     vis.assign(n + 1,false);
//     bool ans = dp(0, nums);
//     return ans;
// }


// time o(n) space o(1)

bool canJump(vector<int>& nums) {
  int n = nums.size();
  int goal = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] + i >= goal) {
      goal = i;
    }
  }
  if(goal == 0){
    return true;
  }
  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> nums = {2, 3, 1, 0, 4};

  bool ans = canJump(nums);
  cout << ans << "\n";
}