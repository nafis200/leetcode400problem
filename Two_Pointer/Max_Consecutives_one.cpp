// 0 - 3 months: Amazon (4)
// 0 - 6 months: Google (7) — Meta (3) — Bloomberg (2) — Accenture (2)
// 6 months ago: Adobe (10) — Uber (4) — Yandex (4) — Apple (3) — Oracle (2) — Zoho (2)

// Problem_Link: https://leetcode.com/problems/max-consecutive-ones/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(n^2) space o(1)

// int findMaxConsecutiveOnes(vector<int>& nums) {
//        int mx = 0; 
//        int n = nums.size();
//        for(int i = 0; i < n; i++){
//           int count = 0;
//           for(int j = i; j < n; j++){
//              if(nums[j]){
//                 count++;
//              }
//              else{
//                 break;
//              }
//           }
//           mx = max(mx, count);
//        }
//        return mx;
// }

// Time complexity o(n) space o(1)

int findMaxConsecutiveOnes(vector<int>& nums) {
       int mx = 0; 
       int n = nums.size();
       int count = 0;
       for(int i = 0; i < n; i++){
          if(nums[i] == 1){
            count++;
          }
          else{
            mx = max(mx, count);
            count = 0;
          }
       }
       mx = max(mx, count);
       return mx;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 1, 0, 1, 1, 1};

    int ans = findMaxConsecutiveOnes(nums);

    cout << ans << "\n";
}