// 0 - 3 months:
// Bloomberg (11) — Amazon (9) — Google (8) — TikTok (3) — Uber (3) — Meta (2) — Microsoft (2) — Oracle (2)

// 0 - 6 months:
// Zepto (3) — IBM (2) — Infosys (2) — EPAM Systems (2) — Cisco (2) — Lyft (2)

// 6 months ago:
// Adobe (30) — Apple (20) — Yahoo (12) — Turing (4) — tcs (3) — ByteDance (3) — Walmart Labs (3) — Zoho (3) — DE Shaw (3) — Yandex (2)

// Problem_Link: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(n)

// int longestConsecutive(vector<int>& nums) {
//    if(nums.empty()){
//     return 0;
//    }
//    int ans = 1;
//    int count = 1;
//    int n = nums.size();
//    sort(nums.begin(), nums.end());
//    for(int i = 1; i < n; i++){
//     if(nums[i] == nums[i - 1]){
//         continue;
//     }
//      if(nums[i] - 1 == nums[i - 1]){
//          count++;
//      }
//      else{
//         count = 1;
//      }
//      ans = max(ans, count);
//    }        
//    return ans;
// }

int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    unordered_set<int>st(nums.begin(), nums.end());
    for(auto num : nums){
        if(st.count(num - 1)){
            continue;
        }
        int len = 1;
        int cur = num;
        while(st.count(cur + 1)){
            cur++;
            len++;
        }
        ans = max(ans, len);
    }
    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {100,4,200,1,3,2};

    int ans = longestConsecutive(nums);
    cout << ans << "\n";
}