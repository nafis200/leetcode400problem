// 0 - 3 months:
// Google (12) — Microsoft (6) — Amazon (6) — Meta (3) — Bloomberg (3) — TCS (2)

// 0 - 6 months:
// Oracle (4)

// 6 months ago:
// Adobe (3) — Apple (3) — Coupang (3) — Flipkart (2) — Goldman Sachs (2) — Zoho (2) — Snowflake (2) — Cognizant (2) — Blinkit (2) — Zomato (2)

#include<bits/stdc++.h>
using namespace std;


// Time o(n) space o(1)

// int singleNonDuplicate(vector<int>& nums) {
//     int ans = 0;
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         ans = ans ^ nums[i];
//     }
//     return ans;
// }


// Time o(logn)

int singleNonDuplicate(vector<int>& nums) {
 
    int l = 0, r = nums.size() - 1;

    while (l < r)
    {
       int mid = l + (r - l) / 2;
       if(nums[mid] == nums[mid ^ 1]){
          l = mid + 1;
       }
       else{
         r = mid;
       }
    }
    return nums[l];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    int ans = singleNonDuplicate(nums);

    cout << ans << "\n";
}