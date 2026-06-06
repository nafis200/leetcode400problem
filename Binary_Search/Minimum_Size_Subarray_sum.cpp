// 0 - 3 months:
// Google (6) — Amazon (4) — Meta (2)

// 0 - 6 months:
// Bloomberg (3) — Microsoft (2)

// 6 months ago:
// BCG (8) — DoorDash (7) — TikTok (5) — Goldman Sachs (4) — Oracle (3) — Yandex
// (3) — TCS (2) — DE Shaw (2) — Autodesk (2) — Nvidia (2)

// Problem_Link: https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

// Time o(n) space o(1)

// int minSubArrayLen(int target, vector<int>& nums) {
//   int n = nums.size();
//   int l = 0, ans = INT_MAX, sum = 0;

//   for(int r = 0; r < n; r++){
//      sum += nums[r];
//      while(sum >= target){
//         ans = min(ans, r - l + 1);
//         sum -= nums[l];
//         l++;
//      }
//   }

//   if(ans == INT_MAX){
//     return 0;
//   }
//   return ans;
// }

// pref[r] - pref[l - 1] >= target;

// pref[r] >= target + pref[l - 1]

// Time o(nlogn) space o(n)

int minSubArrayLen(int target, vector<int>& nums) {
  int n = nums.size();
  int ans = INT_MAX;

  vector<long long> pref(n + 1, 0);

  for(int i = 1; i <= n; i++) {
    pref[i] = pref[i-1] + nums[i-1];
}

  for (int l = 0; l <= n; l++) {
    long long need = 0;
    if (l == 0) {
      need = target;
    } else {
      need = target + pref[l - 1];
    }

    auto it = lower_bound(pref.begin(), pref.end(), need);

    if(it != pref.end()){
        int r = it - pref.begin();
        ans = min(ans, r - l  + 1);
    }
  }
  if(ans == INT_MAX){
    ans = 0;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int ans = minSubArrayLen(target, nums);
  cout << ans << "\n";
}