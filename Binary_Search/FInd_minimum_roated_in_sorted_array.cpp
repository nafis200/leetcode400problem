// 0 - 3 months:
// Google (6) — Amazon (3)

// 0 - 6 months:
// Microsoft (9) — Meta (2) — Bloomberg (2)

// 6 months ago:
// Goldman Sachs (18) — TikTok (5) — Apple (4) — Uber (4) — IBM (3) — Yandex (3) — Infosys (2) — TCS (2) — Oracle (2) — Flipkart (2)

// Problem_Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

//  2 1
//  0

//  3 1 2
//    1

// worst case o(n) but o(logn)

//  int findMin(vector<int>& nums) {
//     int l = 0, r = nums.size() - 1;
//     int mid = 0;
//     int ans = INT_MAX;
//     while(l <= r){
//         mid = l + (r - l) / 2;
//         if(nums[mid] < nums[l] && nums[mid] < nums[r]){
//             l++;
//             r--;
//             continue;
//         }
//         if(nums[mid] >= nums[l]){
//             if(nums[l] > nums[r]){
//                 l = mid + 1;
//             }
//             else{
//                 r = mid - 1;
//             }
//         }
//         else{
//             r = mid - 1;
//         }
//     }
//    return nums[l];
//  }


// logn

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;

    while(l < r){
        int mid = l + (r - l) / 2;

        if(nums[mid] > nums[r]){
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
    vector<int>nums = {4, 5, 6, 7, 0, 1, 2};

    int ans = findMin(nums);
    cout << ans << "\n";

}