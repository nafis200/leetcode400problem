// ### 0 – 3 Months

// * Meta ×5
// * Amazon ×5
// * Google ×4
// * Bloomberg ×2

// ### 0 – 6 Months

// * Microsoft ×3
// * Citigroup ×2

// ### 6 Months Ago

// * BCG ×8
// * DoorDash ×7
// * TikTok ×6
// * Goldman Sachs ×4
// * Oracle ×3
// * TCS ×2
// * DE Shaw ×2
// * Autodesk ×2
// * Nvidia ×2
// * Yandex ×2

// Problem_Link:
// https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Time o(n) space o(1)

int minSubArrayLen(int target, vector<int>& nums) {
  nums.push_back(0);
  int l = 0, r = 0;
  int ans = INT_MAX, sum = 0;
  for (r = 0; r < nums.size(); r++) {
    sum += nums[r];
    if (sum >= target) {
      ans = min(ans, r - l + 1);
    }
    while (sum >= target) {
      if (sum >= target) {
        ans = min(ans, r - l + 1);
      }
      sum -= nums[l];
      l++;
    }
    }
  if (ans == INT_MAX) {
    ans = 0;
  }
  return ans;
}

// Time o(nlogn) space o(1)
//  2 5 6 8 12 15
// pref[r] - pref[l - 1] >= target
// pref[r] >= target + pref[l - 1] 

class Solution {
public:
   int minSubArrayLen(int target, vector<int>& nums) {
  int n = nums.size();
  int ans = INT_MAX;

  vector<long long> pref(n + 1, 0);

  for(int i = 1; i <= n; i++) {
    pref[i] = pref[i-1] + nums[i-1];
}

  for (int l = 0; l < n; l++) {
    long long need = pref[l] + target;
    auto it = lower_bound(pref.begin(), pref.end(), need);
    if(it != pref.end()){
        int r = it - pref.begin();
        ans = min(ans, r - l);
    }
  }
  if(ans == INT_MAX){
    ans = 0;
  }
  return ans;
}
};



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int ans = minSubArrayLen(target, nums);
  cout << ans << "\n";
}