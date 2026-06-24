// 0 - 3 months:
// Amazon (11) — Google (8) — LinkedIn (5) — Meta (3) — Bloomberg (2)

// 0 - 6 months:
// IBM (4) — Yandex (3) — Citadel (2) — Motive (2)

// 6 months ago:
// Microsoft (29) — TikTok (5) — Goldman Sachs (5) — Salesforce (3) — Adobe (2)
// — Apple (2) — Oracle (2) — Sigmoid (2) — Roku (2) — Expedia (2)

// Problem_Link:
// https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int diff = 0;
    int ans = 0;
    for(int r = 0; r < (int)nums.size(); r++){
         if(nums[r] == 0){
            diff++;
         }
         while(diff > k){
             if(nums[l] == 0){
                diff--;
             }
             l++;
         }
         int len = r - l + 1;
         ans = max(ans, len);
    }
    return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  int ans = longestOnes(nums, k);
  cout << ans << "\n";
}