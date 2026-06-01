// 0 - 3 months: Google (3)
// 0 - 6 months: Meta (3)
// 6 months ago: Amazon (6) — Apple (5) — Microsoft (3) — Bloomberg (3) — DXC Technology (2)

// Problem_Link: https://leetcode.com/problems/sort-array-by-parity/description/

#include<bits/stdc++.h>
using namespace std;

// time o(n) space o(n)

//  vector<int> sortArrayByParity(vector<int>& nums) {
//      vector<int>ans;
//      for(auto it : nums){
//         if(it % 2 == 0){
//             ans.push_back(it);
//         }
//      }       
//      for(auto it : nums){
//         if(it % 2 == 1){
//             ans.push_back(it);
//         }
//      }
//      return ans;
//  }


// time o(n) space o(1)

vector<int> sortArrayByParity(vector<int>& nums) {
     int j = 0;
     for(int i = 0; i < (int)nums.size(); i++){
         if(nums[i] % 2 == 0){
            swap(nums[i],nums[j]);
            j++;
         }
     }
     return nums;
 }

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,3,2,4};

    vector<int>ans = sortArrayByParity(nums);

    for(auto it : ans){
        cout << it << " ";
    }
}