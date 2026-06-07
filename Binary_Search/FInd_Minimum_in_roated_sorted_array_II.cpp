

// 0 - 6 months:
// Google (2)

// 6 months ago:
// Microsoft (3) — Amazon (3)

//  1 0 1 1 1

#include<bits/stdc++.h>
using namespace std;

// time o(logn) space o(1)
// Worst case o(n)

 int findMin(vector<int>& nums) {
    int l = 0, r = (int)nums.size() - 1;

    int mid = 0;
    while(l < r){
        mid = l + (r - l) / 2;
        if(nums[mid] == nums[r]){
            r--;
        }
        else if(nums[mid] > nums[r]){
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
    vector<int>nums = {2, 2 ,2, 0, 1};
    
    int ans = findMin(nums);
    cout << ans << "\n";
}