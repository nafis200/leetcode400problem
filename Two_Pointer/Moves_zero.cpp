// Meta (33) — Amazon (9) — Microsoft (7) — Google (5) — Apple (3) — TikTok (3) — Josh Technology (3) — JTG (3) — Bloomberg (2) — Cisco (2)

// Problem_Link: https://leetcode.com/problems/move-zeroes/

#include<bits/stdc++.h>
using namespace std;

// time o(n^2) space o(1)

//  void moveZeroes(vector<int>& nums) {
//     int n = nums.size();
//     for(int i = 0; i < n - 1; i++){
//         if(nums[i] == 0){
//             for(int j = i + 1; j < n; j++){
//                 if(nums[j] != 0){
//                     swap(nums[i],nums[j]);
//                     break;
//                 }
//             }
//         }
//     } 
//  }

// Time o(n) space o(1)

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    for(i = 0; i < n; i++){
        if(nums[i] == 0){
            break;
        }
    }
    for(int j = i + 1; j < n; j++){
         if(nums[j] != 0){
             swap(nums[i], nums[j]);
             i++;
         }
    }
 }


int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(auto it : nums){
        cout << it << " ";
    }

}