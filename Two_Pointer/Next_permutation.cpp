// 0 - 3 months:
// Meta (42) — Google (16) — Amazon (6) — Microsoft (3) — Bloomberg (2)

// 0 - 6 months:
// TikTok (4) — Adobe (3) — Mitsogo (3) — DoorDash (3) — Infosys (2) — Nike (2)

// 6 months ago:
// J.P. Morgan (28) — Apple (20) — Uber (17) — Yahoo (8) — Goldman Sachs (5) — Paytm (5) — DE Shaw (3) — Cisco (3) — Arcesium (3) — VMware (3)

// Problem_Link: https://leetcode.com/problems/next-permutation/description/

#include<bits/stdc++.h>
using namespace std;

// Time o(nlogn) space o(1)

// void nextPermutation(vector<int>& nums) {
//     bool ok = false;
//     while(next_permutation(nums.begin(), nums.end())){
//         ok = true;
//         break;
//     }
//     if(!ok){
//         sort(nums.begin(),nums.end());
//     }
// }

// 1 3 5 4 2
// 1 4 5 3 2 // it is not next biggest permutation

// Correct
//  1 4 2 3 5 is next biggest permutation




//  3 is pivot so next larger 3 is 4 from last

// swap 1 4 5 3 2
//  now reverse next pivot





void nextPermutation(vector<int>& nums) {
    int n = nums.size(); 
    int i = n - 2;
    while(i >= 0 && nums[i] >= nums[i + 1]){
        i--;
    }

    if(i >= 0){
        int j = n - 1;
        while(nums[j] <= nums[i]){
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 2, 3};
 
    nextPermutation(nums);

    for(auto i : nums){
        cout << i << " ";
    }

}