// 0 - 3 months:
// Amazon (8) — Google (7) — Microsoft (7) — TikTok (5) — Meta (4) — Grammarly (3) — Bloomberg (2) — Apple (2) — Flipkart (2) — Salesforce (2)

// 0 - 6 months:
// Goldman Sachs (4) — Uber (4) — LinkedIn (3) — Walmart Labs (2) — Zepto (2) — DP World (2)

// 6 months ago:
// Adobe (15) — Oracle (13) — Visa (9) — Yahoo (9) — Yandex (8) — ServiceNow (5) — Zoho (4) — Nvidia (4) — Arcesium (4) — Tinkoff (3)

// Problem_Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

//  4 5 6 7 0 1 2 3 4

// think target 5 and 4

  int search(vector<int>& nums, int target) {
     int l = 0, r = nums.size() - 1, mid = 0, ans = -1;
     
     while(l <= r){
        mid = l + (r - l) / 2;
        if(nums[mid] == target){
             ans = mid;
             return ans;
        }
        // Left sorted 
        if(nums[l] <= nums[mid]){
            if(target >= nums[l] && target < nums[mid]){
                 r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
           if(target <= nums[r] && nums[mid] < target){
              l = mid + 1;
           }
           else{
            r = mid - 1;
           }
        }    
     }
     return ans;
  }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {4,5,6,7,0,1,2};
    int target = 0;

    int ans = search(nums, target);

    cout << ans << "\n";
}