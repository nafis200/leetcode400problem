// 0 - 3 months:
// Google (9) — Amazon (5) — Meta (4) — Microsoft (2)

// 0 - 6 months:
// LinkedIn (4) — Bloomberg (3) — Goldman Sachs (2)

// 6 months ago:
// TikTok (7) — Apple (6) — Oracle (4) — Booking.com (4) — J.P. Morgan (2) — Adobe (2) — Epic Systems (2) — Uber (2) — Cisco (2) — Arista Networks (2)

// Problem_Link: https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>freq;
vector<vector<int>>result;

void permutation(vector<int>& ans, vector<int>& nums){
    if(ans.size() == n){
        result.push_back(ans);
        return;
    }
    for(int i = 0; i < n; i++){
        if(freq[i] == 0){
            ans.push_back(nums[i]);
            freq[i] = 1;
            permutation(ans, nums);
            ans.pop_back();
            freq[i] = 0;
        }
    }
}

 vector<vector<int>> permute(vector<int>& nums) {
      n = nums.size();
      freq.assign(n, 0);
      vector<int>ans;
      permutation(ans, nums);
      return result;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);

    for(auto num : ans){
        cout << "[";
        for(auto i : num){
            cout << i << " ";
        }
        cout << "]";
    }
}