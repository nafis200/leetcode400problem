// Google (10) — Meta (3) — Amazon (3) — Bloomberg (3) — Microsoft (2)

// Problem_Link: https://leetcode.com/problems/search-insert-position/description/

#include<bits/stdc++.h>
using namespace std;

// int searchInsert(vector<int>& nums, int target) {
//     int index = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
//     return index;
// }

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    
    int ans = -1, mid = 0;

    while(l <= r){
        mid = (l + r) / 2;
        if(nums[mid] >= target){
           ans = mid;
           r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(ans == -1){
        ans = nums.size();
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1,3,5,6};
    int target = 5;
    
    int ans = searchInsert(nums,target);

    cout << ans << "\n";
}