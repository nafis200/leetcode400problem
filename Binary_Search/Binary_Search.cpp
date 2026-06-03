// Google (8) — Meta (3) — Bloomberg (3) — Oracle (2)
// 0 - 6 months: Amazon (5)
// 6 months ago: Apple (15) — Microsoft (13) — Adobe (13) — Uber (7) — tcs (3) — Zoho (3) — Wipro (3) — Samsung (2) — Accenture (2) — Yandex (2)

// Problem_Link: https://leetcode.com/problems/binary-search/description/

#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int mid = 0, ans = -1;
    
    while(l <= r){
        mid = (l + r) / 2;
        if(nums[mid] == target){
            ans = mid;
            r = mid - 1;
        }
        else if(nums[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int target = 9;
    vector<int> nums = {-1,0,3,5,9,12};
    int ans = search(nums, target);
    cout << ans << "\n";
}