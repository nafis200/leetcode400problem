// 0 - 3 months: Google (2) — Meta (2) — Microsoft (2)
// 0 - 6 months: Amazon (2) — TCS (2)
// 6 months ago: Adobe (10) — Apple (6) — Uber (6) — Bloomberg (3) — Yahoo (3)

// Problem_Link: https://leetcode.com/problems/number-of-good-pairs/description/

#include<bits/stdc++.h>
using namespace std;
int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int,int>mp;
    int n = nums.size();
    int pairs = 0;
    for(int i = 0; i < n; i++){
         if(mp.find(nums[i]) != mp.end()){
             pairs += mp[nums[i]];
         }
         mp[nums[i]]++;
    }    
    return pairs;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,2,3,1,1,3};
    int ans = numIdenticalPairs(nums);
    cout << ans << "\n";
}