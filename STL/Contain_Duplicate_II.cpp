// 0 - 3 months:
// Google (7) — Amazon (6) — Meta (5) — Bloomberg (5) — Microsoft (2)

// 0 - 6 months:
// Zoho (2)

// 6 months ago:
// TCS (5) — Netflix (5) — Arista Networks (4) — Airbnb (4) — Palantir Technologies (3) — Apple (2) — Accenture (2)

// Problem_Link: https://leetcode.com/problems/contains-duplicate-ii/

#include<bits/stdc++.h>
using namespace std;
// bool containsNearbyDuplicate(vector<int>& nums, int k) {
//     int n = nums.size();
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             if(nums[i] == nums[j] && abs(j - i) <= k){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// Time o(n) space o(n)

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int>mp;
    for(int i = 0; i < n; i++){
        if(mp.count(nums[i])){
            if(abs(i - mp[nums[i]]) <= k){
                return true;
            }
        }
        mp[nums[i]] = i;
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {1, 0, 1, 1};
    int k = 1;
    bool ans = containsNearbyDuplicate(nums, k);
    cout << ans << "\n";
}