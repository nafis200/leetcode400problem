// Google (23) — Amazon (17) — Cisco (6) — Meta (5) — Microsoft (5) — Bloomberg (5) — LinkedIn (5) — Apple (3) — Oracle (2) — TikTok (2)


// Problem_Link: https://leetcode.com/problems/maximum-subarray/description/

#include<bits/stdc++.h>
using namespace std;

// time o(n ^ 2) space o(1)

// int maxSubArray(vector<int>& nums) {
//    int ans = nums[0], mx = 0;
//    int n = nums.size();
//    for(int i = 0; i < n; i++){
//      int sum = 0;
//       for(int j = i; j < n ; j++){
//           sum += nums[j];
//           ans = max(ans, sum);
//       }
//    }    
//    return ans;    
// }



// time o(n) space o(n)

int maxSubArray(vector<int>& nums) {
    vector<int>dp(nums.size(), 0);
    int n = nums.size();
    dp[0] = nums[0];
    int ans = dp[0];
    
    for(int i = 1; i < n; i++){
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        ans = max(ans,dp[i]);
    }
  
    return ans;
}


// time o(n) space o(1)

// int maxSubArray(vector<int>& nums) {
//    int ans = nums[0], mx = 0;
//    int n = nums.size();
//    int sum = 0;
//    for(int i = 0; i < n; i++){
//        sum += nums[i];
//        ans = max(ans, sum);
//        if(sum < 0){
//           sum = 0;
//        }
//    }    
//    return ans;    
// }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = maxSubArray(nums);
    cout << ans << "\n";

}