// 0 - 3 months:
// Google (10) — Amazon (6) — Meta (4) — Bloomberg (4) — Microsoft (2) — TikTok (2) — Agoda (2)

// 0 - 6 months:
// Adobe (3) — TomTom (3) — Cognizant (2)

// 6 months ago:
// TCS (11) — Apple (8) — Goldman Sachs (8) — DoorDash (5) — Oracle (4) — Zoho (4) — Shopee (4) — Verily (4) — Walmart Labs (3) — Nvidia (3)

// Problem_Links: https://leetcode.com/problems/jump-game/description/

#include<bits/stdc++.h>
using namespace std;
//  0 2 3
bool canJump(vector<int>& nums){
    int current = 0;
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        if(i > current){
            return false;
        }
        current = max(current, i + nums[i]);
    }
    
    return current >= n - 1;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums = {2,3,1,1,4};
    cout << canJump(nums) << "\n";
}